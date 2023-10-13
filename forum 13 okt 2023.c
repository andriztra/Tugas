#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    char ID[12];
    char Nama[50];
    char Prodi[50];
    float GPA;
};

int main() {
    int n; // Jumlah mahasiswa
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Membuat array mahasiswa sesuai jumlah yang dimasukkan
    struct Mahasiswa mahasiswa[n];

    // Mengisi data mahasiswa
    for (int i = 0; i < n; i++) {
        printf("Data Mahasiswa %d:\n", i + 1);
        printf("ID: ");
        scanf("%s", mahasiswa[i].ID);
        printf("Nama: ");
        scanf(" %[^\n]", mahasiswa[i].Nama);
        printf("Prodi: ");
        scanf(" %[^\n]", mahasiswa[i].Prodi);
        printf("GPA: ");
        scanf("%f", &mahasiswa[i].GPA);
    }

    // Menampilkan data mahasiswa
    printf("\nData Mahasiswa:\n");
    printf("%-10s %-20s %-20s %s\n", "ID", "Nama", "Prodi", "GPA");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-20s %-20s %.2f\n", mahasiswa[i].ID, mahasiswa[i].Nama, mahasiswa[i].Prodi, mahasiswa[i].GPA);
    }

    return 0;
}
