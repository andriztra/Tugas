#include <stdio.h>

// Fungsi pass-by-address
void passByAddress(int *x) {
    printf("Saya memberikan kunci asli dengan nomor %d kepada Anda.\n", *x);
    (*x) = 0; // Mengubah kunci asli
    printf("Anda kehilangan kunci asli atau mengubahnya menjadi %d, sehingga kunci asli saya juga berubah.\n", *x);
}

int main() {
    int kunciAsli = 1234;

    printf("Saya memiliki kunci asli dengan nomor %d.\n", kunciAsli);
    passByAddress(&kunciAsli);
    printf("Setelah Anda mengembalikan kunci asli, kunci asli saya sekarang dengan nomor %d.\n", kunciAsli);

    return 0;
}
