#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"

typedef struct {
    char id[105];
    char nama[105];
    long long harga;
    long long terjual;
} Item;

int main() {
    init();

    Item items[105];
    int n = 0;
    char temp_id[105];

    FILE *f_kat = fopen("katalog.txt", "r");
    if (f_kat == NULL) return 1;

    while (fscanf(f_kat, "%s", temp_id) == 1 && strcmp(temp_id, ".") != 0) {
        strcpy(items[n].id, temp_id);
        fscanf(f_kat, "%s %lld", items[n].nama, &items[n].harga);
        items[n].terjual = 0;
        n++;
    }
    fclose(f_kat);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(items[j].id, items[j+1].id) > 0) {
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    FILE *f_trans = fopen("transaksi.txt", "r");
    if (f_trans == NULL) return 1;

    long long qty;
    while (fscanf(f_trans, "%s", temp_id) == 1 && strcmp(temp_id, ".") != 0) {
        fscanf(f_trans, "%lld", &qty);
        for (int i = 0; i < n; i++) {
            if (strcmp(items[i].id, temp_id) == 0) {
                items[i].terjual += qty;
                break;
            }
        }
    }
    fclose(f_trans);

    long long grand_total = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].terjual > 0) {
            long long revenue = items[i].terjual * items[i].harga;
            printf("%s %lld\n", items[i].nama, revenue);
            grand_total += revenue;
        }
    }
    printf("TOTAL %lld\n", grand_total);

    return 0;
}