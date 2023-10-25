#include <stdio.h>
#include <string.h>

void merge(char arr[10][20], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    char L[n1][20], R[n2][20];
    
    for (i = 0; i < n1; i++) {
        strcpy(L[i], arr[l + i]);
    }
    for (j = 0; j < n2; j++) {
        strcpy(R[j], arr[m + 1 + j]);
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }
    
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[10][20], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    char nama[10][20] = {"Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida", "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur", "Bella Christie", "Chelshe Love"};
    int n = 10;
    int i;

    printf("Data sebelum diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    mergeSort(nama, 0, n - 1);

    printf("\nData setelah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}
