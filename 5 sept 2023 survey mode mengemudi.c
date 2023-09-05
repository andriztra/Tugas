#include <stdio.h>
#include <string.h>

int main() {
    float keiritan_pertamax_konstan = 15.0; // KM per liter
    float keiritan_pertamax_stopngo = 10.0; // KM per liter
    float keiritan_pertalite_konstan = 12.0; // KM per liter
    float keiritan_pertalite_stopngo = 8.0;  // KM per liter

    float bensin_awal, jarak_tempuh;
    char mode_sopir[20], jenis_bensin[20];

    // Input bensin awal, jarak tempuh, jenis bensin, dan mode sopir
    printf("Masukkan jumlah bensin (liter): ");
    scanf("%f", &bensin_awal);
    printf("Masukkan jenis bensin (Pertamax atau Pertalite): ");
    scanf("%s", jenis_bensin);
    printf("Masukkan jarak yang akan ditempuh (km): ");
    scanf("%f", &jarak_tempuh);
    printf("Masukkan mode sopir (konstan atau stop&go): ");
    scanf("%s", mode_sopir);

    float keiritan_bahan_bakar;

    // Menentukan keiritan bahan bakar berdasarkan jenis bensin dan mode sopir
    if (strcmp(jenis_bensin, "Pertamax") == 0) {
        if (strcmp(mode_sopir, "konstan") == 0) {
            keiritan_bahan_bakar = keiritan_pertamax_konstan;
        } else if (strcmp(mode_sopir, "stop&go") == 0) {
            keiritan_bahan_bakar = keiritan_pertamax_stopngo;
        } else {
            printf("Mode sopir tidak valid.\n");
            return 1;
        }
    } else if (strcmp(jenis_bensin, "Pertalite") == 0) {
        if (strcmp(mode_sopir, "konstan") == 0) {
            keiritan_bahan_bakar = keiritan_pertalite_konstan;
        } else if (strcmp(mode_sopir, "stop&go") == 0) {
            keiritan_bahan_bakar = keiritan_pertalite_stopngo;
        } else {
            printf("Mode sopir tidak valid.\n");
            return 1;
        }
    } else {
        printf("Jenis bensin tidak valid.\n");
        return 1;
    }

    // Menghitung bensin yang digunakan
    float bensin_yang_digunakan = jarak_tempuh / keiritan_bahan_bakar;

    // Menghitung bensin akhir
    float bensin_akhir = bensin_awal - bensin_yang_digunakan;

    // Output hasil
    if (bensin_akhir >= 0) {
        printf("Bensin yang digunakan: %.2f liter\n", bensin_yang_digunakan);
        printf("Bensin akhir: %.2f liter\n", bensin_akhir);
    } else {
        printf("Bensin tidak mencukupi untuk menempuh jarak tersebut.\n");
    }

    return 0;
}
