#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk memeriksa apakah sebuah string hanya mengandung karakter alfabet
int isAlphabetic(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0; // Terdapat karakter yang bukan alfabet
        }
    }
    return 1; // Semua karakter adalah alfabet
}

// Fungsi untuk memeriksa apakah sebuah string berakhir dengan "@binus.ac.id"
int isBinusEmail(const char *str) {
    int len = strlen(str);
    const char *suffix = "@binus.ac.id";
    int suffixLen = strlen(suffix);

    if (len < suffixLen) {
        return 0; // Panjang string lebih pendek dari panjang sufiks
    }

    return strcmp(str + len - suffixLen, suffix) == 0;
}

// Fungsi untuk memeriksa apakah sebuah string hanya berisi angka
int isNumeric(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Terdapat karakter yang bukan angka
        }
    }
    return 1; // Semua karakter adalah angka
}

// Struktur untuk menyimpan data kontak
struct Contact {
    char name[100];
    char phone[15];
    char email[100];
    struct Contact* next;
};

// Fungsi untuk menambahkan kontak ke linked list
void addContact(struct Contact **head, char *name, char *phone, char *email) {
    // Validasi nama (hanya alfabet)
    if (!isAlphabetic(name)) {
        printf("Nama harus berisi karakter alfabet.\n");
        return;
    }

    // Validasi nomor HP (harus angka)
    if (!isNumeric(phone)) {
        printf("Nomor HP harus berupa angka.\n");
        return;
    }

    // Validasi email (@binus.ac.id)
    if (!isBinusEmail(email)) {
        printf("Email harus berakhir dengan '@binus.ac.id'.\n");
        return;
    }

    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    if (newContact == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = *head;
    *head = newContact;

    printf("Kontak berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan semua kontak
void displayContacts(struct Contact *head) {
    if (head == NULL) {
        printf("Daftar kontak kosong.\n");
        return;
    }

    printf("Daftar Kontak:\n");
    while (head != NULL) {
        printf("Nama: %s\n", head->name);
        printf("No. HP: %s\n", head->phone);
        printf("Email: %s\n", head->email);
        printf("\n");
        head = head->next;
    }
}

// Fungsi untuk menghapus kontak berdasarkan nama
void deleteContact(struct Contact **head, char *name) {
    struct Contact* current = *head;
    struct Contact* prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            found = 1;
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            printf("Kontak '%s' telah dihapus.\n", name);
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("Kontak '%s' tidak ditemukan.\n", name);
    }
}

int main() {
    struct Contact* head = NULL; // Inisialisasi linked list kosong
    int choice;
    char name[100], phone[15], email[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Tampilkan Kontak\n");
        printf("3. Hapus Kontak\n");
        printf("4. Keluar\n");
        printf("Pilih tindakan (1/2/3/4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Masukkan harus berupa angka.\n");
            while (getchar() != '\n'); // Membersihkan input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", name);

                // Validasi nama (hanya alfabet)
                if (!isAlphabetic(name)) {
                    printf("Nama harus berisi karakter alfabet.\n");
                    while (getchar() != '\n'); // Membersihkan input buffer
                    break;
                }

                printf("Masukkan No. HP: ");
                scanf("%s", phone);

                // Validasi nomor HP (harus angka)
                if (!isNumeric(phone)) {
                    printf("Nomor HP harus berupa angka.\n");
                    while (getchar() != '\n'); // Membersihkan input buffer
                    break;
                }

                printf("Masukkan Email: ");
                scanf("%s", email);

                // Validasi email (@binus.ac.id)
                if (!isBinusEmail(email)) {
                    printf("Email harus berakhir dengan '@binus.ac.id'.\n");
                    while (getchar() != '\n'); // Membersihkan input buffer
                    break;
                }

                addContact(&head, name, phone, email);
                break;
            case 2:
                displayContacts(head);
                break;
            case 3:
                printf("Masukkan Nama Kontak yang akan dihapus: ");
                scanf("%s", name);

                // Membersihkan input buffer
                while (getchar() != '\n');

                deleteContact(&head, name);
                break;
            case 4:
                printf("Program selesai.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Masukkan 1, 2, 3, atau 4.\n");
                while (getchar() != '\n'); // Membersihkan input buffer
        }
    }

    return 0;
}
