#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"

typedef struct {
    char kode[25];
    int count;
    long long total_severity;
} Anomali;

Anomali arr[10005];
int n_anomali = 0;

int cmp(const void *a, const void *b) {
    Anomali *A = (Anomali *)a;
    Anomali *B = (Anomali *)b;
    
    if (A->total_severity != B->total_severity) {
        return (A->total_severity > B->total_severity) ? -1 : 1;
    }
    if (A->count != B->count) {
        return (A->count > B->count) ? -1 : 1;
    }
    return strcmp(A->kode, B->kode);
}

int main() {
    init();

    FILE *fin = fopen("input_main.txt", "r");
    if (!fin) {
        fin = stdin;
    }

    int k;
    if (fscanf(fin, "%d", &k) != 1) {
        if (fin != stdin) fclose(fin);
        return 0;
    }

    int invalid_count = 0;

    for (int i = 0; i < k; i++) {
        char filename[256];
        fscanf(fin, "%s", filename);

        FILE *fp = fopen(filename, "r");
        if (!fp) {
            printf("FILE_NOT_FOUND %s\n", filename);
            continue;
        }

        char line[1024];
        while (fgets(line, sizeof(line), fp)) {
            int len = strlen(line);
            while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
                line[len - 1] = '\0';
                len--;
            }

            int valid = 1;
            char *pipe = strchr(line, '|');

            if (!pipe || pipe == line || strchr(pipe + 1, '|')) {
                valid = 0;
            } else {
                int k_len = pipe - line;
                if (k_len < 1 || k_len > 20) {
                    valid = 0;
                } else {
                    for (int j = 0; j < k_len; j++) {
                        if (!((line[j] >= 'A' && line[j] <= 'Z') || line[j] == '_')) {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (valid) {
                    char *sev_str = pipe + 1;
                    int s_len = strlen(sev_str);
                    if (s_len == 0 || s_len > 3) {
                        valid = 0;
                    } else {
                        for (int j = 0; j < s_len; j++) {
                            if (sev_str[j] < '0' || sev_str[j] > '9') {
                                valid = 0;
                                break;
                            }
                        }
                        if (valid) {
                            int sev = atoi(sev_str);
                            if (sev < 1 || sev > 100) {
                                valid = 0;
                            } else {
                                char temp_kode[25];
                                strncpy(temp_kode, line, k_len);
                                temp_kode[k_len] = '\0';

                                int found = 0;
                                for (int idx = 0; idx < n_anomali; idx++) {
                                    if (strcmp(arr[idx].kode, temp_kode) == 0) {
                                        arr[idx].count++;
                                        arr[idx].total_severity += sev;
                                        found = 1;
                                        break;
                                    }
                                }
                                if (!found) {
                                    strcpy(arr[n_anomali].kode, temp_kode);
                                    arr[n_anomali].count = 1;
                                    arr[n_anomali].total_severity = sev;
                                    n_anomali++;
                                }
                            }
                        }
                    }
                }
            }

            if (!valid) {
                invalid_count++;
            }
        }
        fclose(fp);
    }

    if (fin != stdin) {
        fclose(fin);
    }

    qsort(arr, n_anomali, sizeof(Anomali), cmp);

    for (int i = 0; i < n_anomali; i++) {
        double avg = (double)arr[i].total_severity / arr[i].count;
        printf("%s|%d|%lld|%.2f\n", arr[i].kode, arr[i].count, arr[i].total_severity, avg);
    }

    printf("INVALID %d\n", invalid_count);

    return 0;
}