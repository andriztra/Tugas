#include <stdio.h>
#include <string.h>

int main() {
    char bahanBakar[20];
    int jarakTempuh;
    char modeMenyopir[20];
    float keiritan;
    
    printf("Masukkan jenis bahan bakar (Pertamax/Pertalite): ");
    scanf("%s", bahanBakar);
    
    printf("Masukkan jarak yang akan ditempuh (km): ");
    scanf("%d", &jarakTempuh);
    
    printf("Masukkan mode menyopir (konstan/dalam kota, stop&go/luar kota): ");
    scanf("%s", modeMenyopir);
    
    // Menghitung keiritan berdasarkan jenis bahan bakar dan mode menyopir
    if (strcmp(bahanBakar, "Pertamax") == 0) {
        if (strcmp(modeMenyopir, "konstan") == 0) {
            keiritan = 15.0;
        } else if (strcmp(modeMenyopir, "stop&go") == 0) {
            keiritan = 10.0;
        }
    } else if (strcmp(bahanBakar, "Pertalite") == 0) {
        if (strcmp(modeMenyopir, "konstan") == 0) {
            keiritan = 12.0;
        } else if (strcmp(modeMenyopir, "stop&go") == 0) {
            keiritan = 8.0;
        }
    }
    
    // Menghitung penggunaan bensin
    float penggunaanBensin = (float)jarakTempuh / keiritan;
    
    printf("Jumlah pengurangan bensin setelah menempuh %d km: %.2f liter\n", jarakTempuh, penggunaanBensin);
    
    // Menampilkan perbandingan bahan bakar dan mode menyopir
    printf("Perbandingan hasil:\n");
    printf("- Penggunaan bahan bakar (%s) dalam mode %s: %.2f liter\n", bahanBakar, modeMenyopir, penggunaanBensin);
    
    // Menghitung penggunaan bahan bakar dengan jenis bahan bakar yang berbeda
    char bahanBakarLain[20];
    strcpy(bahanBakarLain, strcmp(bahanBakar, "Pertamax") == 0 ? "Pertalite" : "Pertamax");
    float keiritanLain = (strcmp(bahanBakarLain, "Pertamax") == 0) ? (strcmp(modeMenyopir, "konstan") == 0 ? 15.0 : 10.0) : (strcmp(modeMenyopir, "konstan") == 0 ? 12.0 : 8.0);
    float penggunaanBensinLain = (float)jarakTempuh / keiritanLain;
    
    printf("- Penggunaan bahan bakar (%s) dalam mode %s: %.2f liter\n", bahanBakarLain, modeMenyopir, penggunaanBensinLain);
    
    // Membandingkan konsumsi bahan bakar
    if (penggunaanBensin < penggunaanBensinLain) {
        printf("Dalam mode %s, %s lebih efisien.\n", modeMenyopir, bahanBakar);
    } else if (penggunaanBensin > penggunaanBensinLain) {
        printf("Dalam mode %s, %s lebih efisien.\n", modeMenyopir, bahanBakarLain);
    } else {
        printf("Dalam mode %s, kedua bahan bakar memiliki efisiensi yang sama.\n", modeMenyopir);
    }
    
    return 0;
}
