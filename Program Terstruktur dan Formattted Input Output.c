{
    // ! Inisialisasi variabel
    char names[100][50];
    int results[100];
    int numStudents;
    int passed = 0, failed = 0;

    // ! masukan jumlah mahasiswa dengan validasi
    do {
        greet(); // output membuat salam pembuka
        printf("Masukkan jumlah mahasiswa (maksimal jumlah 100): ");
        scanf("%d", &numStudents);
        clearInputBuffer(); // ! menghapus input buffer
    } 
    //looping ketika input selain angka,kembali lagi
    while (numStudents <= 0 || numStudents > 100);

    // ! masukan data hasil ujian untuk setiap mahasiswa
    for (int i = 0; i < numStudents; i++) {
        printf("Nama: ");
        scanf("%s", names[i]);
        clearInputBuffer(); // ! menghapus input buffer

        // ! Input hasil ujian dengan validasi
        do {
            printf("Masukkan hasil (1: Lulus, 2: Gagal) untuk %s: ", names[i]);

            // ! Menggunakan scanf untuk memeriksa apakah input angka valid
            if (scanf("%d", &results[i]) != 1) {
                clearInputBuffer(); // ! jika input tidak valid, maka hapus buffer input
                printf("Invalid. Hanya boleh memasukkan 1 atau 2.\n");
            }
//looping ketika input selain angka,kembali lagi
        } while (results[i] != 1 && results[i] != 2);

        // ! Menghitung jumlah lulus dan gagal
        if (results[i] == 1) {
            passed++;
        } else if (results[i] == 2) {
            failed++;
        }
    }

    // Menampilkan hasil ujian untuk setiap mahasiswa
    printf("\nHasil Ujian Mahasiswa:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Nama: %s, Hasil: %s\n", names[i], results[i] == 1 ? "Lulus" : "Gagal");
    }

    // Menghitung persentase kelulusan
    float passPercentage = (float) passed / numStudents * 100;

    // Menampilkan jumlah lulus, gagal, dan persentase kelulusan
    printf("\nJumlah Lulus: %d\n", passed);
    printf("Jumlah Gagal: %d\n", failed);
    printf("Persentase Kelulusan: %.2f%%\n", passPercentage);

    // Menampilkan output tambahan jika kelulusan lebih dari 80 persen
    if (passPercentage > 80.0) {
        printf("Kelulusan kelas telah mencapai target!\n");
        printf("==================\n");
        printf("Senang bisa membantu anda");
    }
    // Menampilkan output tambahan jika kelulusan kurang dari 80 persen
    else if (passPercentage < 80.0) {
        printf("Kelulusan kelas belum mencapai target!\n");
        printf("==================\n");
        printf("Senang bisa membantu anda");
    }

    return 0;
}
