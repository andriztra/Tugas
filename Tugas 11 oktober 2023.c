#include <stdio.h>
#include <string.h>
#include <ctype.h> // Library untuk isupper dan isalpha

// Membuat typedef untuk struktur Bulan
typedef struct {
    char nama[15];
    int vokal;
    int nonvokal;
} Bulan;

int main() {
    // Inisialisasi array Bulan dengan semua entri bulan dari Januari hingga Desember
    Bulan daftarBulan[] = {
        {"Januari", 3, 5},
        {"Februari", 5, 4},
        {"Maret", 2, 3},
        {"April", 3, 2},
        {"Mei", 2, 2},
        {"Juni", 2, 2},
        {"Juli", 2, 2},
        {"Agustus", 3, 5},
        {"September", 3, 6},
        {"Oktober", 3, 5},
        {"November", 3, 6},
        {"Desember", 3, 6}
    };

    char hurufAwalan;
    char ulangi;

    do {
        printf("Masukkan huruf awalan bulan (A-Z): ");
        
        // Validasi huruf kapital dan huruf
        do {
            scanf(" %c", &hurufAwalan);
            if (!isalpha(hurufAwalan)) {
                puts("Input harus berupa huruf. Silakan coba lagi: ");
            } else if (!isupper(hurufAwalan)) {
                puts("Input harus berupa huruf kapital (A-Z). Silakan coba lagi: ");
            }
        } while (!isupper(hurufAwalan) || !isalpha(hurufAwalan));

        printf("Bulan-bulan yang sesuai dengan huruf awalan '%c':\n", hurufAwalan);
        for (int i = 0; i < sizeof(daftarBulan) / sizeof(daftarBulan[0]); i++) {
            if (daftarBulan[i].nama[0] == hurufAwalan) {
                printf("%s\n", daftarBulan[i].nama);
                printf("Jumlah karakter vokal: %d\n", daftarBulan[i].vokal);
                printf("Jumlah karakter nonvokal: %d\n", daftarBulan[i].nonvokal);
            }
        }

        printf("Apakah Anda ingin mengulang lagi (y/n)?: ");
        scanf(" %c", &ulangi);

    } while (ulangi == 'y' || ulangi == 'Y');
    puts("Terimakasih sudah menggunakan program ini");
    return 0;
} 
