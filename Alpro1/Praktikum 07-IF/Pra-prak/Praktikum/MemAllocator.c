#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemAllocator.h"

void CreateListMem(ListMem *l, int capacity) {
    l->buffer = (MemBlock *)malloc(capacity * sizeof(MemBlock));
    l->capacity = capacity;
    l->nEff = 0;
}

void DealokasiListMem(ListMem *l) {
    free(l->buffer);
    l->buffer = NULL;
    l->capacity = 0;
    l->nEff = 0;
}

void ShrinkToFit(ListMem *l) {
    if (l->nEff == 0) {
        free(l->buffer);
        l->buffer = NULL;
        l->capacity = 0;
    } else {
        l->buffer = (MemBlock *)realloc(l->buffer, l->nEff * sizeof(MemBlock));
        l->capacity = l->nEff;
    }
}

void FreeMemory(ListMem *l, int address, int size) {
    if (l->nEff == l->capacity) {
        l->capacity *= 2;
        l->buffer = (MemBlock *)realloc(l->buffer, l->capacity * sizeof(MemBlock));
    }

    l->buffer[l->nEff].address = address;
    l->buffer[l->nEff].size = size;
    l->nEff++;
}

int AllocateMemory(ListMem *l, int reqSize) {
    if (reqSize <= 0) return ADDR_UNDEF;

    for (int i = 0; i < l->nEff; i++) {
        if (l->buffer[i].size >= reqSize) {
            int allocAddr = l->buffer[i].address;

            l->buffer[i].address += reqSize;
            l->buffer[i].size    -= reqSize;

            if (l->buffer[i].size == 0) {
                for (int j = i; j < l->nEff - 1; j++) {
                    l->buffer[j] = l->buffer[j + 1];
                }
                l->nEff--;
            }

            return allocAddr;
        }
    }

    return ADDR_UNDEF;
}

static void SortByAddress(ListMem *l) {
    for (int i = 0; i < l->nEff - 1; i++) {
        for (int j = 0; j < l->nEff - i - 1; j++) {
            if (l->buffer[j].address > l->buffer[j+1].address) {
                MemBlock tmp = l->buffer[j];
                l->buffer[j] = l->buffer[j+1];
                l->buffer[j+1] = tmp;
            }
        }
    }
}

void Defragment(ListMem *l) {
    if (l->nEff <= 1) {
        ShrinkToFit(l);
        return;
    }

    SortByAddress(l);

    int i = 0;
    while (i < l->nEff - 1) {
        int endOfCurrent = l->buffer[i].address + l->buffer[i].size;
        if (endOfCurrent == l->buffer[i+1].address) {
            l->buffer[i].size += l->buffer[i+1].size;
            for (int j = i + 1; j < l->nEff - 1; j++) {
                l->buffer[j] = l->buffer[j+1];
            }
            l->nEff--;
        } else {
            i++;
        }
    }

    ShrinkToFit(l);
}