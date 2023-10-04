#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa {
    char nama[50];
    int umur;
    char jurusan[50];
};

int main() {
    // Membuat variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs1;

    // Mengisi data mahasiswa
    strcpy(mhs1.nama, "John");
    mhs1.umur = 20;
    strcpy(mhs1.jurusan, "Informatika");

    // Menampilkan informasi mahasiswa
    printf("Nama: %s\n", mhs1.nama);
    printf("Umur: %d tahun\n", mhs1.umur);
    printf("Jurusan: %s\n", mhs1.jurusan);

    return 0;
}
