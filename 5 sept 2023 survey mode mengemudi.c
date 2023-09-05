#include <stdio.h>
#include <string.h>

int main() {
    char bahanBakar[20];
    int jarakTempuh;
    char modeMenyopir[20];
    float keiritan_konstan, keiritan_stopngo;

    printf("Masukkan jenis bahan bakar (Pertamax/Pertalite): ");
    scanf("%s", bahanBakar);

    printf("Masukkan jarak yang akan ditempuh (km): ");
    scanf("%d", &jarakTempuh);

    printf("Masukkan mode menyopir (konstan, stop&go): ");
    scanf("%s", modeMenyopir);

    // Menghitung keiritan berdasarkan jenis bahan bakar dan mode menyopir
    if (strcmp(bahanBakar, "Pertamax") == 0) {
        keiritan_konstan = 15.0;
        keiritan_stopngo = 10.0;
    } else if (strcmp(bahanBakar, "Pertalite") == 0) {
        keiritan_konstan = 12.0;
        keiritan_stopngo = 8.0;
    }

    // Permintaan input jumlah liter bensin awal
    float literBensinAwal;
    printf("Masukkan jumlah liter bensin awal: ");
    scanf("%f", &literBensinAwal);

    // Menghitung penggunaan bensin
    float penggunaanBensin_konstan, penggunaanBensin_stopngo;
    
    if (strcmp(modeMenyopir, "konstan") == 0) {
        penggunaanBensin_konstan = (float)jarakTempuh / keiritan_konstan;
        penggunaanBensin_stopngo = (float)jarakTempuh / keiritan_stopngo;
    } else if (strcmp(modeMenyopir, "stop&go") == 0) {
        penggunaanBensin_konstan = (float)jarakTempuh / keiritan_konstan;
        penggunaanBensin_stopngo = (float)jarakTempuh / keiritan_stopngo;
    }

    printf("Jumlah pengurangan bensin setelah menempuh %d km (konstan): %.2f liter\n", jarakTempuh, penggunaanBensin_konstan);
    printf("Jumlah pengurangan bensin setelah menempuh %d km (stop&go): %.2f liter\n", jarakTempuh, penggunaanBensin_stopngo);

    // Menghitung hasil akhir (jumlah liter bensin setelah perjalanan)
    float hasilAkhir_konstan = literBensinAwal - penggunaanBensin_konstan;
    float hasilAkhir_stopngo = literBensinAwal - penggunaanBensin_stopngo;

    printf("Hasil akhir (Jumlah liter bensin setelah perjalanan, konstan): %.2f liter\n", hasilAkhir_konstan);
    printf("Hasil akhir (Jumlah liter bensin setelah perjalanan, stop&go): %.2f liter\n", hasilAkhir_stopngo);

    // Menampilkan perbandingan bahan bakar dan mode menyopir
    printf("Perbandingan hasil:\n");
    printf("- Penggunaan bahan bakar (%s) dalam mode (konstan): %.2f liter\n", bahanBakar, modeMenyopir, penggunaanBensin_konstan);
    printf("- Penggunaan bahan bakar (%s) dalam mode (stop&go): %.2f liter\n", bahanBakar, modeMenyopir, penggunaanBensin_stopngo);

    // Membandingkan konsumsi bahan bakar
    if (penggunaanBensin_konstan < penggunaanBensin_stopngo) {
        printf("Dalam mode %s, %s lebih efisien konstan.\n", modeMenyopir, bahanBakar);
    } else if (penggunaanBensin_konstan > penggunaanBensin_stopngo) {
        printf("Dalam mode %s, %s lebih efisien stop&go.\n", modeMenyopir, bahanBakar);
    } else {
        printf("Dalam mode %s, kedua bahan bakar memiliki efisiensi yang sama.\n", modeMenyopir);
    }

    return 0;
}
