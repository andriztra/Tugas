#include <stdio.h>
#include <ctype.h>

int main() {
    int jumlahMahasiswa;
    int i;
    
    puts("#########################################");
    printf("Program Perhitungan Grade Mahasiswa\n");
    puts("#########################################");

    do {
        printf("Masukkan Jumlah Mahasiswa: ");
        scanf("%d", &jumlahMahasiswa);
    } while (jumlahMahasiswa < 1 || jumlahMahasiswa > 100);

    for (i = 1; i <= jumlahMahasiswa; i++) {
        printf("Mahasiswa %d\n", i);

        float nilaiQuis, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS, totalNilai;
        char grade;
        int lulus = 1; // Ini digunakan untuk mengecek apakah ada yang tidak lulus

        // Input nilai dengan validasi menggunakan do-while
        do {
            printf("Nilai Quis: ");
            if (scanf("%f", &nilaiQuis) == 1 && nilaiQuis >= 0 && nilaiQuis <= 100) {
                break; // Keluar dari loop jika input valid
            } else {
                printf("Input nilai Quis tidak valid. Masukkan nilai antara 0 hingga 100.\n");
                while (getchar() != '\n'); // Membersihkan input buffer
            }
        } while (1);

        do {
            printf("Nilai Tugas: ");
            if (scanf("%f", &nilaiTugas) == 1 && nilaiTugas >= 0 && nilaiTugas <= 100) {
                break;
            } else {
                printf("Input nilai Tugas tidak valid. Masukkan nilai antara 0 hingga 100.\n");
                while (getchar() != '\n');
            }
        } while (1);

        // Lakukan validasi yang sama untuk nilai-nilai lainnya (Absensi, Praktek, UAS)
        // ...

        // Menghitung total nilai
        totalNilai = (nilaiQuis + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5;

        // Menentukan grade
        if (totalNilai <= 55) {
            grade = 'E';
            lulus = 0; // Set lulus menjadi 0 jika ada yang tidak lulus
        } else if (totalNilai <= 65) {
            grade = 'D';
            lulus = 0; // Set lulus menjadi 0 jika ada yang tidak lulus
        } else if (totalNilai <= 75) {
            grade = 'C';
        } else if (totalNilai <= 85) {
            grade = 'B';
        } else {
            grade = 'A';
        }

        // Menampilkan grade
        printf("Grade: %c\n\n", grade);
    }

    return 0;
}
