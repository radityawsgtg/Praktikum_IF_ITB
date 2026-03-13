#include<stdio.h>

int hasUpper(char password[], int n) {
    for (int i = 0; i < n; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

int hasLower(char password[], int n) {
    for (int i = 0; i < n; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int hasDigit(char password[], int n) {
    for (int i = 0; i < n; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    char password[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &password[i]);
    }
    
    if (n >= 8 && hasUpper(password, n) && hasLower(password, n) && hasDigit(password, n)) {
        printf("KUAT\n");
    } else {
        printf("LEMAH\n");
    }
    
    return 0;
}