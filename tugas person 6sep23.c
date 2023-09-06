#include <stdio.h>
#include <stdlib.h> // Digunakan untuk fungsi exit()

int main() {
    printf("Selamat datang di program mesin penghitung diskon\n");

    double totalBelanja;
    int jumlahTransaksi;
    char inputBuffer[100]; // Buffer untuk mengatasi input yang salah
    char lanjut;

    do {
        while (1) {
            // Meminta input total belanja
            printf("Masukkan total belanja: Rp. ");

            if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
                printf("Error: Gagal membaca input.\n");
                return 1; // Keluar dari program dengan kode kesalahan
            }

            if (sscanf(inputBuffer, "%lf", &totalBelanja) != 1 || totalBelanja < 0) {
                printf("Error: Input tidak valid atau total belanja tidak boleh negatif.\n");
                continue; // Ulangi loop untuk meminta input kembali
            }

            // Meminta input jumlah transaksi dalam sebulan
            printf("Masukkan jumlah transaksi dalam sebulan: ");

            if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
                printf("Error: Gagal membaca input.\n");
                return 1; // Keluar dari program dengan kode kesalahan
            }

            if (sscanf(inputBuffer, "%d", &jumlahTransaksi) != 1 || jumlahTransaksi < 0) {
                printf("Error: Input tidak valid atau jumlah transaksi tidak boleh negatif.\n");
                continue; // Ulangi loop untuk meminta input kembali
            }

            break; // Keluar dari loop jika input yang valid telah diberikan
        }

        double diskon = 0.0;

        if (totalBelanja < 200000) {
            // Jika total belanja kurang dari Rp. 200.000, tidak mendapat diskon
            diskon = 0.0;
        } else if (totalBelanja >= 200000 && totalBelanja <= 500000) {
            // Jika total belanja antara Rp. 200.000 dan Rp. 500.000, mendapat diskon 10%
            diskon = 0.10;
        } else if (totalBelanja > 1000000) {
            // Jika total belanja di atas Rp. 1.000.000, mendapat diskon 30%
            diskon = 0.30;
        } else if (totalBelanja >= 550000) {
            // Jika total belanja antara Rp. 550.000 dan Rp. 1.000.000, mendapat diskon 20%
            diskon = 0.20;
        }

        // Jika ada pembeli yang melakukan 4 transaksi dalam sebulan, tambahkan diskon 20%
        if (jumlahTransaksi >= 4) {
            diskon += 0.20;
        }

        // Hitung jumlah diskon
        double jumlahDiskon = totalBelanja * diskon;

        // Hitung harga yang harus dibayar setelah dikurangi diskon
        double hargaDibayar = totalBelanja - jumlahDiskon;

        // Tampilkan hasil
        printf("Total belanja: Rp. %.2lf\n", totalBelanja);
        printf("Diskon: Rp. %.2lf\n", jumlahDiskon);
        printf("Harga yang harus dibayar: Rp. %.2lf\n", hargaDibayar);

        // Meminta pilihan untuk melanjutkan atau tidak
        printf("Ingin menggunakan program ini lagi? (y/n): ");
        scanf(" %c", &lanjut);

        // Validasi input pilihan
        while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
            printf("Error: Input tidak valid. Masukkan 'y' atau 'n'.\n");
            printf("Ingin menggunakan program ini lagi? (y/n): ");
            scanf(" %c", &lanjut);
        }

        while ((getchar()) != '\n'); // Bersihkan buffer stdin

    } while (lanjut == 'y' || lanjut == 'Y');

    printf("Terima kasih telah menggunakan program ini.\n");

    return 0;
}
