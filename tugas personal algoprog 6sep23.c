#include <stdio.h>

int main() {
    double jarakKm;
    char lanjut;

    do {
        // Memasukkan input untuk konversi
        printf("Masukkan jarak dalam kilometer: ");

        // Validasi input
        if (scanf("%lf", &jarakKm) != 1 || jarakKm < 0) {
            printf("Error: Input tidak valid atau jarak tidak boleh negatif.\n");
            while (getchar() != '\n'); // Membersihkan buffer stdin
            continue; // Lanjutkan ke iterasi berikutnya dalam loop
        }

        // Konversi jarak ke meter
        double jarakMeter = jarakKm * 1000; // 1 km = 1000 m

        // Tampilkan hasil konversi ke meter
        printf("Hasil konversi ke meter: %.2lf meter\n", jarakMeter);
        getchar(); // Menunggu penekanan Enter

        // Tampilkan instruksi untuk melanjutkan ke konversi sentimeter
        printf("Tekan Enter lagi untuk konversi ke sentimeter...");
        getchar(); // Menunggu penekanan Enter

        // Konversi jarak ke sentimeter
        double jarakCm = jarakMeter * 100; // 1 m = 100 cm

        // Tampilkan hasil konversi ke sentimeter
        printf("Hasil konversi ke sentimeter: %.2lf sentimeter\n", jarakCm);
        
        // Memasukkan input untuk pengulangan
        printf("Ingin melakukan konversi lagi? (y/n): ");
        while (scanf(" %c", &lanjut) != 1 || (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N')) {
            printf("Error: Input tidak valid. Masukkan 'y' atau 'n'.\n");
            while (getchar() != '\n'); // Membersihkan buffer stdin
            printf("Ingin melakukan konversi lagi? (y/n): ");
        }

    } while (lanjut == 'y' || lanjut == 'Y');

    printf("Terima kasih telah menggunakan program ini.\n");
    
    return 0;
}
