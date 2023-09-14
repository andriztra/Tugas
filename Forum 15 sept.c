#include <stdio.h>
#include <stdbool.h> // Diperlukan untuk menggunakan tipe data boolean
#include <stdlib.h> // Diperlukan untuk menggunakan fungsi atoi

// Fungsi untuk memeriksa apakah input adalah bilangan bulat
bool isInteger(char input[20]) {
    int i = 0;

    // Cek setiap karakter dalam input
    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return false; // Jika ada karakter yang bukan bilangan bulat, return false
        }
        i++;
    }

    return true; // Jika semua karakter adalah bilangan bulat, return true
}

void tampilkanMatrix(char judul[20], int matrix[4]) {
    printf("\n%s\n", judul);
    for (int i = 0; i < 4; i++) {
        printf("%d ", matrix[i]);
        if (i == 1) {
            printf("\n");
        }
    }
}

void kalikan(int matrix1[4], int matrix2[4]) {
    int matrixHasil[4];

    matrixHasil[0] = matrix1[0] * matrix2[0] + matrix1[1] * matrix2[2];
    matrixHasil[1] = matrix1[0] * matrix2[1] + matrix1[1] * matrix2[3];
    matrixHasil[2] = matrix1[2] * matrix2[0] + matrix1[3] * matrix2[2];
    matrixHasil[3] = matrix1[2] * matrix2[1] + matrix1[3] * matrix2[3];

    tampilkanMatrix("Hasil", matrixHasil);
}

int main() {
    printf("====================\n");
    printf("PROGRAM HASIL MATRIX\n");
    printf("====================\n");

    int matrix1[4];
    int matrix2[4];
    char input[20];

    printf("Matrix 1\n");
    for (int i = 0; i < 4; i++) {
        printf("Bilangan %d: ", i + 1);
        scanf("%s", input);
        
        // Memeriksa apakah input adalah bilangan bulat
        while (!isInteger(input)) {
            printf("Input tidak valid. Masukkan bilangan bulat: ");
            scanf("%s", input);
        }
        
        // Mengonversi input menjadi bilangan bulat
        matrix1[i] = atoi(input);
    }

    printf("\nMatrix 2\n");
    for (int i = 0; i < 4; i++) {
        printf("Bilangan %d: ", i + 1);
        scanf("%s", input);
        
        // Memeriksa apakah input adalah bilangan bulat
        while (!isInteger(input)) {
            printf("Input tidak valid. Masukkan bilangan bulat: ");
            scanf("%s", input);
        }
        
        // Mengonversi input menjadi bilangan bulat
        matrix2[i] = atoi(input);
    }

    tampilkanMatrix("Matrix 1", matrix1);
    tampilkanMatrix("Matrix 2", matrix2);

    kalikan(matrix1, matrix2);

    return 0;
}
