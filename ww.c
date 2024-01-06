#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct contact{
    char nama[30];
    int umur;
    char jenisKelamin;
    char noTelp[14];
    char email[30];
};

typedef struct contact kontak;
typedef struct {
    kontak kontak[N];
    int jumlah;
    int indeksUndoEdit;
    kontak undoEditBuffer[N];
    int indeksRedoEdit;
    kontak redoEditBuffer[N];
    int indeksUndoInsert;
    kontak undoInsertBuffer[N];
    int indeksRedoInsert;
    kontak redoInsertBuffer[N];
    int indeksRedoDelete;
    kontak redoDeleteBuffer[N];
    int indeksUndoDelete;
    kontak undoDeleteBuffer[N];
} BukuKontak;

void tambahKontak(BukuKontak *buku) {
    char buffer[100]; // Buffer tambahan untuk membersihkan newline character

    if (buku->jumlah < N) {
        printf("--------------------------------------------------\n");
        printf("\t\tAPLIKASI BUKU KONTAK\n");
        printf("--------------------------------------------------\n");
        printf("|\t\tTAMBAH DAFTAR KONTAK\t\t |\n");
        printf("--------------------------------------------------\n");

        // Backup state saat ini ke undo buffer
        memcpy(buku->undoInsertBuffer, buku->kontak, sizeof(kontak) * N);
        buku->indeksUndoInsert++;

        kontak *temp = &buku->kontak[buku->jumlah];
        printf("| Kontak %d\n", buku->jumlah + 1);
        printf("| Nama : ");
        fgets(buffer, sizeof(buffer), stdin); // Membersihkan newline character dari buffer
        fgets(temp->nama, sizeof(temp->nama), stdin);
        temp->nama[strcspn(temp->nama, "\n")] = '\0'; // Menghilangkan newline character
        printf("| Umur : ");
        scanf("%d", &temp->umur);
        printf("| Jenis Kelamin (L/P) : ");
        scanf(" %c", &temp->jenisKelamin);
        printf("| Nomor Telepon : ");
        scanf("%s", temp->noTelp);
        printf("| Email : ");
        scanf("%s", temp->email);
        printf("--------------------------------------------------\n");

        buku->jumlah++;
        printf("Kontak %d berhasil ditambahkan.\n", buku->jumlah );
    } else {
        printf("Buku kontak penuh. Tidak dapat menambahkan lebih banyak kontak.\n\n");
    }
}

void deleteKontak(BukuKontak *buku, int criteria) {
    char target[30];
    int target2;
    char target3;
    char target4[14];
    char target5[30];
    int found = 0;

    switch (criteria) {
        case 1:
            printf("| Masukkan Nama Daftar Kontak yang ingin Anda Hapus : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = '\0';

            for (int i = 0; i < buku->jumlah; i++) {
                if (strstr(buku->kontak[i].nama, target) != NULL) {
                    // Copy data yang akan dihapus ke undo buffer
                    memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[i], sizeof(kontak));
                    buku->indeksUndoDelete++;

                    // Geser elemen ke kiri untuk menghapus data
                    for (int j = i; j < buku->jumlah - 1; j++) {
                        buku->kontak[j] = buku->kontak[j + 1];
                    }

                    found = 1;
                    break;
                }
            }

            if (found) {
                buku->jumlah--;
                printf("| Kontak dengan nama %s berhasil dihapus.\n", target);
            } else {
                printf("| Kontak dengan nama %s tidak ditemukan.\n", target);
            }
            break;

        case 2:
            printf("| Masukkan Umur Daftar Kontak yang ingin Anda Hapus : ");
            scanf("%d", &target2);

            for (int i = 0; i < buku->jumlah; i++) {
                if (buku->kontak[i].umur == target2) {
                    // Copy data yang akan dihapus ke undo buffer
                    memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[i], sizeof(kontak));
                    buku->indeksUndoDelete++;

                    // Geser elemen ke kiri untuk menghapus data
                    for (int j = i; j < buku->jumlah - 1; j++) {
                        buku->kontak[j] = buku->kontak[j + 1];
                    }

                    found = 1;
                }
            }

            if (found) {
                buku->jumlah--;
                printf("| Kontak dengan umur %d berhasil dihapus.\n", target2);
            } else {
                printf("| Kontak dengan umur %d tidak ditemukan.\n", target2);
            }
            break;

        case 3:
            printf("| Masukkan Jenis Kelamin Daftar Kontak yang ingin Anda Hapus : ");
            scanf(" %c", &target3);

            for (int i = 0; i < buku->jumlah; i++) {
                if (buku->kontak[i].jenisKelamin == target3) {
                    // Copy data yang akan dihapus ke undo buffer
                    memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[i], sizeof(kontak));
                    buku->indeksUndoDelete++;

                    // Geser elemen ke kiri untuk menghapus data
                    for (int j = i; j < buku->jumlah - 1; j++) {
                        buku->kontak[j] = buku->kontak[j + 1];
                    }

                    found = 1;
                }
            }

            if (found) {
                buku->jumlah--;
                printf("| Kontak dengan jenis kelamin %c berhasil dihapus.\n", target3);
            } else {
                printf("| Kontak dengan jenis kelamin %c tidak ditemukan.\n", target3);
            }
            break;

        case 4:
            printf("| Masukkan Nomor Telepon Daftar Kontak yang ingin Anda Hapus : ");
            scanf("%s", target4);

            for (int i = 0; i < buku->jumlah; i++) {
                if (strcmp(buku->kontak[i].noTelp, target4) == 0) {
                    // Copy data yang akan dihapus ke undo buffer
                    memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[i], sizeof(kontak));
                    buku->indeksUndoDelete++;

                    // Geser elemen ke kiri untuk menghapus data
                    for (int j = i; j < buku->jumlah - 1; j++) {
                        buku->kontak[j] = buku->kontak[j + 1];
                    }

                    found = 1;
                }
            }

            if (found) {
                buku->jumlah--;
                printf("| Kontak dengan nomor telepon %s berhasil dihapus.\n", target4);
            } else {
                printf("| Kontak dengan nomor telepon %s tidak ditemukan.\n", target4);
            }
            break;

        case 5:
            printf("| Masukkan Email Daftar Kontak yang ingin Anda Hapus : ");
            scanf("%s", target5);

            for (int i = 0; i < buku->jumlah; i++) {
                if (strcmp(buku->kontak[i].email, target5) == 0) {
                    // Copy data yang akan dihapus ke undo buffer
                    memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[i], sizeof(kontak));
                    buku->indeksUndoDelete++;

                    // Geser elemen ke kiri untuk menghapus data
                    for (int j = i; j < buku->jumlah - 1; j++) {
                        buku->kontak[j] = buku->kontak[j + 1];
                    }

                    found = 1;
                }
            }

            if (found) {
                buku->jumlah--;
                printf("| Kontak dengan email %s berhasil dihapus.\n", target5);
            } else {
                printf("| Kontak dengan email %s tidak ditemukan.\n", target5);
            }
            break;

        default:
            printf("Pilihan tidak valid.\n");
            break;
    }

    // Setelah menghapus, inisialisasi elemen terakhir dengan nilai default
    memset(&buku->kontak[buku->jumlah], 0, sizeof(kontak));
}

void menudelete(BukuKontak *buku) {
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\t    MENU DELETE\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Hapus Berdasarkan Nama\t\t\t |\n");
    printf("| 2. Hapus Berdasarkan Umur\t\t\t |\n");
    printf("| 3. Hapus Berdasarkan Jenis Kelamin\t\t |\n");
    printf("| 4. Hapus Berdasarkan No Telepon\t\t |\n");
    printf("| 5. Hapus Berdasarkan Email\t\t\t |\n");
    printf("| 6. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 7. Keluar\t\t\t\t\t |\n");
    printf("----------------------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d", &choice);
    printf("----------------------------------------------------------------------\n");

    switch (choice) {
        case 1:
            deleteKontak(buku, 1);
            break;
        case 2:
            deleteKontak(buku, 2);
            break;
        case 3:
            deleteKontak(buku, 3);
            break;
        case 4:
            deleteKontak(buku, 4);
            break;
        case 5:
            deleteKontak(buku, 5);
            break;
        case 6:
            // Kembali ke Menu Utama
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
    }
}

void editKontak(BukuKontak *buku) {
    char namaLama[30];
    int ditemukan = 0;
    char buffer[100]; // Buffer tambahan untuk membersihkan newline character
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\t    EDIT KONTAK      \t\t |\n");
    printf("--------------------------------------------------\n");

    printf("| Masukkan Nama Kontak Yang Akan Diedit: ");

    fgets(buffer, sizeof(buffer), stdin); // Membersihkan newline character dari buffer
    fgets(namaLama, sizeof(namaLama), stdin);
    namaLama[strcspn(namaLama, "\n")] = '\0'; // Menghilangkan newline character

    for (int i = 0; i < buku->jumlah; i++) {
        if (strcmp(buku->kontak[i].nama, namaLama) == 0) {
            ditemukan++;
            printf("--------------------------------------------------\n");
            printf("\t\t     Kontak %d\n", i + 1);
            printf("--------------------------------------------------\n");
            printf("| Nama : %s\n", buku->kontak[i].nama);
            printf("| Umur : %d\n", buku->kontak[i].umur);
            printf("| Jenis Kelamin (L/P) : %c\n", buku->kontak[i].jenisKelamin);
            printf("| No. Telepon : %s\n", buku->kontak[i].noTelp);
            printf("| Email : %s\n", buku->kontak[i].email);

            // Backup state saat ini ke undo buffer
            memcpy(buku->undoEditBuffer, buku->kontak, sizeof(kontak) * N);
            buku->indeksUndoEdit++;
            printf("--------------------------------------------------\n");
            printf("\t      Masukkan informasi baru:\n");
            printf("--------------------------------------------------\n");
            printf("| Nama : ");
            fgets(buku->kontak[i].nama, sizeof(buku->kontak[i].nama), stdin);
            buku->kontak[i].nama[strcspn(buku->kontak[i].nama, "\n")] = '\0'; // Menghilangkan newline character
            printf("| Umur : ");
            scanf("%d", &buku->kontak[i].umur);
            printf("| Jenis Kelamin (L/P) : ");
            scanf(" %c", &buku->kontak[i].jenisKelamin);
            printf("| No. Telepon : ");
            scanf("%s", buku->kontak[i].noTelp);
            printf("| Email : ");
            scanf("%s", buku->kontak[i].email);
        }
    }

    if (ditemukan == 0) {
        printf("Kontak tidak ditemukan.\n");
    }
}

void hasilsearch(kontak *data) {
    printf("| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
           data->nama, data->umur, data->jenisKelamin,
           data->noTelp, data->email);
}

void headertable(){
    printf("--------------------------------------------------\n");
    printf("|\t\tDAFTAR CONTACT\t\t\t |\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("| %-30s | %-4s | %-2s | %-14s | %-30s |\n", "Nama", "Umur", "JK", "No. Telepon", "Email");
    printf("| %s | %s | %s | %s | %s |\n", "------------------------------", "----", "--", "--------------", "------------------------------");
}

void search(BukuKontak *buku, int criteria) {
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;
    char target_notelp[14];
    char target_email[30];

    switch (criteria) {
    case 1:
        printf("| Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL) {
                found++;
                hasilsearch(&buku->kontak[i]);
            }

        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 2:
        printf("| Masukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (buku->kontak[i].umur == target_umur) {
                found++;
                hasilsearch(&buku->kontak[i]);
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 3:
        printf("| Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&buku->kontak[i]);
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 4:
        printf("| Masukkan Nomor Telepon Kontak yang ingin Anda cari : ");
        scanf("%s", target_notelp);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strcmp(buku->kontak[i].noTelp, target_notelp) == 0) {
                found++;
                hasilsearch(&buku->kontak[i]);
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 5:
        printf("|Masukkan Email Kontak yang ingin Anda cari : ");
        scanf("%s", target_email);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strcmp(buku->kontak[i].email, target_email) == 0) {
                found++;
                hasilsearch(&buku->kontak[i]);
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    }

    if (found == 0) {
        printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
        printf("------------------------------------------------------------------------------------------------\n");
    }
}

void menusearchtunggal(BukuKontak *buku){
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SEARCH TUNGGAL\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama\t\t\t |\n");
    printf("| 2. Search Berdasarkan Umur\t\t\t |\n");
    printf("| 3. Search Berdasarkan Jenis Kelamin\t\t |\n");
    printf("| 4. Search Berdasarkan Nomor Telepon\t\t |\n");
    printf("| 5. Search Berdasarkan Email\t\t\t |\n");
    printf("| 6. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 7. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
   
        switch(choice){
            case 1: search(buku, 1);
                    break;
            case 2: search(buku, 2);
                    break;
            case 3: search(buku, 3);
                    break;
            case 4: search(buku, 4);
                    break;
            case 5: search(buku, 5);
                    break;
            case 6: 
                    break;
            case 7: exit(0);
                    break;
        }
}

void searchand(BukuKontak *buku,int criteria );

void searchand(BukuKontak *buku,int criteria ) {
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;

    switch (criteria) {
    case 1:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("Masukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL && buku->kontak[i].umur == target_umur) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 2:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL && buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 3:
        printf("Masukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (buku->kontak[i].umur == target_umur && buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 4:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("\nMasukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        printf("\nMasukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL && buku->kontak[i].umur == target_umur && buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    }

    if (found == 0) {
        printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
        printf("------------------------------------------------------------------------------------------------\n");
    }
}

void menusearchand(BukuKontak *buku){
    
    int choice;
    printf("----------------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("----------------------------------------------------------\n");
    printf("|\t\t\tMENU SEARCH AND\t\t\t |\n");
    printf("----------------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama dan Umur\t\t\t |\n");
    printf("| 2. Search Berdasarkan Nama dan Jenis Kelamin\t\t |\n");
    printf("| 3. Search Berdasarkan Umur dan Jenis Kelamin\t\t |\n");
    printf("| 4. Search Berdasarkan Nama, Umur, dan Jenis Kelamin\t |\n");
    printf("| 5. Kembali ke Menu Utama\t\t\t\t |\n");
    printf("| 6. Keluar\t\t\t\t\t\t |\n");
    printf("----------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("----------------------------------------------------------\n");
   
        switch(choice){
            case 1: searchand(buku, 1);
                    break;
            case 2: searchand(buku, 2);
                    break;
            case 3: searchand(buku, 3);
                    break;
            case 4: searchand(buku,4);
                    break;
            case 5:
                    break;
            case 6: exit(0);
                    break;
        }
}

void searchor(BukuKontak *buku,int criteria);

void searchor(BukuKontak *buku,int criteria) {
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;

    switch (criteria) {
    case 1:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("Masukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL || buku->kontak[i].umur == target_umur) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 2:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL || buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 3:
        printf("Masukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (buku->kontak[i].umur == target_umur || buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 4:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target_nama, sizeof(target_nama), stdin);
        target_nama[strcspn(target_nama, "\n")] = '\0';

        printf("\nMasukkan Umur Kontak yang ingin Anda cari : ");
        scanf("%d", &target_umur);
        printf("\nMasukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
        scanf(" %c", &target_jk);
        headertable();
        for (int i = 0; i < buku->jumlah; i++) {
            if (strstr(buku->kontak[i].nama, target_nama) != NULL || buku->kontak[i].umur == target_umur || buku->kontak[i].jenisKelamin == target_jk) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    }

    if (found == 0) {
        printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
        printf("------------------------------------------------------------------------------------------------\n");
    }
}

void menusearchor(BukuKontak *buku){
    
    int choice;
    printf("----------------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("----------------------------------------------------------\n");
    printf("|\t\t\tMENU SEARCH OR\t\t\t |\n");
    printf("----------------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama dan Umur\t\t\t |\n");
    printf("| 2. Search Berdasarkan Nama dan Jenis Kelamin\t\t |\n");
    printf("| 3. Search Berdasarkan Umur dan Jenis Kelamin\t\t |\n");
    printf("| 4. Search Berdasarkan Nama, Umur, dan Jenis Kelamin\t |\n");
    printf("| 5. Kembali ke Menu Utama\t\t\t\t |\n");
    printf("| 6. Keluar\t\t\t\t\t\t |\n");
    printf("----------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("----------------------------------------------------------\n");
   
        switch(choice){
            case 1: searchor(buku, 1);
                    break;
            case 2: searchor(buku, 2);
                    break;
            case 3: searchor(buku, 3);
                    break;
            case 4: searchor(buku, 4);
                    break;
            case 5:
                    break;
            case 6: exit(0);
                    break;
        }
}

void searchwildcard(BukuKontak *buku,int criteria);

void searchwildcard(BukuKontak *buku,int criteria) {
    int found = 0, cocok = 0;
    char target[30];

    switch (criteria) {
    case 1:
        printf("Masukkan Nama Kontak yang ingin Anda cari : ");
        getchar(); // Membersihkan buffer stdin
        fgets(target, sizeof(target), stdin);
        target[strcspn(target, "\n")] = '\0';
        headertable();

        if (target[strlen(target) - 1] != '*') {
            printf("| \t\t\tKriteria tidak valid (wajib diakhiri *)\t\t\t |\n");
            break;
        }

        for (int i = 0; i < buku->jumlah; i++) {
            cocok = 1;
            for (int j = 0; j < strlen(target) - 1; j++) {
                if (target[j] != buku->kontak[i].nama[j] && target[j] != '*') {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 2:
        printf("Masukkan Nomor Telepon Kontak yang ingin Anda cari : ");
        scanf("%s", target);
        headertable();

        if (target[strlen(target) - 1] != '*') {
            break;
        }

        for (int i = 0; i < buku->jumlah; i++) {
            cocok = 1;
            for (int j = 0; j < strlen(target) - 1; j++) {
                if (target[j] != buku->kontak[i].noTelp[j]) {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    case 3:
        printf("Masukkan Email Kontak yang ingin Anda cari : ");
        scanf("%s", target);
        headertable();

        if (target[strlen(target) - 1] != '*') {
            break;
        }

        for (int i = 0; i < buku->jumlah; i++) {
            cocok = 1;
            for (int j = 0; j < strlen(target) - 1; j++) {
                if (target[j] != buku->kontak[i].email[j]) {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(&(buku->kontak[i]));
            }
        }
        printf("------------------------------------------------------------------------------------------------\n");
        break;
    }

    if (found == 0 && cocok == 0) {
        if (target[strlen(target) - 1] != '*') {
            printf("| \t\t\tKriteria tidak valid (wajib diakhiri *)\t\t\t |\n");
        } else
            printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
        printf("------------------------------------------------------------------------------------------------\n");
    }
}

void menusearchwildcard(BukuKontak *buku){
    
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SEARCH WILDCARD\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Search Wildcard Berdasarkan Nama\t\t |\n");
    printf("| 2. Search Wildcard Berdasarkan Nomor Telepon\t |\n");
    printf("| 3. Search Wildcard Berdasarkan Email\t\t |\n");
    printf("| 4. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 5. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");
   
        switch(choice){
            case 1: searchwildcard(buku, 1);
                    break;
            case 2: searchwildcard(buku, 2);
                    break;
            case 3: searchwildcard(buku, 3);
                    break;
            case 4: 
                    break;
            case 5: exit(0);
                    break;
        }
}

void sorting(BukuKontak *buku, int criteria) {
    if (buku->jumlah == 0) {
        printf("Daftar Kontak Kosong\n");
        return;
    }

    switch (criteria) {
    case 1:
        for (int i = 0; i < buku->jumlah - 1; i++) {
            for (int j = 0; j < buku->jumlah - i - 1; j++) {
                if (strcmp(buku->kontak[j].nama, buku->kontak[j + 1].nama) > 0) {
                    // Swap contacts if they are in the wrong order
                    kontak temp = buku->kontak[j];
                    buku->kontak[j] = buku->kontak[j + 1];
                    buku->kontak[j + 1] = temp;
                }
            }
        }
        printf("Kontak berhasil diurutkan berdasarkan nama.\n");
        break;
    case 2:
        for (int i = 0; i < buku->jumlah - 1; i++) {
            for (int j = 0; j < buku->jumlah - i - 1; j++) {
                if (buku->kontak[j].umur > buku->kontak[j + 1].umur) {
                    // Swap contacts if they are in the wrong order
                    kontak temp = buku->kontak[j];
                    buku->kontak[j] = buku->kontak[j + 1];
                    buku->kontak[j + 1] = temp;
                }
            }
        }
        printf("Kontak berhasil diurutkan berdasarkan umur.\n");
        break;
    case 3:
        for (int i = 0; i < buku->jumlah - 1; i++) {
            for (int j = 0; j < buku->jumlah - i - 1; j++) {
                if (buku->kontak[j].jenisKelamin > buku->kontak[j + 1].jenisKelamin) {
                    // Swap contacts if they are in the wrong order
                    kontak temp = buku->kontak[j];
                    buku->kontak[j] = buku->kontak[j + 1];
                    buku->kontak[j + 1] = temp;
                }
            }
        }
        printf("Kontak berhasil diurutkan berdasarkan Jenis Kelamin.\n");
        break;
    case 4:
        for (int i = 0; i < buku->jumlah - 1; i++) {
            for (int j = 0; j < buku->jumlah - i - 1; j++) {
                if (strcmp(buku->kontak[j].noTelp, buku->kontak[j + 1].noTelp) > 0) {
                    // Swap contacts if they are in the wrong order
                    kontak temp = buku->kontak[j];
                    buku->kontak[j] = buku->kontak[j + 1];
                    buku->kontak[j + 1] = temp;
                }
            }
        }
        printf("Kontak berhasil diurutkan berdasarkan nomor telepon.\n");
        break;
    case 5:
        for (int i = 0; i < buku->jumlah - 1; i++) {
            for (int j = 0; j < buku->jumlah - i - 1; j++) {
                if (strcmp(buku->kontak[j].email, buku->kontak[j + 1].email) > 0) {
                    // Swap contacts if they are in the wrong order
                    kontak temp = buku->kontak[j];
                    buku->kontak[j] = buku->kontak[j + 1];
                    buku->kontak[j + 1] = temp;
                }
            }
        }
        printf("Kontak berhasil diurutkan berdasarkan Email.\n");
        break;
    }
}

void menusorting(BukuKontak *buku){
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SORTING\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Sorting Berdasarkan Nama\t\t\t |\n");
    printf("| 2. Sorting Berdasarkan Umur\t\t\t |\n");
    printf("| 3. Sorting Berdasarkan Jenis Kelamin\t\t |\n");
    printf("| 4. Sorting Berdasarkan No Telepon\t\t |\n");
    printf("| 5. Sorting Berdasarkan Email\t\t\t |\n");
    printf("| 6. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 7. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");

    
        switch(choice){
            case 1: sorting(buku, 1);
                    break;
            case 2: sorting(buku, 2);
                    break;
            case 3: sorting(buku, 3);
                    break;
            case 4: sorting(buku, 4);
                    break;
            case 5: sorting(buku, 5);
                    break;
            case 6: 
                    break;
            case 7: exit(0);
                    break;
        }

}

void save(BukuKontak *buku, char *namafile) {
    FILE *filecontact = fopen(namafile, "w");

    if (filecontact == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < buku->jumlah; i++) {
        fprintf(filecontact, "| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
                buku->kontak[i].nama, buku->kontak[i].umur,
                buku->kontak[i].jenisKelamin, buku->kontak[i].noTelp,
                buku->kontak[i].email);
    }

    fclose(filecontact);
    printf("--------------------------------------------------\n");
    printf("| Kontak berhasil disimpan ke dalam file: %s\n", namafile);
}

void load(BukuKontak *buku, char *namafile) {
    FILE *file = fopen(namafile, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    buku->jumlah = 0;

    while (fscanf(file, "| %30s | %4d | %2c | %14s | %30s |\n",
                  buku->kontak[buku->jumlah].nama, &buku->kontak[buku->jumlah].umur,
                  &buku->kontak[buku->jumlah].jenisKelamin, buku->kontak[buku->jumlah].noTelp,
                  buku->kontak[buku->jumlah].email) == 5) {
        buku->jumlah++;
        if (buku->jumlah >= N) {
            printf("Jumlah kontak melebihi batas maksimum.\n");
            break;
        }
    }

    fclose(file);
    printf("--------------------------------------------------\n");
    printf("|Kontak berhasil dimuat dari file: %s\n", namafile);
}

#include <stdio.h>

#include <stdio.h>

void numerik(BukuKontak *buku, int criteria) {
    int max_idx[buku->jumlah];  // Array untuk menyimpan indeks dengan nilai maksimum
    int min_idx[buku->jumlah];  // Array untuk menyimpan indeks dengan nilai minimum
    int max_count = 0;  // Penghitung untuk nilai maksimum
    int min_count = 0;  // Penghitung untuk nilai minimum
    int total = 0;
    float rerata;

    switch (criteria) {
        // maksimum
        case 1:
            max_count = 0;  // Reset penghitung
            max_idx[max_count++] = 0;

            for (int i = 1; i < buku->jumlah; i++) {
                if (buku->kontak[i].umur > buku->kontak[max_idx[0]].umur) {
                    max_count = 1;  // Reset penghitung karena ada umur yang lebih besar
                    max_idx[0] = i;
                } else if (buku->kontak[i].umur == buku->kontak[max_idx[0]].umur) {
                    max_idx[max_count++] = i;
                }
            }

            printf("| Kontak Tertua mempunyai umur : %d \n", buku->kontak[max_idx[0]].umur);
            printf("| Data Kontak Tertua : \n");
            headertable();
            for (int j = 0; j < max_count; j++) {
                hasilsearch(&buku->kontak[max_idx[j]]);
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;

        // minimum
        case 2:
            min_count = 0;  // Reset penghitung
            min_idx[min_count++] = 0;

            for (int i = 1; i < buku->jumlah; i++) {
                if (buku->kontak[i].umur < buku->kontak[min_idx[0]].umur) {
                    min_count = 1;  // Reset penghitung karena ada umur yang lebih kecil
                    min_idx[0] = i;
                } else if (buku->kontak[i].umur == buku->kontak[min_idx[0]].umur) {
                    min_idx[min_count++] = i;
                }
            }

            printf("| Kontak Termuda mempunyai umur : %d \n", buku->kontak[min_idx[0]].umur);
            printf("| Data Kontak Termuda : \n");
            headertable();
            for (int j = 0; j < min_count; j++) {
                hasilsearch(&buku->kontak[min_idx[j]]);
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;

        // rata-rata
        case 3:
            total = 0;
            for (int i = 0; i < buku->jumlah; i++) {
                total = total + buku->kontak[i].umur;
            }
            rerata = (float)total / buku->jumlah;
            printf("| Rata- Rata Umur Kontak adalah : %.2f tahun\n", rerata);
            break;
    }
}



void menunumerik(BukuKontak *buku){

    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU NUMERIK\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Mencari Kontak dengan Umur Tertua (MAX)\t |\n");
    printf("| 2. Mencari Kontak dengan Umur Termuda (MIN)\t |\n");
    printf("| 3. Mencari Umur Rata-Rata  Kontak (AVG)\t |\n");
    printf("| 4. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 5. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");

    
        switch(choice){
            case 1: numerik(buku, 1);
                    break;
            case 2: numerik(buku, 2);
                    break;
            case 3: numerik(buku, 3);
                    break;
            case 4: 
                    break;
            case 5: exit(0);
                    break;
        }

}

void menusearch(BukuKontak *buku) {
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SEARCH\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Search Tunggal\t\t\t\t |\n");
    printf("| 2. Search AND\t\t\t\t\t |\n");
    printf("| 3. Search OR\t\t\t\t\t |\n");
    printf("| 4. Search Wildcard\t\t\t\t |\n");
    printf("| 5. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 6. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d", &choice);
    printf("--------------------------------------------------\n");

    switch (choice) {
        case 1:
            menusearchtunggal(buku);
            break;
        case 2:
            menusearchand(buku);
            break;
        case 3:
            menusearchor(buku);
            break;
        case 4:
            menusearchwildcard(buku);
            break;
        case 5:
            break;
        case 6:
            exit(0);
            break;
    }
}

void display(BukuKontak *buku) {
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tDAFTAR CONTACT\t\t\t |\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("| %-30s | %-4s | %-2s | %-14s | %-30s |\n", "Nama", "Umur", "JK", "No. Telepon", "Email");
    printf("| %s | %s | %s | %s | %s |\n", "------------------------------", "----", "--", "--------------", "------------------------------");

    for (int i = 0; i < buku->jumlah; i++) {
        printf("| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
               buku->kontak[i].nama, buku->kontak[i].umur, buku->kontak[i].jenisKelamin,
               buku->kontak[i].noTelp, buku->kontak[i].email);
    }
    printf("------------------------------------------------------------------------------------------------\n");
}

void buat_tabel_relasi(int relasi_kontak[N][N], kontak daftar_kontak[N], int jumlah_kontak) {
    printf("---------------------------------------------------------------------------\n");
    printf("|                           BUAT TABEL RELASI                             |\n");
    printf("---------------------------------------------------------------------------\n");
    printf("| Masukkan relasi antar kontak:\n");
    printf("---------------------------------------------------------------------------\n");
    for (int i = 0; i < jumlah_kontak; i++) {
        for (int j = 0; j < jumlah_kontak; j++) {
            printf("| Apakah %s memiliki hubungan dengan %s? (1 (YA) / 0 (TIDAK)): ", daftar_kontak[i].nama, daftar_kontak[j].nama);
            scanf("%d", &relasi_kontak[i][j]);
        }
    }
    printf("---------------------------------------------------------------------------\n");
}

void tampilkan_tabel_relasi(int relasi_kontak[N][N], kontak daftar_kontak[N], int jumlah_kontak) {
    printf("----------------------------------------------------------\n");
    printf("|                    TABEL RELASI                        |\n");
    printf("----------------------------------------------------------\n");
    printf("| Kontak\t\t|");
    
    for (int i = 0; i < jumlah_kontak; i++) {
        printf("%22s         |", daftar_kontak[i].nama);
    }
    
    printf("\n|-----------------------|");

    for (int i = 0; i < jumlah_kontak; i++) {
        printf("-------------------------------|");
    }
    
    printf("\n");

    for (int i = 0; i < jumlah_kontak; i++) {
        printf("| %-21s |", daftar_kontak[i].nama);
        
        for (int j = 0; j < jumlah_kontak; j++) {
            printf("%22d         |", relasi_kontak[i][j]);
        }
        
        printf("\n");
    }
}

void undoEdit(BukuKontak *buku);
void undoInsert(BukuKontak *buku);
void undoDelete(BukuKontak *buku);

void menuundo(BukuKontak *buku) {
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU UNDO\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Undo Insert \t\t\t\t |\n");
    printf("| 2. Undo Edit \t\t\t\t\t |\n");
    printf("| 3. Undo Delete\t\t\t\t |\n");
    printf("| 4. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 5. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d", &choice);
    printf("--------------------------------------------------\n");

    switch (choice) {
        case 1:
            undoInsert(buku);
            break;
        case 2:
            undoEdit(buku);
            break;
        case 3:
            undoDelete(buku);
            break;
        case 4: break;
        case 5:
            exit(0);
            break;
    }
}

void undoInsert(BukuKontak *buku) {
    if (buku->indeksUndoInsert > 0) {
        // Kurangi indeks undo
        buku->indeksUndoInsert--;

        // Simpan keadaan saat ini ke redo buffer
        memcpy(buku->redoInsertBuffer, buku->kontak, sizeof(kontak) * N);
        buku->indeksRedoInsert++;

        // Pulihkan informasi kontak sebelumnya
        memcpy(buku->kontak, buku->undoInsertBuffer, sizeof(kontak) * N);

        // Kurangi jumlah kontak untuk menghapus data yang baru saja ditambahkan
        buku->jumlah--;

        printf("Undo Penambahan berhasil.\n");
    } else {
        printf("Tidak ada langkah undo penambahan lebih lanjut.\n");
    }
}

void undoEdit(BukuKontak *buku) {
    if (buku->indeksUndoEdit > 0) {
        // Kurangi indeks undo
        buku->indeksUndoEdit--;

        // Simpan keadaan saat ini ke redo buffer
        memcpy(buku->redoEditBuffer, buku->kontak, sizeof(kontak) * N);
        buku->indeksRedoEdit++;

        // Pulihkan informasi kontak sebelumnya
        memcpy(buku->kontak, buku->undoEditBuffer, sizeof(kontak) * N);

        printf("Undo Edit berhasil.\n");
    } else {
        printf("Tidak ada langkah undo edit lebih lanjut.\n");
    }
}

void undoDelete(BukuKontak *buku) {
    if (buku->indeksUndoDelete > 0) {
        buku->indeksUndoDelete--;

        // Copy data yang akan dihapus ke redo buffer
        memcpy(&buku->redoDeleteBuffer[buku->indeksRedoDelete], &buku->kontak[buku->jumlah], sizeof(kontak));

        // Copy data dari undo buffer ke kontak
        memcpy(&buku->kontak[buku->jumlah], &buku->undoDeleteBuffer[buku->indeksUndoDelete], sizeof(kontak));

        buku->indeksRedoDelete++;
        buku->jumlah++;
        printf("Undo Delete berhasil.\n");
    } else {
        printf("Tidak ada langkah undo delete lebih lanjut.\n");
    }
}

void redoEdit(BukuKontak *buku);

void redoInsert(BukuKontak *buku);

void redoDelete(BukuKontak *buku);

void menuredo(BukuKontak *buku){
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU REDO\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Redo Insert \t\t\t\t |\n");
    printf("| 2. Redo Edit \t\t\t\t\t |\n");
    printf("| 3. Redo Delete\t\t\t\t |\n");
    printf("| 4. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 5. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");

    
        switch(choice){
            case 1: redoInsert(buku);
                    break;
            case 2: redoEdit(buku);
                    break;
            case 3: redoDelete(buku);
                    break;
            case 4: break;
            case 5: exit(0);
                    break;
        }

}

void redoInsert(BukuKontak *buku) {
    if (buku->indeksRedoInsert > 0) {
        // Kurangi indeks redo
        buku->indeksRedoInsert--;

        // Simpan keadaan saat ini ke undo buffer
        memcpy(buku->undoInsertBuffer, buku->kontak, sizeof(kontak) * N);
        buku->indeksUndoInsert++;

        // Pulihkan informasi kontak berikutnya
        memcpy(buku->kontak, buku->redoInsertBuffer, sizeof(kontak) * N);

        // Tambah jumlah kontak untuk mengembalikan data yang baru saja dihapus
        buku->jumlah++;

        printf("Redo Penambahan berhasil.\n");
    } else {
        printf("Tidak ada langkah redo penambahan lebih lanjut.\n");
    }
}

void redoEdit(BukuKontak *buku) {
    if (buku->indeksRedoEdit > 0) {
        // Kurangi indeks redo
        buku->indeksRedoEdit--;

        // Simpan keadaan saat ini ke undo buffer
        memcpy(buku->undoEditBuffer, buku->kontak, sizeof(kontak) * N);
        buku->indeksUndoEdit++;

        // Pulihkan informasi kontak berikutnya
        memcpy(buku->kontak, buku->redoEditBuffer, sizeof(kontak) * N);

        printf("Redo Edit berhasil.\n");
    } else {
        printf("Tidak ada langkah redo edit lebih lanjut.\n");
    }
}

void redoDelete(BukuKontak *buku) {
    if (buku->indeksRedoDelete > 0) {
        buku->indeksRedoDelete--;

        // Copy data yang akan dihapus ke undo buffer
        memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontak[buku->jumlah - 1], sizeof(kontak));

        // Copy data dari redo buffer ke kontak
        memcpy(&buku->kontak[buku->jumlah - 1], &buku->redoDeleteBuffer[buku->indeksRedoDelete], sizeof(kontak));

        buku->indeksUndoDelete++;
        buku->jumlah--;
        printf("Redo Delete berhasil.\n");
    } else {
        printf("Tidak ada langkah redo delete lebih lanjut.\n");
    }
}

int menu() {
    int choice;
    printf("\033[1;34m"); // Kode ANSI untuk warna biru cerah
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\t\tMENU\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Tambah Contact\t\t\t\t |\n");
    printf("| 2. Tampilkan Contact\t\t\t\t |\n");
    printf("| 3. Edit Contact\t\t\t\t |\n");
    printf("| 4. Hapus Contact\t\t\t\t |\n");
    printf("| 5. Cari Contact\t\t\t\t |\n");
    printf("| 6. Urutkan Contact\t\t\t\t |\n");
    printf("| 7. Save Data Contact\t\t\t\t |\n");
    printf("| 8. Load Data Contact\t\t\t\t |\n");
    printf("| 9. Fungsi Numerik\t\t\t\t |\n");
    printf("| 10. Buat Tabel Relasi\t\t\t\t |\n");
    printf("| 11. Tampilkan Tabel Relasi\t\t\t |\n");
    printf("| 12. Menu Undo \t\t\t\t |\n");
    printf("| 13. Menu Redo \t\t\t\t |\n");
    printf("| 14. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    BukuKontak bukuKontak;
    bukuKontak.jumlah = 0;
    bukuKontak.indeksUndoEdit = 0;
    bukuKontak.indeksRedoEdit = 0;
    bukuKontak.indeksUndoInsert = 0;
    bukuKontak.indeksRedoInsert = 0;
    bukuKontak.indeksUndoDelete = 0;
    bukuKontak.indeksRedoDelete = 0;
    int choice;
    int relasi_kontak[N][N];

    do {
        choice = menu();

        switch (choice) {
            case 1:
                tambahKontak(&bukuKontak);
                break;
            case 2:
                display(&bukuKontak);
                printf("Jumlah kontak %d \n", bukuKontak.jumlah);
                break;
            case 3:
                editKontak(&bukuKontak);
                break;
            case 4:
                menudelete(&bukuKontak);
                break;
            case 5:
                menusearch(&bukuKontak);
                break;
            case 6:
                menusorting(&bukuKontak);
                break;
            case 7:
                save(&bukuKontak,"data.txt");
                break;
            case 8:
                load(&bukuKontak,"data.txt");
                break;
            case 9:
                menunumerik(&bukuKontak);
                break;
            case 10:
                if (bukuKontak.jumlah > 0) {
                    buat_tabel_relasi(relasi_kontak, bukuKontak.kontak, bukuKontak.jumlah);
                    printf("Matriks relasi antar kontak berhasil dibuat!\n");
                } else {
                    printf("Tambahkan daftar kontak terlebih dahulu.\n");
                }
                break;
            case 11:
                if (bukuKontak.jumlah > 0) {
                    tampilkan_tabel_relasi(relasi_kontak, bukuKontak.kontak, bukuKontak.jumlah);
                } else {
                    printf("Tambahkan daftar kontak terlebih dahulu.\n");
                }
                break;
            case 12:
                // Undo
                menuundo(&bukuKontak);
                break;
            case 13:
                // Redo
                menuredo(&bukuKontak);
                break;
            case 14:
                exit(0);
                break;
            default:
                printf("Pilihan Tidak Valid\n");
        }
    } while (choice != 14);

    return 0;
}
