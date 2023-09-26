#include <stdio.h>

// Fungsi iteratif untuk menghitung bilangan Fibonacci ke-n
long long fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long fib1 = 0;
    long long fib2 = 1;
    long long fib = 0;

    for (int i = 2; i <= n; i++) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }

    return fib;
}

// Fungsi rekursif dengan memoisasi untuk menghitung bilangan Fibonacci ke-n
long long fibonacciRecursiveMemo(int n, long long memo[]) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Cek apakah hasil sudah ada di memo
    if (memo[n] != -1) return memo[n];
    
    // Hitung rekursif dan simpan hasil ke memo
    memo[n] = fibonacciRecursiveMemo(n - 1, memo) + fibonacciRecursiveMemo(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 30; // Ubah nilai n sesuai dengan yang Anda inginkan

    // Menghitung bilangan Fibonacci ke-n dengan pendekatan iteratif
    long long resultIterative = fibonacciIterative(n);

    // Menghitung bilangan Fibonacci ke-n dengan pendekatan rekursif dengan memoisasi
    long long memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1; // Inisialisasi memo
    }
    memo[0] = 0;
    memo[1] = 1;
    long long resultRecursiveMemo = fibonacciRecursiveMemo(n, memo);

    printf("Bilangan Fibonacci ke-%d (iteratif): %lld\n", n, resultIterative);
    printf("Bilangan Fibonacci ke-%d (rekursif dengan memoisasi): %lld\n", n, resultRecursiveMemo);

    return 0;
}
