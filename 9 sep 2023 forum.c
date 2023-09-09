#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nim[11];
    char nama[50];
    double tugas, uts, uas, nilai_akhir;
    char grade;
    char ulangi;
    puts("***************************************");
    printf("Tekan Enter untuk memulai program...\n");
    puts("***************************************");
    getchar(); // Menunggu pengguna menekan Enter

    do {
        int isNimValid = 0;
        while (!isNimValid) {
            printf("Masukkan NIM (10 digit angka): ");
            if (scanf("%10s", nim) != 1) {
                printf("Input NIM tidak valid! Masukkan 10 digit angka.\n");
                while (getchar() != '\n'); // Membersihkan buffer input
            } else {
                if (strlen(nim) != 10) {
                    printf("Input NIM tidak valid! Harus terdiri dari 10 digit angka.\n");
                } else {
                    int valid = 1;
                    for (int i = 0; nim[i]; i++) {
                        if (!isdigit(nim[i])) {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid) {
                        isNimValid = 1;
                    } else {
                        printf("Input NIM tidak valid! Harus terdiri dari 10 digit angka.\n");
                    }
                }
            }
        }

        int isNamaValid = 0;
        while (!isNamaValid) {
            printf("Masukkan Nama: ");
            if (scanf(" %[^\n]s", nama) != 1) {
            } else {
                int valid = 1;
                for (int i = 0; nama[i]; i++) {
                    if (!isalpha(nama[i]) && !isspace(nama[i])) {
                        valid = 0;
                        break;
                    }
                }
                if (valid && strlen(nama) > 0) {
                    isNamaValid = 1;
                } else {
                    printf("Input Nama tidak valid! Harus terdiri dari huruf alfabet.\n");
                }
            }
        }

        int isTugasValid = 0;
        while (!isTugasValid) {
            printf("Masukkan Nilai Tugas: ");
            if (scanf("%lf", &tugas) != 1 || tugas < 0 || tugas > 100) {
                printf("Input Nilai Tugas tidak valid! Harus berupa angka antara 0 dan 100.\n");
                while (getchar() != '\n'); // Membersihkan buffer input
            } else {
                isTugasValid = 1;
            }
        }

        int isUtsValid = 0;
        while (!isUtsValid) {
            printf("Masukkan Nilai UTS: ");
            if (scanf("%lf", &uts) != 1 || uts < 0 || uts > 100) {
                printf("Input Nilai UTS tidak valid! Harus berupa angka antara 0 dan 100.\n");
                while (getchar() != '\n'); // Membersihkan buffer input
            } else {
                isUtsValid = 1;
            }
        }

        int isUasValid = 0;
        while (!isUasValid) {
            printf("Masukkan Nilai UAS: ");
            if (scanf("%lf", &uas) != 1 || uas < 0 || uas > 100) {
                printf("Input Nilai UAS tidak valid! Harus berupa angka antara 0 dan 100.\n");
                while (getchar() != '\n'); // Membersihkan buffer input
            } else {
                isUasValid = 1;
            }
        }

        // Menghitung nilai akhir dengan bobot tertentu
        nilai_akhir = (0.4 * tugas) + (0.3 * uts) + (0.3 * uas);

        // Menentukan grade
        if (nilai_akhir >= 90) {
            grade = 'A';
        } else if (nilai_akhir >= 85) {
            grade = 'A';
            printf("Grade A-\n");
        } else if (nilai_akhir >= 80) {
            grade = 'B';
            printf("Grade B+\n");
        } else if (nilai_akhir >= 75) {
            grade = 'B';
        } else if (nilai_akhir >= 70) {
            grade = 'B';
            printf("Grade B-\n");
        } else if (nilai_akhir >= 65) {
            grade = 'C';
        } else if (nilai_akhir >= 50) {
            grade = 'D';
        } else {
            grade = 'E';
        }

        // Menampilkan hasil
        printf("\nHasil:\n");
        printf("NIM: %s\n", nim);
        printf("Nama: %s\n", nama);
        printf("Nilai Akhir: %.2lf\n", nilai_akhir);
        printf("Grade: %c\n", grade);

        printf("Apakah Anda ingin mengulang lagi? (y/n): ");
        scanf(" %c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');
    puts("***************************************");
    printf("Terima kasih! Program selesai.\n");
    puts("***************************************");
    return 0;
}
