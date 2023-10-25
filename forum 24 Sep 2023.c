#include <stdio.h>
#include <string.h>

int partition(char arr[10][20], int low, int high) {
    char pivot[20];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char temp[20];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    char temp[20];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);
    return (i + 1);
}

void quickSort(char arr[10][20], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(nama, 0, n - 1);

    printf("\nData setelah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}
