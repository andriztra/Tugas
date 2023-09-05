#include <stdio.h>

int main() {
    int a = 10;

    // Menentukan angka pada masing-masing 'x'

    //operasi sebelumnya 10(a) - 4 = 6
    int x1 = 4; // 6 (a) + 4 = 10
    int x2 = 2; // 10 (a) * 2 = 20
    int x3 = 2; // 20 (a) / 2 = 10
    int x4 = a + 1; // 10 % (10 + 1) = 10 Nilai akan tetap sama jika nilai pembagi modulus di atas nilai yang di bagi

    //Loop akan terjadi tapi nilai akan tetap sama
    for (int i = 0; i < 10 ; i++) { 
        a -= 4;
        a += x1;
        a *= x2;
        a /= x3;
        a %= x4;
        printf("Loop %d \n", i);
    }

    // Result
    printf("Hasil Akhir Nilai a : %d", a);

    return 0;
}
