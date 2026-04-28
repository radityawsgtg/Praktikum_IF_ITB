#include <stdio.h>
#include <stdlib.h>
#include"LogScanner.h"


void CreateLogScanner(LogScanner *l, int capacity) {
    l->buffer = (LogItem *) malloc(capacity * sizeof(LogItem));
    l->capacity = capacity;
    l->nEff = 0;
}
 
void DealokasiLogScanner(LogScanner *l) {
    free(l->buffer);
    l->buffer = NULL;
    l->capacity = 0;
    l->nEff = 0;
}
 
boolean IsEmpty(LogScanner l) {
    return l.nEff == 0;
}
 
boolean IsFull(LogScanner l) {
    return l.nEff == l.capacity;
}
 
void ExpandList(LogScanner *l) {
    l->capacity *= 2;
    l->buffer = (LogItem *) realloc(l->buffer, l->capacity * sizeof(LogItem));
}
 
void ShrinkToFit(LogScanner *l) {
    if (l->nEff == 0) {
        l->capacity = INITIAL_CAPACITY;
    } else {
        l->capacity = l->nEff;
    }
    l->buffer = (LogItem *) realloc(l->buffer, l->capacity * sizeof(LogItem));
}
 
void TambahLog(LogScanner *l, LogItem val) {
    if (IsFull(*l)) {
        ExpandList(l);
    }
    l->buffer[l->nEff] = val;
    l->nEff++;
}
 
void HapusLog(LogScanner *l, int idx, LogItem *val) {
    if (idx < 0 || idx >= l->nEff) {
        printf("INDEKS INVALID\n");
        return;
    }
    *val = l->buffer[idx];
    for (int i = idx; i < l->nEff - 1; i++) {
        l->buffer[i] = l->buffer[i + 1];
    }
    l->nEff--;
}
 
void FilterHighSeverity(LogScanner l, LogScanner *l_out) {
    int count = 0;
    for (int i = 0; i < l.nEff; i++) {
        if (l.buffer[i].severity == 3) {
            count++;
        }
    }
 
    int cap = (count == 0) ? INITIAL_CAPACITY : count;
    CreateLogScanner(l_out, cap);
 
    for (int i = 0; i < l.nEff; i++) {
        if (l.buffer[i].severity == 3) {
            TambahLog(l_out, l.buffer[i]);
        }
    }
}
 
void CetakStatusList(LogScanner l) {
    printf("Capacity: %d | nEff: %d\n", l.capacity, l.nEff);
    if (IsEmpty(l)) {
        printf("LIST KOSONG\n");
    } else {
        for (int i = 0; i < l.nEff; i++) {
            printf("[%d] TS: %d | Port: %d | Sev: %d\n",
                i + 1,
                l.buffer[i].timestamp,
                l.buffer[i].port,
                l.buffer[i].severity);
        }
    }
}
 