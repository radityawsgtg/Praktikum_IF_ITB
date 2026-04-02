#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"

typedef struct Node {
    char name[256];
    int is_dir;
    char *content;
    struct Node *parent;
    struct Node **children;
    int child_count;
    int child_capacity;
} Node;

Node *root;

char* my_strdup(const char* s) {
    if (!s) return NULL;
    char *d = (char*)malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

Node* create_node(const char *name, int is_dir, Node *parent) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->is_dir = is_dir;
    n->content = NULL;
    n->parent = parent;
    n->child_count = 0;
    n->child_capacity = 4;
    n->children = (Node**)malloc(sizeof(Node*) * n->child_capacity);
    return n;
}

void add_child(Node *parent, Node *child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (Node**)realloc(parent->children, sizeof(Node*) * parent->child_capacity);
    }
    parent->children[parent->child_count++] = child;
    child->parent = parent;
}

void remove_child(Node *parent, Node *child) {
    int idx = -1;
    for (int i = 0; i < parent->child_count; i++) {
        if (parent->children[i] == child) {
            idx = i; 
            break;
        }
    }
    if (idx != -1) {
        for (int i = idx; i < parent->child_count - 1; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->child_count--;
    }
}

void free_tree(Node *n) {
    if (!n) return;
    for (int i = 0; i < n->child_count; i++) {
        free_tree(n->children[i]);
    }
    free(n->children);
    if (n->content) free(n->content);
    free(n);
}

Node* get_node(const char *path) {
    if (strcmp(path, "/") == 0) return root;
    Node *curr = root;
    char temp[4096];
    strcpy(temp, path);
    char *tok = strtok(temp, "/");
    
    while (tok != NULL) {
        int found = 0;
        if (!curr->is_dir) return NULL;
        for (int i = 0; i < curr->child_count; i++) {
            if (strcmp(curr->children[i]->name, tok) == 0) {
                curr = curr->children[i];
                found = 1;
                break;
            }
        }
        if (!found) return NULL;
        tok = strtok(NULL, "/");
    }
    return curr;
}

Node* get_parent_and_name(const char *path, char *name_out) {
    if (strcmp(path, "/") == 0) return NULL;
    char temp[4096];
    strcpy(temp, path);
    char *last_slash = strrchr(temp, '/');
    if (!last_slash) return NULL; 
    
    strcpy(name_out, last_slash + 1);
    if (strlen(name_out) == 0) return NULL; 
    
    if (last_slash == temp) {
        return root;
    } else {
        *last_slash = '\0';
        return get_node(temp);
    }
}

int check_descendant(Node *src, Node *dest) {
    Node *curr = dest;
    while (curr != NULL) {
        if (curr == src) return 1;
        curr = curr->parent;
    }
    return 0;
}

int compare_nodes(const void *a, const void *b) {
    Node *n1 = *(Node**)a;
    Node *n2 = *(Node**)b;
    return strcmp(n1->name, n2->name);
}

int main() {
    init();

    root = create_node("/", 1, NULL);

    FILE *f_main = fopen("input_main.txt", "r");
    if (!f_main) f_main = stdin;

    char cmd_file[256];
    if (fscanf(f_main, "%s", cmd_file) == 1) {
        FILE *f_cmd = fopen(cmd_file, "r");
        if (f_cmd) {
            char line[8192];
            while (fgets(line, sizeof(line), f_cmd)) {
                line[strcspn(line, "\r\n")] = '\0';
                if (strlen(line) == 0) continue;

                char *cmd = strtok(line, " ");
                char *path1 = strtok(NULL, " ");
                char *path2 = strtok(NULL, " ");
                char *extra = strtok(NULL, " ");

                int err = 0;

                if (!cmd) continue;

                if (strcmp(cmd, "MKDIR") == 0) {
                    if (!path1 || path2 || extra) err = 1;
                    else {
                        char name[256];
                        Node *p = get_parent_and_name(path1, name);
                        if (!p || !p->is_dir) err = 1;
                        else {
                            int exists = 0;
                            for(int i = 0; i < p->child_count; i++) {
                                if (strcmp(p->children[i]->name, name) == 0) { exists = 1; break; }
                            }
                            if (exists) err = 1;
                            else {
                                Node *n = create_node(name, 1, p);
                                add_child(p, n);
                            }
                        }
                    }
                }
                else if (strcmp(cmd, "TOUCH") == 0) {
                    if (!path1 || path2 || extra) err = 1;
                    else {
                        char name[256];
                        Node *p = get_parent_and_name(path1, name);
                        if (!p || !p->is_dir) err = 1;
                        else {
                            int exists = 0;
                            for(int i = 0; i < p->child_count; i++) {
                                if (strcmp(p->children[i]->name, name) == 0) { exists = 1; break; }
                            }
                            if (exists) err = 1;
                            else {
                                Node *n = create_node(name, 0, p);
                                add_child(p, n);
                            }
                        }
                    }
                }
                else if (strcmp(cmd, "WRITE") == 0) {
                    if (!path1 || !path2 || extra) err = 1;
                    else {
                        Node *n = get_node(path1);
                        if (!n || n->is_dir) err = 1;
                        else {
                            if (n->content) free(n->content);
                            n->content = my_strdup(path2);
                        }
                    }
                }
                else if (strcmp(cmd, "MOVE") == 0) {
                    if (!path1 || !path2 || extra) err = 1;
                    else {
                        Node *s = get_node(path1);
                        if (!s || s == root) err = 1;
                        else {
                            char dname[256];
                            Node *dp = get_parent_and_name(path2, dname);
                            if (!dp || !dp->is_dir) err = 1;
                            else if (check_descendant(s, dp)) err = 1;
                            else {
                                int exists = 0;
                                for(int i = 0; i < dp->child_count; i++) {
                                    if (strcmp(dp->children[i]->name, dname) == 0) { exists = 1; break; }
                                }
                                if (exists) err = 1;
                                else {
                                    remove_child(s->parent, s);
                                    strcpy(s->name, dname);
                                    add_child(dp, s);
                                }
                            }
                        }
                    }
                }
                else if (strcmp(cmd, "DELETE") == 0) {
                    if (!path1 || path2 || extra || strcmp(path1, "/") == 0) err = 1;
                    else {
                        Node *n = get_node(path1);
                        if (!n) err = 1;
                        else {
                            remove_child(n->parent, n);
                            free_tree(n);
                        }
                    }
                }
                else if (strcmp(cmd, "CAT") == 0) {
                    if (!path1 || path2 || extra) err = 1;
                    else {
                        Node *n = get_node(path1);
                        if (!n || n->is_dir) err = 1;
                        else {
                            printf("%s\n", n->content ? n->content : "");
                        }
                    }
                }
                else if (strcmp(cmd, "LIST") == 0) {
                    if (!path1 || path2 || extra) err = 1;
                    else {
                        Node *n = get_node(path1);
                        if (!n || !n->is_dir) err = 1;
                        else {
                            if (n->child_count == 0) {
                                printf("EMPTY\n");
                            } else {
                                qsort(n->children, n->child_count, sizeof(Node*), compare_nodes);
                                for (int i = 0; i < n->child_count; i++) {
                                    printf("%s%s", n->children[i]->name, (i == n->child_count - 1) ? "" : " ");
                                }
                                printf("\n");
                            }
                        }
                    }
                }
                else {
                    err = 1;
                }

                if (err) {
                    printf("ERROR\n");
                }
            }
            fclose(f_cmd);
        }
    }

    if (f_main != stdin) fclose(f_main);

    return 0;
}