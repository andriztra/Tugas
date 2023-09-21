#include <stdio.h>

int main() {
    // Array kode
    const char *kode[] = {"ORTI1", "COMP6112036", "COMP6112036", "COMP6112036", "COMP6112036"};

    // Array matkul
    const char *matkul[] = {
        "Academic Orientation PJJ Computer Science",
        "Algorithm and Programming",
        "Competency Orientation",
        "Discrete Mathematics and Linear Algebra",
        "General Orientation"
    };

    // Array sks
    int sks[] = {4, 4, 4, 4, 4};

    // Array grade
    char grade[] = {'A', 'A', 'A', 'A', 'A'};

    // Menampilkan data dari setiap array
    printf("Kode          Matkul                                       SKS  Grade\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < sizeof(kode) / sizeof(kode[0]); i++) {
        printf("%-12s %-45s %d    %c\n", kode[i], matkul[i], sks[i], grade[i]);
    }

    return 0;
}
