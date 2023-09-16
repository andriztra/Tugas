#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // Hanya tersedia di lingkungan Windows

struct Mahasiswa {
    char nim[20];
    char nama[50];
    char alamat[100];
    char no_hp[15];
};

int isNumeric(const char *str) {
    // Memeriksa apakah string str terdiri dari digit (angka) saja
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) || str[0] == '-') {
            return 0; // Bukan numeric atau angka negatif
        }
    }
    return 1; // Numeric
}

int isAlpha(const char *str) {
    // Memeriksa apakah string str terdiri dari huruf (alphabet) saja
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i])) {
            return 0; // Bukan huruf
        }
    }
    return 1; // Alphabet
}

void addStudent(struct Mahasiswa *mahasiswa, int *count) {
    printf("\n== Menu Add ==\n");
    char nim[20], nama[50], alamat[100], no_hp[15];

    while (1) {
        printf("Masukkan NIM: ");
        int i = 0;
        char ch;
        
        while (1) {
            ch = getch();
            
            if (ch == 13) { // Enter key
                nim[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) { // Backspace key
                printf("\b \b");
                i--;
            } else if (isdigit(ch) && i < 19) {
                printf("%c", ch);
                nim[i] = ch;
                i++;
            }
        }

        // Validasi NIM
        if (!isNumeric(nim)) {
            printf("\nInput NIM tidak valid. Harap masukkan angka positif.\n");
            continue;
        }

        break;
    }

    while (1) {
        printf("\nMasukkan Nama: ");
        int i = 0;
        char ch;
        
        while (1) {
            ch = getch();
            
            if (ch == 13) { // Enter key
                nama[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) { // Backspace key
                printf("\b \b");
                i--;
            } else if (isalpha(ch) && i < 49) {
                printf("%c", ch);
                nama[i] = ch;
                i++;
            }
        }

        // Validasi Nama
        if (!isAlpha(nama)) {
            printf("\nInput Nama tidak valid. Harap masukkan huruf saja.\n");
            continue;
        }

        break;
    }

    printf("\nMasukkan Alamat: ");
    int i = 0;
    char ch;
    
    while (1) {
        ch = getch();
        
        if (ch == 13) { // Enter key
            alamat[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) { // Backspace key
            printf("\b \b");
            i--;
        } else if (i < 99) {
            printf("%c", ch);
            alamat[i] = ch;
            i++;
        }
    }

    while (1) {
        printf("\nMasukkan No HP: ");
        int i = 0;
        char ch;
        
        while (1) {
            ch = getch();
            
            if (ch == 13) { // Enter key
                no_hp[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) { // Backspace key
                printf("\b \b");
                i--;
            } else if (isdigit(ch) && i < 14) {
                printf("%c", ch);
                no_hp[i] = ch;
                i++;
            }
        }

        // Validasi No HP
        if (!isNumeric(no_hp)) {
            printf("\nInput No HP tidak valid. Harap masukkan angka saja.\n");
            continue;
        }

        break;
    }

    // Simpan data mahasiswa ke dalam array
    strcpy(mahasiswa[*count].nim, nim);
    strcpy(mahasiswa[*count].nama, nama);
    strcpy(mahasiswa[*count].alamat, alamat);
    strcpy(mahasiswa[*count].no_hp, no_hp);
    (*count)++; // Menambah jumlah mahasiswa yang telah diinput
    printf("\nData mahasiswa %s dengan NIM %s berhasil ditambahkan!\n", nama, nim);
}

void viewStudents(struct Mahasiswa *mahasiswa, int count) {
    printf("\n== Menu View ==\n");
    
    if (count == 0) {
        printf("Daftar mahasiswa kosong.\n");
        return;
    }

    printf("Daftar mahasiswa:\n");
    for (int i = 0; i < count; i++) {
        printf("NIM: %s\n", mahasiswa[i].nim);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("Alamat: %s\n", mahasiswa[i].alamat);
        printf("No HP: %s\n", mahasiswa[i].no_hp);
        printf("\n");
    }
}

void deleteStudent(struct Mahasiswa *mahasiswa, int *count) {
    printf("\n== Menu Delete ==\n");
    
    if (*count == 0) {
        printf("Daftar mahasiswa kosong.\n");
        return;
    }

    char nim[20];
    printf("Masukkan NIM mahasiswa yang ingin dihapus: ");
    int i = 0;
    char ch;
    
    while (1) {
        ch = getch();
        
        if (ch == 13) { // Enter key
            nim[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) { // Backspace key
            printf("\b \b");
            i--;
        } else if (i < 19) {
            printf("%c", ch);
            nim[i] = ch;
            i++;
        }
    }

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(mahasiswa[i].nim, nim) == 0) {
            // Menghapus mahasiswa dengan mengganti data dengan data dari indeks terakhir
            (*count) -= 1;
            mahasiswa[i] = mahasiswa[*count];
            printf("\nData mahasiswa dengan NIM %s berhasil dihapus.\n", nim);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nData mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
    }
}

void updateStudent(struct Mahasiswa *mahasiswa, int count) {
    printf("\n== Menu Update ==\n");
    
    if (count == 0) {
        printf("Daftar mahasiswa kosong.\n");
        return;
    }

    char nim[20];
    printf("Masukkan NIM mahasiswa yang ingin diupdate: ");
    int i = 0;
    char ch;
    
    while (1) {
        ch = getch();
        
        if (ch == 13) { // Enter key
            nim[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) { // Backspace key
            printf("\b \b");
            i--;
        } else if (i < 19) {
            printf("%c", ch);
            nim[i] = ch;
            i++;
        }
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(mahasiswa[i].nim, nim) == 0) {
            printf("\nData mahasiswa dengan NIM %s ditemukan. Silakan masukkan data yang baru:\n", nim);
            
            char nama[50], alamat[100], no_hp[15];

            while (1) {
                printf("Masukkan Nama: ");
                int i = 0;
                char ch;
                
                while (1) {
                    ch = getch();
                    
                    if (ch == 13) { // Enter key
                        nama[i] = '\0';
                        break;
                    } else if (ch == 8 && i > 0) { // Backspace key
                        printf("\b \b");
                        i--;
                    } else if (isalpha(ch) && i < 49) {
                        printf("%c", ch);
                        nama[i] = ch;
                        i++;
                    }
                }

                // Validasi Nama
                if (!isAlpha(nama)) {
                    printf("\nInput Nama tidak valid. Harap masukkan huruf saja.\n");
                    continue;
                }

                break;
            }

            printf("\nMasukkan Alamat: ");
            int i = 0;
            char ch;
            
            while (1) {
                ch = getch();
                
                if (ch == 13) { // Enter key
                    alamat[i] = '\0';
                    break;
                } else if (ch == 8 && i > 0) { // Backspace key
                    printf("\b \b");
                    i--;
                } else if (i < 99) {
                    printf("%c", ch);
                    alamat[i] = ch;
                    i++;
                }
            }

            while (1) {
                printf("\nMasukkan No HP: ");
                int i = 0;
                char ch;
                
                while (1) {
                    ch = getch();
                    
                    if (ch == 13) { // Enter key
                        no_hp[i] = '\0';
                        break;
                    } else if (ch == 8 && i > 0) { // Backspace key
                        printf("\b \b");
                        i--;
                    } else if (isdigit(ch) && i < 14) {
                        printf("%c", ch);
                        no_hp[i] = ch;
                        i++;
                    }
                }

                // Validasi No HP
                if (!isNumeric(no_hp)) {
                    printf("\nInput No HP tidak valid. Harap masukkan angka saja.\n");
                    continue;
                }

                break;
            }

            // Perbarui data mahasiswa
            strcpy(mahasiswa[i].nama, nama);
            strcpy(mahasiswa[i].alamat, alamat);
            strcpy(mahasiswa[i].no_hp, no_hp);
            
            printf("\nData mahasiswa dengan NIM %s berhasil diupdate!\n", nim);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nData mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
    }
}

void searchStudents(struct Mahasiswa *mahasiswa, int count) {
    printf("\n== Menu Search ==\n");
    
    if (count == 0) {
        printf("Daftar mahasiswa kosong.\n");
        return;
    }

    char keyword[50];
    printf("Masukkan kata kunci untuk pencarian: ");
    int i = 0;
    char ch;
    
    while (1) {
        ch = getch();
        
        if (ch == 13) { // Enter key
            keyword[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) { // Backspace key
            printf("\b \b");
            i--;
        } else if (i < 49) {
            printf("%c", ch);
            keyword[i] = ch;
            i++;
        }
    }

    printf("\nHasil pencarian:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(mahasiswa[i].nim, keyword) || strstr(mahasiswa[i].nama, keyword) || strstr(mahasiswa[i].alamat, keyword) || strstr(mahasiswa[i].no_hp, keyword)) {
            printf("NIM: %s\n", mahasiswa[i].nim);
            printf("Nama: %s\n", mahasiswa[i].nama);
            printf("Alamat: %s\n", mahasiswa[i].alamat);
            printf("No HP: %s\n", mahasiswa[i].no_hp);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ditemukan hasil pencarian untuk kata kunci '%s'.\n", keyword);
    }
}

int main() {
    struct Mahasiswa mahasiswa[100]; // Misalnya, kita maksimum menyimpan 100 mahasiswa
    int count = 0; // Jumlah mahasiswa yang telah diinput

    while (1) {
        printf("\n===== Program Pendaftaran Mahasiswa =====\n");
        printf("Pilihan Menu Utama:\n");
        printf("1. Add\n");
        printf("2. View\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Quit\n");

        int choice;
        printf("Pilih menu (1/2/3/4/5/6): ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Membersihkan buffer input

        switch (choice) {
            case 1:
                addStudent(mahasiswa, &count);
                break;
            case 2:
                viewStudents(mahasiswa, count);
                break;
            case 3:
                deleteStudent(mahasiswa, &count);
                break;
            case 4:
                updateStudent(mahasiswa, count);
                break;
            case 5:
                searchStudents(mahasiswa, count);
                break;
            case 6:
                printf("Terima kasih! Program selesai.\n");
                return 0;
            default:
                printf("Pilihan menu tidak valid. Harap masukkan pilihan yang benar (1-6).\n");
                break;
        }
    }
    return 0;
}
