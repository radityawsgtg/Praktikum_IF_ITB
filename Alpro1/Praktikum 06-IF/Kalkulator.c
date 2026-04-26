#include"boolean.h"
#include<stdio.h>
#include"Kalkulator.h"

/* Kamus Umum 
#define MAX_OPERAND 100
#define MAX_OPERATOR 99

typedef struct {
    int Operan[MAX_OPERAND]; 
    char Operator[MAX_OPERATOR];
    int Ans;
    int NEffOperan;
    int NEffOperator;
} Kalkulator;
*/

void BuatKalkulator (Kalkulator *K) {
    K->NEffOperan = 0;
    K->NEffOperator = 0;
    K->Ans = 0;
}

boolean CekError (Kalkulator K) {
    if (K.NEffOperator != K.NEffOperan - 1) return true;
    for (int i = 0; i < K.NEffOperator; i++) {
        int next = K.Operan[i+1];
        char op = K.Operator[i];
        if (op == '/' && next == 0) return true;
    }
    return false;
}

void ResetKalkulator (Kalkulator *K) {
    K->NEffOperan = 0;
    K->NEffOperator = 0;
    K->Ans = 0;
}

void InputOperasi (Kalkulator *K, int oprn[], int n_oprn, char oprtor[], int n_oprtor) {
    ResetKalkulator(K);
    K->NEffOperan = n_oprn;
    K->NEffOperator = n_oprtor;
    for (int i = 0; i < n_oprn; i++) K->Operan[i] = oprn[i];
    for (int i = 0; i < n_oprtor; i++) K->Operator[i] = oprtor[i];
}

void TambahOperator (Kalkulator *K, char oprtor) {
    if (K->NEffOperator < MAX_OPERATOR) {
        K->Operator[K->NEffOperator] = oprtor;
        K->NEffOperator++;
    }
}

void HapusOperator (Kalkulator *K) {
    if (K->NEffOperator > 0) {
        K->NEffOperator--;
    }
}

void UbahOperator (Kalkulator *K, int idx, char oprtor) {
    if (idx >= 0 && idx < K->NEffOperator) {
        K->Operator[idx] = oprtor;
    }
}

void TambahOperan (Kalkulator *K, int oprn) {
    if (K->NEffOperan < MAX_OPERAND) {
        K->Operan[K->NEffOperan] = oprn;
        K->NEffOperan++;
    }
}

void HapusOperan (Kalkulator *K) {
    if (K->NEffOperan > 0) {
        K->NEffOperan--;
    }
}

void UbahOperan (Kalkulator *K, int idx, int oprn) {
    if (idx >= 0 && idx < K->NEffOperan) {
        K->Operan[idx] = oprn;
    }
}

boolean JalankanKalkulasi (Kalkulator *K) {
    if (CekError(*K)) return false;
    int result = K->Operan[0];
    for (int i = 0; i < K->NEffOperator; i++) {
        int next = K->Operan[i+1];
        char op = K->Operator[i];
        if (op == '+') result += next;
        else if (op == '-') result -= next;
        else if (op == '*') result *= next;
        else if (op == '/') result /= next;
    }
    K->Ans = result;
    return true;
}

void CetakHasil (Kalkulator K) {
    if (K.NEffOperan == 0) {
        printf("KALKULATOR MASIH KOSONG\n");
    } else {
        for (int i = 0; i < K.NEffOperan; i++) {
            printf("%d", K.Operan[i]);
            if (i < K.NEffOperator) printf("%c", K.Operator[i]);
        }
        printf("\n");
        if (CekError(K)) {
            printf("Hasil Kalkulasi: ERROR\n");
        } else {
            int result = K.Operan[0];
            for (int i = 0; i < K.NEffOperator; i++) {
                int next = K.Operan[i+1];
                char op = K.Operator[i];
                if (op == '+') result += next;
                else if (op == '-') result -= next;
                else if (op == '*') result *= next;
                else if (op == '/') result /= next;
            }
            printf("Hasil Kalkulasi: %d\n", result);
        }
    }
}