#include <stdio.h>

// Fungsi pass-by-value
void passByValue(int x) {
    printf("Saya memberikan kunci salinan dengan nomor %d kepada Anda.\n", x);
    x = 0; // Mengubah salinan kunci (tidak memengaruhi kunci asli)
    printf("Anda kehilangan kunci salinan atau mengubahnya menjadi %d, tapi kunci asli saya tetap aman.\n", x);
}

int main() {
    int kunciAsli = 1234;

    printf("Saya memiliki kunci asli dengan nomor %d.\n", kunciAsli);
    passByValue(kunciAsli);
    printf("Setelah Anda mengembalikan kunci salinan, kunci asli saya masih dengan nomor %d.\n", kunciAsli);

    return 0;
}
