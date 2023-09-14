#include <stdio.h>
#include <stdbool.h>

int main() {
    int jumlahMahasiswa;
    int i;
    char ulangi;
    float totalNilaiSemuaMahasiswa = 0.0;
    do {
	    puts("#########################################");
	    printf("Program Perhitungan Grade Mahasiswa\n");
	    puts("#########################################");
	 
	    do {
	        printf("Masukkan Jumlah Mahasiswa: ");
	        if (scanf("%d", &jumlahMahasiswa) != 1 || jumlahMahasiswa < 1 || jumlahMahasiswa > 100) {
	            printf("Input jumlah mahasiswa tidak valid. Masukkan angka antara 1 dan 100.\n");
	            while (getchar() != '\n'); // Membersihkan input buffer
	        } else {
	            break; // Keluar dari loop jika input valid
	        }
	    } while (true);
	
	    for (i = 1; i <= jumlahMahasiswa; i++) {
	        printf("Mahasiswa ke-%d\n", i);
	
	        float nilaiQuis, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS, totalNilai;
	        char grade;
	        int lulus = 1; // Ini digunakan untuk mengecek apakah ada yang tidak lulus
	
	        // Input nilai dengan validasi menggunakan scanf yang dimodifikasi
	        printf("Nilai Quiz: ");
	        if (scanf("%f", &nilaiQuis) != 1 || nilaiQuis < 0 || nilaiQuis > 100) {
	            printf("Input nilai Quis tidak valid. Masukkan nilai antara 0 hingga 100.\n\n");
	            i--; // Kembali ke mahasiswa yang sama
	            while (getchar() != '\n'); // Membersihkan input buffer
	            continue;
	        }
	
	        printf("Nilai Tugas: ");
	        if (scanf("%f", &nilaiTugas) != 1 || nilaiTugas < 0 || nilaiTugas > 100) {
	            printf("Input nilai Tugas tidak valid. Masukkan nilai antara 0 hingga 100.\n\n");
	            i--;
	            while (getchar() != '\n');
	            continue;
	        }
	
	        printf("Nilai Absensi: ");
	        if (scanf("%f", &nilaiAbsensi) != 1 || nilaiAbsensi < 0 || nilaiAbsensi > 100) {
	            printf("Input nilai Absensi tidak valid. Masukkan nilai antara 0 hingga 100.\n\n");
	            i--;
	            while (getchar() != '\n');
	            continue;
	        }
	
	        printf("Nilai Praktek: ");
	        if (scanf("%f", &nilaiPraktek) != 1 || nilaiPraktek < 0 || nilaiPraktek > 100) {
	            printf("Input nilai Praktek tidak valid. Masukkan nilai antara 0 hingga 100.\n\n");
	            i--;
	            while (getchar() != '\n');
	            continue;
	        }
	
	        printf("Nilai UAS: ");
	        if (scanf("%f", &nilaiUAS) != 1 || nilaiUAS < 0 || nilaiUAS > 100) {
	            printf("Input nilai UAS tidak valid. Masukkan nilai antara 0 hingga 100.\n\n");
	            i--;
	            while (getchar() != '\n');
	            continue;
	        }
	
	        // Menentukan grade
	        totalNilai = (nilaiQuis + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5;
	        
	        if (totalNilai <= 55) {
	            grade = 'E';
	            printf("Rata Rata Nilai adalah %.1f \n", totalNilai);
	        } else if (totalNilai <= 65) {
	            grade = 'D';
	            printf("Rata Rata Nilai adalah %.1f \n", totalNilai);
	        } else if (totalNilai <= 75) {
	            grade = 'C';
	            printf("Rata Rata Nilai adalah %.1f \n", totalNilai);
	        } else if (totalNilai <= 85) {
	            grade = 'B';
	            printf("Rata Rata Nilai adalah %.1f \n", totalNilai);
	        } else {
	            grade = 'A';
	            printf("Rata Rata Nilai adalah %.1f \n", totalNilai);
	        }
	
	        // Menampilkan grade
	        printf("Grade: %c\n\n", grade);
	                // Menambahkan total nilai mahasiswa saat ini ke total semua mahasiswa
	        totalNilaiSemuaMahasiswa += totalNilai;
	    } 
	    
	    // Menghitung rata-rata nilai semua mahasiswa
	    float rataRata = totalNilaiSemuaMahasiswa / jumlahMahasiswa;
	    
	    printf("Rata-rata nilai semua mahasiswa: %.1f\n", rataRata);
	    if (totalNilaiSemuaMahasiswa <= 65) {
	            printf("Label: Tidak Lulus\n\n");
	        } else {
	            printf("Label: LULUS\n\n");
				}
	            printf("Apakah Anda ingin mengulang lagi? (y/n): ");
	            scanf(" %c", &ulangi);
	}while (ulangi == 'y' || ulangi == 'Y');
	puts("***************************************");
	printf("Terima kasih! Program selesai.\n");
	puts("***************************************");
	
	return 0;
}
