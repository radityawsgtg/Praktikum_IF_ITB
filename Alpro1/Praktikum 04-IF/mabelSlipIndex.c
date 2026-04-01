#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"

typedef struct {
    char slip_id[105];
    long long timestamp;
    char category[25];
    int severity;
    char title[155];
} Slip;

Slip slips[10005];
int n_slips = 0;

int is_all_digits(const char *s) {
    if (!s || *s == '\0') return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

int main() {
    init();

    FILE *f_slips = fopen("slips.txt", "r");
    int invalid_count = 0;

    if (f_slips) {
        char line[1024];
        while (fgets(line, sizeof(line), f_slips)) {
            int len = strlen(line);
            while (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r')) {
                line[len-1] = '\0';
                len--;
            }

            if (strcmp(line, ".") == 0) break;

            int valid = 1;
            char *p1 = strchr(line, '|');
            char *p2 = p1 ? strchr(p1 + 1, '|') : NULL;
            char *p3 = p2 ? strchr(p2 + 1, '|') : NULL;
            char *p4 = p3 ? strchr(p3 + 1, '|') : NULL;

            if (!p1 || !p2 || !p3 || !p4 || strchr(p4 + 1, '|')) {
                invalid_count++;
                continue;
            }

            *p1 = *p2 = *p3 = *p4 = '\0';
            char *id_str = line;
            char *ts_str = p1 + 1;
            char *cat_str = p2 + 1;
            char *sev_str = p3 + 1;
            char *title_str = p4 + 1;

            if (strlen(id_str) == 0 || strlen(title_str) == 0) valid = 0;

            if (valid && !is_all_digits(ts_str)) valid = 0;
            
            long long ts = 0;
            if (valid) ts = atoll(ts_str);

            if (valid) {
                if (strcmp(cat_str, "MYSTERY") != 0 &&
                    strcmp(cat_str, "MONSTER") != 0 &&
                    strcmp(cat_str, "ARTIFACT") != 0 &&
                    strcmp(cat_str, "PORTAL") != 0) {
                    valid = 0;
                }
            }

            int sev = 0;
            if (valid) {
                if (!is_all_digits(sev_str)) valid = 0;
                else {
                    sev = atoi(sev_str);
                    if (sev < 1 || sev > 9) valid = 0;
                }
            }

            if (!valid) {
                invalid_count++;
            } else {
                int found = -1;
                for (int i = 0; i < n_slips; i++) {
                    if (strcmp(slips[i].slip_id, id_str) == 0) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    if (ts > slips[found].timestamp) {
                        slips[found].timestamp = ts;
                        strcpy(slips[found].category, cat_str);
                        slips[found].severity = sev;
                        strcpy(slips[found].title, title_str);
                    }
                } else {
                    strcpy(slips[n_slips].slip_id, id_str);
                    slips[n_slips].timestamp = ts;
                    strcpy(slips[n_slips].category, cat_str);
                    slips[n_slips].severity = sev;
                    strcpy(slips[n_slips].title, title_str);
                    n_slips++;
                }
            }
        }
        fclose(f_slips);
    }

    FILE *f_in = fopen("input_main.txt", "r");
    if (!f_in) f_in = stdin;

    int q;
    if (fscanf(f_in, "%d", &q) == 1) {
        for (int i = 0; i < q; i++) {
            char cmd[25];
            fscanf(f_in, "%s", cmd);

            if (strcmp(cmd, "COUNT") == 0) {
                char cat[25];
                fscanf(f_in, "%s", cat);
                int count = 0;
                for (int j = 0; j < n_slips; j++) {
                    if (strcmp(slips[j].category, cat) == 0) {
                        count++;
                    }
                }
                printf("%d\n", count);
            } else if (strcmp(cmd, "LATEST") == 0) {
                char cat[25];
                fscanf(f_in, "%s", cat);
                long long max_ts = -1;
                int best_idx = -1;

                for (int j = 0; j < n_slips; j++) {
                    if (strcmp(slips[j].category, cat) == 0) {
                        if (best_idx == -1) {
                            best_idx = j;
                            max_ts = slips[j].timestamp;
                        } else if (slips[j].timestamp > max_ts) {
                            max_ts = slips[j].timestamp;
                            best_idx = j;
                        } else if (slips[j].timestamp == max_ts) {
                            if (strcmp(slips[j].slip_id, slips[best_idx].slip_id) < 0) {
                                best_idx = j;
                            }
                        }
                    }
                }

                if (best_idx != -1) {
                    printf("%s|%lld|%d|%s\n", 
                        slips[best_idx].slip_id, 
                        slips[best_idx].timestamp, 
                        slips[best_idx].severity, 
                        slips[best_idx].title);
                } else {
                    printf("NONE\n");
                }
            } else if (strcmp(cmd, "RANGE") == 0) {
                long long L, R;
                fscanf(f_in, "%lld %lld", &L, &R);
                int count = 0;
                for (int j = 0; j < n_slips; j++) {
                    if (slips[j].timestamp >= L && slips[j].timestamp <= R) {
                        count++;
                    }
                }
                printf("%d\n", count);
            }
        }
    }

    if (f_in != stdin) fclose(f_in);

    printf("INVALID %d\n", invalid_count);

    return 0;
}