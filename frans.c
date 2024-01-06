#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 31
#define MAX_TELEPHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 31
#define MAX_KONTAK 50

struct Contact_Book {
    char nama[MAX_NAME_LENGTH];
    int umur;
    char jenis_kelamin[2];
    char nomor_telepon[MAX_TELEPHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Contact_Book* next;
};

typedef struct Contact_Book Node;

Node* head = NULL;
Node* undo = NULL;
Node* redo = NULL;
Node* files = NULL;
int numNodes;
int **adjacencyMatrix = NULL; 
char nodes[MAX_KONTAK][MAX_NAME_LENGTH];

void MENU() {
    printf(" --------------------------------------- \n");
    printf("|           MENU BUKU KONTAK            |  \n");
    printf("|---------------------------------------|\n");
    printf("|  1. INPUT KONTAK                      |\n");
    printf("|  2. TAMPILKAN KONTAK                  |\n");
    printf("|  3. CARI KONTAK                       |\n");
    printf("|  4. HAPUS KONTAK                      |\n");
    printf("|  5. SUNTING KONTAK                    |\n");
    printf("|  6. URUTKAN KONTAK                    |\n");
    printf("|  7. TAMBAH RELASI KONTAK              |\n");
    printf("|  8. TAMPILKAN RELASI KONTAK           |\n");
    printf("|  9. SIMPAN KONTAK KE DALAM FILE       |\n");
    printf("|  10.TAMPILKAN KONTAK DARI FILE        |\n");
    printf("|  11.UNDO AKSI TERAKHIR                |\n");
    printf("|  12.REDO SETELAH UNDO                 |\n");
    printf("|  13.KELUAR                            |\n");
    printf(" --------------------------------------- \n\n");
}

Node* inputContactBook(char* nama, int umur, char* jenis_kelamin, char* nomor_telepon, char* email) {
    Node* input = (Node*)malloc(sizeof(Node));
    strcpy(input->nama, nama);
    input->umur = umur;
    strcpy(input->jenis_kelamin, jenis_kelamin);
    strcpy(input->nomor_telepon, nomor_telepon);
    strcpy(input->email, email);
    input->next = NULL;
    return input;
}
void tambahContactBook(char* nama, int umur, char* jenis_kelamin, char* nomor_telepon, char* email) {
    Node* input = inputContactBook(nama, umur, jenis_kelamin, nomor_telepon, email);
    if (head == NULL) {
        head = input;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = input;
    }
}
void tambahContactBook_files(char* nama, int umur, char* jenis_kelamin, char* nomor_telepon, char* email) {
    Node* input = inputContactBook(nama, umur, jenis_kelamin, nomor_telepon, email);
    if (files == NULL) {
        files = input;
    } else {
        Node* current = files;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = input;
    }
}
void input_data() {
    int size;
    printf("=========================================\n");
    printf("            INPUT DATA KONTAK          \n");
    printf("=========================================\n");
    printf("Berapa Kontak yang Ingin Anda Input: ");
    scanf("%d", &size);
    printf("\n");

    for (int i = 0; i < size; i++) {
        char nama[31]; int umur;
        char jenis_kelamin[2];
        char nomor_telepon[15];
        char email[31];

        printf("=========================================\n");
        printf("              KONTAK KE-%d              \n", i + 1);
        printf("=========================================\n");
        printf("NAMA           : ");
        scanf(" %[^\n]", nama);  
        printf("UMUR           : ");
        scanf("%d", &umur);
        printf("JENIS KELAMIN  : ");
        scanf(" %[^\n]", jenis_kelamin);  
        printf("NO. TELEPON    : ");
        scanf(" %[^\n]", nomor_telepon);
        printf("EMAIL          : ");
        scanf(" %[^\n]", email); 

        tambahContactBook(
            nama, umur, jenis_kelamin, nomor_telepon, email);
    }
    system("clear");
    printf("=========================================\n");
    printf("           DATA TELAH DIINPUT\n");
    printf("=====1====================================\n");
    
}

void TAMPILKAN() {
    Node* current = head;
    while (current != NULL) {
        
        printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",
           current->nama, current->umur, current->jenis_kelamin,
           current->nomor_telepon, current->email);
        printf(" -------------------------------------------------------------------------------------------------- \n");
    
        current=current->next;
    }

}
void TAMPILKAN_FILES() {
    Node* current = files;
    while (current != NULL) {
        
        printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",
           current->nama, current->umur, current->jenis_kelamin,
           current->nomor_telepon, current->email);
        printf(" -------------------------------------------------------------------------------------------------- \n");
    
        current=current->next;
    }

}
void TAMPILKAN_NAMA_UMUR_JK() {

    Node* current = head;

    printf("\n ===============================================\n");
    printf("    DAFTAR KONTAK (NAMA, UMUR, JENIS KELAMIN)       \n");
    printf(" ===============================================\n\n");
    printf(" =============================================== \n");
    printf("| %-30s | %-5s | %-4s |\n", "NAMA", "UMUR", "JK");
    printf(" =============================================== \n");       

    while (current != NULL) {
        
        printf("| %-30s | %-5d | %-4s |\n",
           current->nama, current->umur,current->jenis_kelamin);
        printf(" ----------------------------------------------- \n");
    
        current=current->next;
    }

}
void TAMPILKAN_NAMA_NOTEL() {
    Node* current = head;

    printf("\n ==================================================\n");
    printf("        DAFTAR NAMA DAN NOMOR TELEPON KONTAK       \n");
    printf(" ==================================================\n\n");
    printf(" ================================================== \n");
    printf("| %-30s | %-15s |\n", "NAMA", "NO. TELEPON");
    printf(" ================================================== \n");       

    while (current != NULL) {
        
        printf("| %-30s | %-15s |\n",
           current->nama, current->nomor_telepon);
        printf(" -------------------------------------------------- \n");
    
        current=current->next;
    }

}
void TAMPILKAN_NAMA_EMAIL() {

    Node* current = head;

    printf("\n =================================================================\n");
    printf("                   DAFTAR NAMA DAN EMAIL KONTAK                  \n");
    printf(" =================================================================\n\n");
    printf(" ================================================================= \n");
    printf("| %-30s | %-30s |\n", "NAMA", "EMAIL");
    printf(" ================================================================= \n");       

    while (current != NULL) {
        
        printf("| %-30s | %-30s |\n",
           current->nama, current->email);
        printf(" ----------------------------------------------------------------- \n");
    
        current=current->next;
    }

}


int DELETE_NAMA() {
    char nama[MAX_NAME_LENGTH];
    printf("\n=========================================\n");
    printf("   HAPUS DATA KONTAK BERDASARKAN NAMA    \n");
    printf("=========================================\n");
    printf("Masukkan nama kontak : ");
    scanf(" %[^\n]", nama);  

    if (strcmp(head->nama, nama) == 0) {
        Node* first = head;
        head = head->next;
        free(first);
        printf("\n=========================================\n");
        printf("          KONTAK DENGAN NAMA %s \n",nama);
        printf("              TELAH DIHAPUS\n");
        printf("=========================================\n");
        return 1; // Data ditemukan dan dihapus
    }

    Node* cursor = head;
    Node* prevNode = NULL;

    while (cursor != NULL) {
        if (strcmp(cursor->nama, nama) == 0) {
            prevNode->next = cursor->next;
            cursor->next = NULL;
            free(cursor);
            printf("\n=========================================\n");
            printf("          KONTAK DENGAN NAMA %s \n",nama);
            printf("              TELAH DIHAPUS\n");
            printf("=========================================\n");
            return 1; // Data ditemukan dan dihapus
        }
        prevNode = cursor;
        cursor = cursor->next;
    }

    printf("\n=========================================\n");
    printf("           DATA DENGAN NAMA %s \n",nama);
    printf("              TIDAK DITEMUKAN\n");
    printf("=========================================\n");
    return 0; // Data tidak ditemukan
}
int DELETE_UMUR() {
    int umur;
    int ketemu = 0;
    int index = 0;

    printf("\n=========================================\n");
    printf("   HAPUS DATA KONTAK BERDASARKAN UMUR    \n");
    printf("=========================================\n");
    printf("Masukkan umur kontak : ");
    scanf("%d", &umur);

   
    Node* current = head;
    while (current != NULL) {
        if (current->umur == umur) {
            ketemu = ketemu + 1;
        }
        current = current->next;
    }

    if (ketemu == 0) {
        printf("\n=========================================\n");
        printf("           DATA DENGAN UMUR %d \n", umur);
        printf("              TIDAK DITEMUKAN\n");
        printf("=========================================\n");
        return 0; // Data tidak ditemukan
    }

    do {
        Node* cursor = head;
        Node* prevNode = NULL;

        while (cursor != NULL) {
            if (cursor->umur == umur) {
                if (prevNode == NULL) {
                    head = cursor->next;
                } else {
                    prevNode->next = cursor->next;
                }

                cursor->next = NULL;
                free(cursor);
            } else {
                prevNode = cursor;
            }

            cursor = cursor->next;
        }
        index = index + 1;
    } while (index != ketemu);
    printf("\n=========================================\n");
    printf(" KONTAK DENGAN UMUR %d TAHUN SEBANYAK %d\n", umur, ketemu);
    printf("              TELAH DIHAPUS\n");
    printf("=========================================\n");
    return 1; 
}
int DELETE_JK() {
    char jeniskelamin[2];
    int ketemu = 0;
    int index = 0;

    printf("\n=========================================\n");
    printf(" HAPUS KONTAK BERDASARKAN JENIS KELAMIN\n");
    printf("=========================================\n");
    printf("Masukkan jenis kelamin kontak : ");
    scanf(" %[^\n]", jeniskelamin);

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->jenis_kelamin, jeniskelamin) == 0) {
            ketemu = ketemu + 1;
        }
        current = current->next;
    }

    if (ketemu == 0) {
        printf("\n=========================================\n");
        printf("       DATA DENGAN JENIS KELAMIN %s \n", jeniskelamin);
        printf("            TIDAK DITEMUKAN\n");
        printf("=========================================\n");
        return 0; 
    }

    do {
        Node* cursor = head;
        Node* prevNode = NULL;

        while (cursor != NULL) {
            if (strcmp(cursor->jenis_kelamin, jeniskelamin) == 0) {
                if (prevNode == NULL) {
                    head = cursor->next;
                } else {
                    prevNode->next = cursor->next;
                }

                cursor->next = NULL;
                free(cursor);
            } else {
                prevNode = cursor;
            }

            cursor = cursor->next;
        }
        index = index + 1;
    } while (index != ketemu);

    printf("\n=========================================\n");
    printf("KONTAK DNGAN JENIS KELAMIN %s SEBANYAK %d\n", jeniskelamin, ketemu);
    printf("              TELAH DIHAPUS\n");
    printf("=========================================\n");
    return 1; 
}
int DELETE_NOTEL() {
    char nomorTelepon[15];
    printf("\n=========================================\n");
    printf(" HAPUS KONTAK BERDASARKAN NOMOR TELEPON         \n");
    printf("=========================================\n");
    printf("Masukkan nomor telepon kontak : ");
    scanf(" %[^\n]", nomorTelepon);

     if (strcmp(head->nomor_telepon, nomorTelepon) == 0) {
        Node* first = head;
        head = head->next;
        first->next = NULL;
        free(first);
        printf("\n=========================================\n");
        printf("  KONTAK DENGAN NOMOR TELEPON %s \n",nomorTelepon);
        printf("              TELAH DIHAPUS\n");
        printf("=========================================\n");
        return 1; 
    }

    Node* cursor = head;
    Node* prevNode = NULL;

    while (cursor != NULL) {
        if (strcmp(cursor->nomor_telepon, nomorTelepon) == 0) {
            prevNode->next = cursor->next;
            cursor->next = NULL;
            free(cursor);
            printf("\n=========================================\n");
            printf("  KONTAK DENGAN NOMOR TELEPON %s \n",nomorTelepon);
            printf("              TELAH DIHAPUS\n");
            printf("=========================================\n");
            return 1; 
        }
        prevNode = cursor;
        cursor = cursor->next;
    }

    printf("\n=========================================\n");
    printf("    KONTAK DENGAN NOMOR TELEPON %s \n",nomorTelepon);
    printf("              TIDAK DITEMUKAN\n");
    printf("=========================================\n");
    return 0; 
}
int DELETE_EMAIL() {
    char email[50];
    printf("\n=========================================\n");
    printf("   HAPUS DATA KONTAK BERDASARKAN EMAIL          \n");
    printf("=========================================\n");
    printf("Masukkan email kontak: ");
    scanf(" %[^\n]", email);

    if (strcmp(head->email, email) == 0) {
        Node* first = head;
        head = head->next;
        first->next = NULL;
        free(first);
        printf("\n=========================================\n");
        printf("     KONTAK DENGAN EMAIL %s \n",email);
        printf("              TELAH DIHAPUS\n");
        printf("=========================================\n");
        return 1; 
    }

    Node* cursor = head;
    Node* prevNode = NULL;

    while (cursor != NULL) {
        if (strcmp(cursor->email, email) == 0) {
            prevNode->next = cursor->next;
            cursor->next = NULL;
            free(cursor);
            printf("\n=========================================\n");
            printf("     KONTAK DENGAN EMAIL %s \n",email);
            printf("              TELAH DIHAPUS\n");
            printf("=========================================\n");
            return 1; 
        }
        prevNode = cursor;
        cursor = cursor->next;
    }

    printf("\n=========================================\n");
    printf("        KONTAK DENGAN EMAIL %s \n",email);
    printf("              TIDAK DITEMUKAN\n");
    printf("=========================================\n");
    return 0; 
}
void DELETE_SEMUA() {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    head = NULL;
    printf("\n=========================================\n");
    printf("       SEMUA KONTAK TELAH DIHAPUS       \n");
    printf("=========================================\n");
}

void TERKECIL() {
    int kecil = head->umur;
    Node* contact = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->umur < kecil) {
            kecil = current->umur;
            contact = current;
        }
        current = current->next;
    }

    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                  DATA KONTAK DENGAN UMUR TERMUDA                                 \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");

    Node* cek = head;
    while (cek != NULL) {
        if (cek->umur == contact->umur) {
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n", cek->nama, cek->umur, cek->jenis_kelamin,cek->nomor_telepon, cek->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
        }
        cek = cek->next;
    }
}
void TERBESAR() {
    int besar = head->umur;
    Node* contact = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->umur > besar) {
            besar = current->umur;
            contact = current;
        }
        current = current->next;
    }

    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                   DATA KONTAK DENGAN UMUR TERTUA                                 \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    Node* cek = head;
    while (cek != NULL) {
        if (cek->umur == contact->umur) {
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n", cek->nama, cek->umur, cek->jenis_kelamin,cek->nomor_telepon, cek->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
        }
        cek = cek->next;
    }
}
void RERATA() {
    int jumlah = 0;
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        jumlah += current->umur;
        count++;
        current = current->next;
    }

    float rata2 = (float)jumlah / count;

    printf("\n=========================================\n");
    printf("  RATA-RATA UMUR KONTAK :  %.2f TAHUN\n", rata2);
    printf("=========================================\n\n");
}

Node* CARI_NAMA(Node* head) {
    char search[31];
    printf("Masukkan nama kontak : ");
    scanf(" %[^\n]", search);

    Node* current = head;
    while (current != NULL && strcmp(search, current->nama) != 0) {
        current = current->next;
    }

    if (current != NULL && strcmp(search, current->nama) == 0) {
        system("clear");
        printf(" ================================================================================================== \n");
        printf("                              DATA KONTAK DENGAN NAMA %s \n", search);
        printf(" ================================================================================================== \n\n");
        printf(" ================================================================================================== \n");
        printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
        printf(" ================================================================================================== \n");

        printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
        printf(" -------------------------------------------------------------------------------------------------- \n");
    

    } else {
        printf("\n=========================================\n");
        printf("    DATA KONTAK DENGAN NAMA %s \n", search);
        printf("              TIDAK DITEMUKAN     \n");
        printf("=========================================\n");
        return NULL;
    }

    return current; 
}
Node* CARI_UMUR(Node* head) {
    int search;
    int ketemu;
    ketemu=0;
    printf("Masukkan umur kontak : ");
    scanf("%d", &search);

    Node* current = head;
    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                  DATA KONTAK DENGAN UMUR %d TAHUN                        \n", search);
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");

    do{
        if (current->umur==search){
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
            ketemu=ketemu+1;
        }
        current=current->next;
        
    } while (current != NULL);
    
     if (ketemu==0) {
        system("clear");
        printf("\n=========================================\n");
        printf("    DATA KONTAK DENGAN UMUR %d TAHUN \n", search);
        printf("             TIDAK DITEMUKAN           \n");
        printf("=========================================\n");
        return NULL;
    }

    return head; 
}
Node* CARI_JK(Node* head) {
    char search[2];
    int ketemu = 0;
    printf("Masukkan jenis kelamin kontak : ");
    scanf(" %[^\n]", search);
    search[0] = toupper(search[0]); 
    Node* current = head;
    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                  DATA KONTAK DENGAN JENIS KELAMIN %s                     \n", search);
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");

    do {
        current->jenis_kelamin[0] = toupper(current->jenis_kelamin[0]); 
        if (strcmp(current->jenis_kelamin, search) == 0) {
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
            ketemu=ketemu+1;
        }
        current=current->next;
        
    } while (current != NULL);

    if (ketemu == 0) {
        system("clear");
        printf("\n=========================================\n");
        printf("       DATA KONTAK JENIS KELAMIN %s \n", search);
        printf("             TIDAK DITEMUKAN           \n");
        printf("=========================================\n");
        return NULL;
    }

    return head;
}
Node* CARI_NOTEL(Node * head) {
    char search[15];
    printf("Masukkan nomor telepon kontak : ");
    scanf(" %[^\n]", search);
    
    Node* current = head;
    while (current != NULL && strcmp(search, current->nomor_telepon) != 0) {
        current = current->next;
    }

    if (current != NULL && strcmp(search, current->nomor_telepon) == 0) {
        system("clear");
        printf(" ================================================================================================== \n");
        printf("                         DATA KONTAK DENGAN NOMOR TELEPON %s \n", search);
        printf(" ================================================================================================== \n\n");
        printf(" ================================================================================================== \n");
        printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
        printf(" ================================================================================================== \n");

        printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
        printf(" -------------------------------------------------------------------------------------------------- \n");

    } else {
        printf("\n=========================================\n");
        printf("KONTAK DENGAN NOMOR TELEPON %s \n", search);
        printf("             TIDAK DITEMUKAN     \n");
        printf("=========================================\n");
        return NULL;
    }

    return current; 
}
Node* CARI_EMAIL(Node* head) {
    char search[31];
    printf("Masukkan email kontak : ");
    scanf(" %[^\n]", search);

    Node* current = head;
    while (current != NULL && strcmp(search, current->email) != 0) {
        current = current->next;
    }

    if (current != NULL && strcmp(search, current->email) == 0) {
        system("clear");
        printf(" ================================================================================================== \n");
        printf("                           DATA KONTAK DENGAN EMAIL %s \n", search);
        printf(" ================================================================================================== \n\n");
        printf(" ================================================================================================== \n");
        printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
        printf(" ================================================================================================== \n");

        printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
        printf(" -------------------------------------------------------------------------------------------------- \n");


    } else {
        printf("\n=========================================\n");
        printf("   DATA KONTAK DENGAN EMAIL %s \n", search);
        printf("           TIDAK DITEMUKAN     \n");
        printf("=========================================\n");
        return NULL;
    }

    return current; 
}
Node* CARI_UMUR_JK_AND(Node* head) {
    int search_umur;
    char search_jk[2];
    int ketemu = 0;

    printf("Masukkan umur kontak: ");
    scanf("%d", &search_umur);

    printf("Masukkan jenis kelamin kontak: ");
    scanf(" %[^\n]", search_jk);
    search_jk[0] = toupper(search_jk[0]); 
    Node* current = head;
    
    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                  DATA KONTAK DENGAN UMUR %d TAHUN                     \n", search_umur);
    printf("                                        DAN JENIS KELAMIN %s                     \n", search_jk);
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");


    do {
        current->jenis_kelamin[0] = toupper(current->jenis_kelamin[0]); 
        if (current->umur == search_umur && strcmp(current->jenis_kelamin, search_jk) == 0) {
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
            ketemu=ketemu+1;
        }
        current=current->next;
        
    } while (current != NULL);

    if (ketemu == 0) {
        system("clear");
        printf("\n=========================================\n");
        printf("   DATA KONTAK JENIS UMUR %d TAHUN DAN \n", search_umur);
        printf("     JENIS KELAMIN %s TIDAK DITEMUKAN           \n",search_jk);
        printf("=========================================\n");
        return NULL;
    }

    return head;
}
Node* CARI_UMUR_JK_OR(Node* head) {
    int search_umur;
    char search_jk[2];
    int ketemu = 0;

    printf("Masukkan umur kontak: ");
    scanf("%d", &search_umur);

    printf("Masukkan jenis kelamin kontak: ");
    scanf(" %[^\n]", search_jk);
    search_jk[0] = toupper(search_jk[0]); 
    Node* current = head;
    
    system("clear");
    printf(" ================================================================================================== \n");
    printf("                                  DATA KONTAK DENGAN UMUR %d TAHUN                     \n", search_umur);
    printf("                                       ATAU JENIS KELAMIN %s                     \n", search_jk);
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");

    do {
        current->jenis_kelamin[0] = toupper(current->jenis_kelamin[0]); 
        if (current->umur == search_umur || strcmp(current->jenis_kelamin, search_jk) == 0) {
            printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",current->nama, current->umur, current->jenis_kelamin,current->nomor_telepon, current->email);
            printf(" -------------------------------------------------------------------------------------------------- \n");
            ketemu=ketemu+1;
        }
        current=current->next;
        
    } while (current != NULL);

    if (ketemu == 0) {
        system("clear");
        printf("\n=========================================\n");
        printf("   DATA KONTAK JENIS UMUR %d TAHUN ATAU \n", search_umur);
        printf("     JENIS KELAMIN %s TIDAK DITEMUKAN           \n",search_jk);
        printf("=========================================\n");
        return NULL;
    }

    return head;
}

void headertable() {
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
}
void hasilsearch(Node* contact) {
    printf("| %-30s | %-5d | %-4s | %-15s | %-30s |\n",
           contact->nama, contact->umur, contact->jenis_kelamin,
           contact->nomor_telepon, contact->email);
    printf(" -------------------------------------------------------------------------------------------------- \n");
}
int searchWildcard_nama_end() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Nama Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    int targetLen = strlen(target);
    for (Node* current = head; current != NULL; current = current->next) {
        int contactLen = strlen(current->nama);
        if (contactLen >= targetLen) {
            cocok = 1;
            for (int j = 0; j < targetLen; j++) {
                if (target[j] != current->nama[contactLen - targetLen + j]) {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(current);
                
            }
        }
    }
    return found;
}
int searchWildcard_notel_end() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Nomor Telepon Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    int targetLen = strlen(target);
    for (Node* current = head; current != NULL; current = current->next) {
        int contactLen = strlen(current->nomor_telepon);
        if (contactLen >= targetLen) {
            cocok = 1;
            for (int j = 0; j < targetLen; j++) {
                if (target[j] != current->nomor_telepon[contactLen - targetLen + j]) {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(current);
            }
        }
    }
    return found;
}
int searchWildcard_email_end() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Email Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    int targetLen = strlen(target);
    for (Node* current = head; current != NULL; current = current->next) {
        int contactLen = strlen(current->email);
        if (contactLen >= targetLen) {
            cocok = 1;
            for (int j = 0; j < targetLen; j++) {
                if (target[j] != current->email[contactLen - targetLen + j]) {
                    cocok = 0;
                    break;
                }
            }
            if (cocok != 0) {
                found++;
                hasilsearch(current);
            }
        }
    }
    return found;
}
int searchWildcard_nama_first() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Nama Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    for (Node* current = head; current != NULL; current = current->next) {
        cocok = 1;
        for (int j = 0; j < strlen(target); j++) {
            if (target[j] != current->nama[j]) {
                cocok = 0;
                break;
            }
        }
        if (cocok != 0) {
            found++;
            hasilsearch(current);
        }
    }
    return found;
}
int searchWildcard_notel_first() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Nomor Telepon Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    for (Node* current = head; current != NULL; current = current->next) {
        cocok = 1;
        for (int j = 0; j < strlen(target); j++) {
            if (target[j] != current->nomor_telepon[j]) {
                cocok = 0;
                break;
            }
        }
        if (cocok != 0) {
            found++;
            hasilsearch(current);
        }
    }
    return found;
}
int searchWildcard_email_first() {
    int found = 0, cocok = 0;
    char target[30];

    printf("\nMasukkan Email Kontak : ");
    scanf(" %[^\n]", target);

    headertable();

    for (Node* current = head; current != NULL; current = current->next) {
        cocok = 1;
        for (int j = 0; j < strlen(target); j++) {
            if (target[j] != current->email[j]) {
                cocok = 0;
                break;
            }
        }
        if (cocok != 0) {
            found++;
            hasilsearch(current);
        }
    }
    return found;
}
void MENUWILDCARD(){
    int choice;
    int pilih;
    int wildcard;
    do {
    
        printf(" ---------------------------------------\n");
        printf("|          MENU SEARCH WILDCARD         |\n");
        printf(" ---------------------------------------\n");
        printf("| 1. Berdasarkan Nama                   |\n");
        printf("| 2. Berdasarkan Nomor Telepon          |\n");
        printf("| 3. Berdasarkan Email                  |\n");
        printf("| 4. BATAL                              |\n");
        printf(" ---------------------------------------\n");
        printf(" Pilihan : ");
        scanf("%d", &choice);
        
        
        switch (choice) {
        case 1:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| PILIH Search Wilcard Nama :           |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Beberapa Karakter di Depan         |\n");
                printf("|    Contoh : Fr (mencari Frans)        |\n");
                printf("| 2. Beberapa Karakter di Belakang      |\n");
                printf("|    Contoh : tra (mencari Putra)       |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");
                printf(" ================================================================================================== \n");
                printf("                                  SEARCH WILDCARD BERDASARKAN NAMA                                 \n");
                printf(" ================================================================================================== \n");

                switch (pilih) {
                    case 1:
                        wildcard=searchWildcard_nama_first();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                            
                            break;}
                        return;
                        break;
                    case 2:
                        wildcard=searchWildcard_nama_end();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                            break;}
                        return;
                        break;
                    case 3:
                        system("clear");
                        return;
                        break;
                    default:
                        printf("=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            break; 
            
        case 2:
            
            do {
     
                printf(" --------------------------------------- \n");
                printf("| PILIH Search Wilcard Nomor Telepon :  |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Beberapa Karakter di Depan         |\n");
                printf("|    Contoh : 081 (mencari 08123423421) |\n");
                printf("| 2. Beberapa Karakter di Belakang      |\n");
                printf("|    Contoh : 123 (mencari 08123423123) |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");
                printf(" ================================================================================================== \n");
                printf("                             SEARCH WILDCARD BERDASARKAN NOMOR TELEPON                                 \n");
                printf(" ================================================================================================== \n");

                switch (pilih) {
                    case 1:
                        wildcard=searchWildcard_notel_first();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                        
                            break;}
                        return;
                        break;
                    case 2:
                        wildcard=searchWildcard_notel_end();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                            break;}
                        return;
                        break;
                    case 3:
                        system("clear");
                        return;
                        break;
                    default:
                        printf("=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            break; 
        case 3:
            
            do {
     
                printf(" --------------------------------------- \n");
                printf("| PILIH Search Wilcard Email:           |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Beberapa Karakter di Depan         |\n");
                printf("|    Contoh : put (mencari putra@gmail) |\n");
                printf("| 2. Beberapa Karakter di Belakang      |\n");
                printf("|    Contoh : com (mencari p@gmail.com) |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");
                printf(" ================================================================================================== \n");
                printf("                                 SEARCH WILDCARD BERDASARKAN EMAIL                                 \n");
                printf(" ================================================================================================== \n");

                switch (pilih) {
                    case 1:
                        wildcard=searchWildcard_email_first();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                            break;}
                        return;
                        break;
                    case 2:
                        wildcard=searchWildcard_email_end();
                        if (wildcard==0){
                            system("clear");
                            printf("=========================================\n");
                            printf("          DATA TIDAK DITEMUKAN   \n");
                            printf("=========================================\n\n");
                            break;}
                        return;
                        break;
                    case 3:
                        system("clear");
                        return;
                        break;
                    default:
                        printf("=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            break; 
            
        case 4:
            system("clear");
            break;
            
        default:
            printf("\n=========================================\n");
            printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
            printf("=========================================\n\n");
                        
            break;
    }
    } while (choice != 4);
}
void displaySearchResults() {
    headertable();

    for (Node* current = head; current != NULL; current = current->next) {
        hasilsearch(current);
    }
}
void displayContact(Node* contact) {
    headertable();  
    hasilsearch(contact);
}

int EDIT_NAMA(Node* head) {
    char tempNama[31];
    char nama[31];
    int tempUmur;
    char tempJenis_Kelamin[2];
    char tempNomor_Telepon[15];
    char tempEmail[31];

    printf("=========================================\n");
    printf("     SUNTING KONTAK BERDASARKAN NAMA    \n");
    printf("=========================================\n");

    Node* current = CARI_NAMA(head); 

    if (current != NULL) {
        // Lakukan penyuntingan
        printf("\nLakukan Penyuntingan:\n");
        printf("NAMA           : ");
        scanf("%s", tempNama);
        printf("UMUR           : ");
        scanf("%d", &tempUmur);
        printf("JENIS KELAMIN  : ");
        scanf("%s", tempJenis_Kelamin);
        printf("NO. TELEPON    : ");
        scanf("%s", tempNomor_Telepon);
        printf("EMAIL          : ");
        scanf("%s", tempEmail);

        // Update data
        strcpy(current->nama, tempNama);
        current->umur = tempUmur;
        strcpy(current->jenis_kelamin, tempJenis_Kelamin);
        strcpy(current->nomor_telepon, tempNomor_Telepon);
        strcpy(current->email, tempEmail);
        system("clear");
        printf("\n=========================================\n");
        printf("        KONTAK BERHASIL DISUNTING        \n");
        printf("=========================================\n");
        printf("NAMA           : %s\n", current->nama);
        printf("UMUR           : %d\n", current->umur);
        printf("JENIS KELAMIN  : %s\n", current->jenis_kelamin);
        printf("NOMOR TELEPON  : %s\n", current->nomor_telepon);
        printf("EMAIL          : %s\n", current->email);
        printf("=========================================\n\n");
        return 1;

    } else {
        printf("=========================================\n");
        printf("            PENYUNTINGAN GAGAL        \n");
        printf("=========================================\n");
        return 0;
    }
}
int EDIT_NOTEL(Node* head) {
    char tempNama[31];
    char nomor_telepon[15];
    int tempUmur;
    char tempJenis_Kelamin[2];
    char tempNomor_Telepon[15];
    char tempEmail[31];
    printf("=========================================\n");
    printf(" SUNTING KONTAK BERDASARKAN NOMOR TELEPON\n");
    printf("=========================================\n");

    Node* current = CARI_NOTEL(head);

    if (current != NULL) {
        // Lakukan penyuntingan
        printf("\nLakukan Penyuntingan:\n");
        printf("NAMA           : ");
        scanf("%s", tempNama);
        printf("UMUR           : ");
        scanf("%d", &tempUmur);
        printf("JENIS KELAMIN  : ");
        scanf("%s", tempJenis_Kelamin);
        printf("NO. TELEPON    : ");
        scanf("%s", tempNomor_Telepon);
        printf("EMAIL          : ");
        scanf("%s", tempEmail);

        // Update data
        strcpy(current->nama, tempNama);
        current->umur = tempUmur;
        strcpy(current->jenis_kelamin, tempJenis_Kelamin);
        strcpy(current->nomor_telepon, tempNomor_Telepon);
        strcpy(current->email, tempEmail);
        system("clear");
        printf("\n=========================================\n");
        printf("        KONTAK BERHASIL DISUNTING        \n");
        printf("=========================================\n");
        printf("NAMA           : %s\n", current->nama);
        printf("UMUR           : %d\n", current->umur);
        printf("JENIS KELAMIN  : %s\n", current->jenis_kelamin);
        printf("NOMOR TELEPON  : %s\n", current->nomor_telepon);
        printf("EMAIL          : %s\n", current->email);
        printf("=========================================\n\n");
        return 1;

    } else {
        printf("=========================================\n");
        printf("            PENYUNTINGAN GAGAL        \n");
        printf("=========================================\n");
        return 0;
    }
}
int EDIT_EMAIL(Node* head) {
    char tempNama[31];
    char email[31]; 
    int tempUmur;
    char tempJenis_Kelamin[2];
    char tempNomor_Telepon[15];
    char tempEmail[31];
    
    printf("=========================================\n");
    printf("     SUNTING KONTAK BERDASARKAN EMAIL    \n");
    printf("=========================================\n");

    Node* current = CARI_EMAIL(head);

    if (current != NULL) {
        // Lakukan penyuntingan
        printf("\nLakukan Penyuntingan:\n");
        printf("NAMA           : ");
        scanf("%s", tempNama);
        printf("UMUR           : ");
        scanf("%d", &tempUmur);
        printf("JENIS KELAMIN  : ");
        scanf("%s", tempJenis_Kelamin);
        printf("NO. TELEPON    : ");
        scanf("%s", tempNomor_Telepon);
        printf("EMAIL          : ");
        scanf("%s", tempEmail);

        // Update data
        strcpy(current->nama, tempNama);
        current->umur = tempUmur;
        strcpy(current->jenis_kelamin, tempJenis_Kelamin);
        strcpy(current->nomor_telepon, tempNomor_Telepon);
        strcpy(current->email, tempEmail);
        system("clear");
        printf("\n=========================================\n");
        printf("        KONTAK BERHASIL DISUNTING        \n");
        printf("=========================================\n");
        printf("NAMA           : %s\n", current->nama);
        printf("UMUR           : %d\n", current->umur);
        printf("JENIS KELAMIN  : %s\n", current->jenis_kelamin);
        printf("NOMOR TELEPON  : %s\n", current->nomor_telepon);
        printf("EMAIL          : %s\n", current->email);
        printf("=========================================\n\n");
        return 1;

    } else {
        printf("=========================================\n");
        printf("            PENYUNTINGAN GAGAL        \n");
        printf("=========================================\n");
        return 0;
    }
}

void swapData(Node* node1, Node* node2) {
    char tempNama[31];
    int tempUmur;
    char tempJenis_Kelamin[2];
    char tempNomor_Telepon[15];
    char tempEmail[31];

    strcpy(tempNama, node1->nama);
    tempUmur = node1->umur;
    strcpy(tempJenis_Kelamin, node1->jenis_kelamin);
    strcpy(tempNomor_Telepon, node1->nomor_telepon);
    strcpy(tempEmail, node1->email);

    strcpy(node1->nama, node2->nama);
    node1->umur = node2->umur;
    strcpy(node1->jenis_kelamin, node2->jenis_kelamin);
    strcpy(node1->nomor_telepon, node2->nomor_telepon);
    strcpy(node1->email, node2->email);

    strcpy(node2->nama, tempNama);
    node2->umur = tempUmur;
    strcpy(node2->jenis_kelamin, tempJenis_Kelamin);
    strcpy(node2->nomor_telepon, tempNomor_Telepon);
    strcpy(node2->email, tempEmail);
}
void URUTKAN_NAMA_MENAIK() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->nama, current->nama) < 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }
    printf(" ================================================================================================== \n");
    printf("                                 DATA TELAH DIURUTKAN SECARA MENAIK\n");
    printf("                                          BERDASARKAN NAMA                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_UMUR_MENAIK() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (temp->umur < current->umur) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                 DATA TELAH DIURUTKAN SECARA MENAIK\n");
    printf("                                          BERDASARKAN UMUR                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_JK_MENAIK() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->jenis_kelamin, current->jenis_kelamin) < 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                 DATA TELAH DIURUTKAN SECARA MENAIK\n");
    printf("                                      BERDASARKAN JENIS KELAMIN                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_NOTEL_MENAIK() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->nomor_telepon, current->nomor_telepon) < 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                 DATA TELAH DIURUTKAN SECARA MENAIK\n");
    printf("                                       BERDASARKAN NOMOR TELEPON                                      \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_EMAIL_MENAIK() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->email, current->email) < 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                 DATA TELAH DIURUTKAN SECARA MENAIK\n");
    printf("                                          BERDASARKAN EMAIL                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_NAMA_MENURUN() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->nama, current->nama) > 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                DATA TELAH DIURUTKAN SECARA MENURUN\n");
    printf("                                          BERDASARKAN NAMA                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_UMUR_MENURUN() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (temp->umur > current->umur) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                DATA TELAH DIURUTKAN SECARA MENURUN\n");
    printf("                                          BERDASARKAN UMUR                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_JK_MENURUN() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->jenis_kelamin, current->jenis_kelamin) > 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                DATA TELAH DIURUTKAN SECARA MENURUN\n");
    printf("                                      BERDASARKAN JENIS KELAMIN                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_NOTEL_MENURUN() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->nomor_telepon, current->nomor_telepon) > 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                DATA TELAH DIURUTKAN SECARA MENURUN\n");
    printf("                                     BERDASARKAN NOMOR TELEPON                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}
void URUTKAN_EMAIL_MENURUN() {
    Node* current;
    Node* temp;

    for (current = head; current != NULL; current = current->next) {
        for (temp = current->next; temp != NULL; temp = temp->next) {
            if (strcmp(temp->email, current->email) > 0) {
                // Swap data
                swapData(current, temp);
            }
        }
    }

    printf(" ================================================================================================== \n");
    printf("                                DATA TELAH DIURUTKAN SECARA MENURUN\n");
    printf("                                          BERDASARKAN EMAIL                                       \n");
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    
    TAMPILKAN();
}

void saveToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("=========================================\n");
        printf("          TIDAK DAPAT DISIMPAN     \n");
        printf("    GAGAL MEMBUKA FILE UNTUK DITULIS     \n");
        printf("=========================================\n\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(file, "| %-30s | %-4d | %-2s | %-15s | %-30s |\n", current->nama, current->umur, current->jenis_kelamin, current->nomor_telepon, current->email);
        current = current->next;
    }
    fclose(file);
    printf("\n=========================================\n");
    printf("          DATA BERHASIL DISIMPAN           \n");
    printf("         KE DALAM FILE '%s'.\n", filename);
    printf("=========================================\n\n");
}
void loadFromFile(const char* filename) {
    while (files != NULL) {
        Node* temp = files;
        files = files->next;
        free(temp);
    }
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n=========================================\n");
        printf("              FILE TIDAK ADA     \n");
        printf("=========================================\n\n");
        return;
    }

    char nama[MAX_NAME_LENGTH];
    int umur;
    char jenis_kelamin[2];
    char nomor_telepon[MAX_TELEPHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    while (fscanf(file, "| %29[^|] | %d | %1[^|] | %14[^|] | %29[^|] |\n", nama, &umur, jenis_kelamin, nomor_telepon, email) == 5) {
        tambahContactBook_files(nama, umur, jenis_kelamin, nomor_telepon, email);
    }

    fclose(file);
    printf(" ================================================================================================== \n");
    printf("                                BERHASIL DIMUAT DARI FILE '%s'.\n",filename);
    printf(" ================================================================================================== \n\n");
    printf(" ================================================================================================== \n");
    printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
    printf(" ================================================================================================== \n");
    TAMPILKAN_FILES();
}
void copyContactBook(Node* source, Node** destination) {
    
    while (source != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Gagal mengalokasikan memori.\n");
            exit(EXIT_FAILURE); 
        }

        strcpy(newNode->nama, source->nama);
        newNode->umur = source->umur;
        strcpy(newNode->jenis_kelamin, source->jenis_kelamin);
        strcpy(newNode->nomor_telepon, source->nomor_telepon);
        strcpy(newNode->email, source->email);
        newNode->next = NULL;

        if (*destination == NULL) {
            *destination = newNode;
        } else {
            Node* current = *destination;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        source = source->next;
    }
}
void MENU2() {
   int pilihan;
   int pilih;
   Node* cari;
   if (head == NULL) {
        printf("\n=========================================\n");
        printf("           BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
   
    do {
    
        printf(" --------------------------------------- \n");
        printf("| Tampilkan:                            |\n");
        printf("|---------------------------------------|\n");
        printf("| 1. Seluruh Kontak                     |\n");
        printf("| 2. Kontak dengan Atribut Tertentu     |\n");
        printf("| 3. BATAL                              |\n");
        printf(" --------------------------------------- \n");
    
        printf("Pilihan: ");
        scanf("%d", &pilihan);
    
    
    system("clear");
    switch (pilihan) {
        case 1:
            printf(" ================================================================================================== \n");
            printf("                                       DAFTAR SELURUH KONTAK                                        \n");
            printf(" ================================================================================================== \n\n");
            printf(" ================================================================================================== \n");
            printf("| %-30s | %-5s | %-4s | %-15s | %-30s |\n", "NAMA", "UMUR", "JK", "NO. TELEPON", "EMAIL");
            printf(" ================================================================================================== \n");

            TAMPILKAN();
            return;
            break;
        case 2:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Tampilkan                             |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Nama, Umur, & Jenis Kelamin Kontak |\n");
                printf("| 2. Nama dan Nomor Telepon Kontak      |\n");
                printf("| 3. Nama dan Email Kontak              |\n");
                printf("| 4. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        TAMPILKAN_NAMA_UMUR_JK();
                        return;
                        break;
                    case 2:
                        TAMPILKAN_NAMA_NOTEL();
                        return;
                        break;
                    case 3:
                        TAMPILKAN_NAMA_EMAIL();
                        return;
                        break;
                    case 4:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 5);
            return;
            break; 
        
        case 3:
            break;
            
        default:
            printf("\n=========================================\n");
            printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
            printf("=========================================\n\n");
                        
            break;
    }
    } while (pilihan != 3);
}
void MENU3() {
   int pilihan;
   Node* cari;
   if (head == NULL) {
        printf("\n=========================================\n");
        printf("           BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
   
    do {
    
        printf(" --------------------------------------- \n");
        printf("| Pilih Operasi Pencarian:              |\n");
        printf("|---------------------------------------|\n");
        printf("| 1. Berdasarkan Nama                   |\n");
        printf("| 2. Berdasarkan Umur                   |\n");
        printf("| 3. Berdasarkan Jenis Kelamin          |\n");
        printf("| 4. Berdasarkan Nomor Telepon          |\n");
        printf("| 5. Berdasarkan Email                  |\n");
        printf("| 6. Berdasarkan Umur AND Jenis Kelamin |\n");
        printf("| 7. Berdasarkan Umur OR Jenis Kelamin  |\n");
        printf("| 8. Kontak Dengan Umur Termuda         |\n");
        printf("| 9. Kontak Dengan Umur Tertua          |\n");
        printf("| 10.Rata-Rata Umur Kontak              |\n");
        printf("| 11.Pencarian Wildcard                 |\n");
        printf("|    Brdasarkan Bberapa Karakter String |\n");
        printf("| 12.BATAL                              |\n");
        printf(" --------------------------------------- \n");
    
        printf("Pilihan: ");
        scanf("%d", &pilihan);
    
    
    system("clear");
    switch (pilihan) {
        case 1:
            printf("\n=========================================\n");
            printf("    CARI DATA KONTAK BERDASARKAN NAMA    \n");
            printf("=========================================\n\n");
            cari=CARI_NAMA(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 2:
            printf("\n=========================================\n");
            printf("    CARI DATA KONTAK BERDASARKAN UMUR    \n");
            printf("=========================================\n\n");
            cari=CARI_UMUR(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 3:
            printf("\n=========================================\n");
            printf("  CARI KONTAK BERDASARKAN JENIS KELAMIN  \n");
            printf("=========================================\n\n");
            cari=CARI_JK(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 4:
            printf("\n=========================================\n");
            printf("  CARI KONTAK BERDASARKAN NOMOR TELEPON  \n");
            printf("=========================================\n\n");
            cari=CARI_NOTEL(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 5:
            printf("\n=========================================\n");
            printf("    CARI DATA KONTAK BERDASARKAN EMAIL   \n");
            printf("=========================================\n\n");
            cari=CARI_EMAIL(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 6:
            printf("\n=========================================\n");
            printf("CARI KONTAK MENURUT UMUR & JENIS KELAMIN   \n");
            printf("=========================================\n\n");
            cari=CARI_UMUR_JK_AND(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 7:
            printf("\n=========================================\n");
            printf("CARI KONTAK MENURUT UMUR & JENIS KELAMIN   \n");
            printf("=========================================\n\n");
            cari=CARI_UMUR_JK_OR(head);
            if (cari==NULL){
                break;
            } else {
                return;
                break;
            }
        case 8:
            TERKECIL();
            return;
            break;
            
        case 9:
            TERBESAR();
            return;
            break;
            
        case 10:
            RERATA();
            return;
            break;
            
        case 11:
            printf("\n=========================================\n");
            printf("           PENCARIAN WILDCARD           \n");
            printf("   BERDASARKAN BEBERAPA KARAKTER STRING   \n");
            printf("=========================================\n");
            MENUWILDCARD();
            return;
            break;  
            
        case 12:
            break;
            
        default:
            printf("\n=========================================\n");
            printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
            printf("=========================================\n\n");
                        
            break;
    }
    } while (pilihan != 12);
}
void MENU4() {
   int pilihan;
   int delete;
   if(head==NULL){
        printf("\n=========================================\n");
        printf("            BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
    do {
     
    printf(" --------------------------------------- \n");
    printf("| Pilih operasi penghapusan:            |\n");
    printf("|---------------------------------------|\n");
    printf("| 1.Hapus Berdasarkan Nama              |\n");
    printf("| 2.Hapus Berdasarkan Umur              |\n");
    printf("| 3.Hapus Berdasarkan Jenis Kelamin     |\n");
    printf("| 4.Hapus Berdasarkan Nomor Telepon     |\n");
    printf("| 5.Hapus Berdasarkan Email             |\n");
    printf("| 6.Hapus Semua Kontak                  |\n");
    printf("| 7.BATAL                               |\n");
    printf(" --------------------------------------- \n");
    
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    system("clear");

    switch (pilihan) {
        case 1:
            delete=DELETE_NAMA();
            if (delete==1){
                return;
                break;
            }
            break;
        case 2:
            delete=DELETE_UMUR();
            if (delete==1){
                return;
                break;
            }
            break;
        case 3:
            delete=DELETE_JK();
            if (delete==1){
                return;
                break;
            }
            break;
        case 4:
            delete=DELETE_NOTEL();
            if (delete==1){
                return;
                break;
            }
            break;
        case 5:
            delete=DELETE_EMAIL();
            if (delete==1){
                return;
                break;
            }
            break;
        case 6:
            DELETE_SEMUA();
            return;
            break;
        case 7:
            break;
        default:
            printf("\n=========================================\n");
            printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
            printf("=========================================\n\n");
                        
            break;
        }
    }while (pilihan != 7);

}
void MENU5() {
   int pilihan;
   int edit;
   if(head==NULL){
        printf("\n=========================================\n");
        printf("            BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
    do {
     
    printf(" --------------------------------------- \n");
    printf("| Pilih operasi penyuntingan:           |\n");
    printf("|---------------------------------------|\n");
    printf("| 1.Sunting Berdasarkan Nama            |\n");
    printf("| 2.Sunting Berdasarkan Nomor Telepon   |\n");
    printf("| 3.Sunting Berdasarkan Email           |\n");
    printf("| 4.BATAL                               |\n");
    printf(" --------------------------------------- \n");
    
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    system("clear");

    switch (pilihan) {
        case 1:
            edit=EDIT_NAMA(head);
            if (edit==1){
                return;
                break;
            }else{
                break;
            }
        case 2:
            edit=EDIT_NOTEL(head);
            if (edit==1){
                return;
                break;
            }else{
                break;
            }
        case 3:
            edit=EDIT_EMAIL(head);
            if (edit==1){
                return;
                break;
            }else{
                break;
            }
        case 4:
            break;
        default:
            printf("\n=========================================\n");
            printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
            printf("=========================================\n\n");
            break;
    }
    }while (pilihan != 4);
    

}
void MENU6() {
   int pilihan;
   int pilih;
   int delete;
   if(head==NULL){
        printf("\n=========================================\n");
        printf("            BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
    do {
     
    printf(" --------------------------------------- \n");
    printf("| Pilih operasi pengurutan:             |\n");
    printf("|---------------------------------------|\n");
    printf("| 1.Urutkan Berdasarkan Nama            |\n");
    printf("| 2.Urutkan Berdasarkan Umur            |\n");
    printf("| 3.Urutkan Berdasarkan Jenis Kelamin   |\n");
    printf("| 4.Urutkan Berdasarkan Nomor Telepon   |\n");
    printf("| 5.Urutksn Berdasarkan Email           |\n" );
    printf("| 6.BATAL                               |\n");
    printf(" --------------------------------------- \n");
    
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    system("clear");

    switch (pilihan) {
        case 1:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Pilih Model Pengurutan:               |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Ascending (Menaik)                 |\n");
                printf("| 2. Descending (Menurun)               |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        URUTKAN_NAMA_MENAIK();
                        return;
                        break;
                    case 2:
                        URUTKAN_NAMA_MENURUN();
                        return;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            return;
            break;           
        case 2:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Pilih Model Pengurutan:               |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Ascending (Menaik)                 |\n");
                printf("| 2. Descending (Menurun)               |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        URUTKAN_UMUR_MENAIK();
                        return;
                        break;
                    case 2:
                        URUTKAN_UMUR_MENURUN();
                        return;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            return;
            break;
        case 3:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Pilih Model Pengurutan:               |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Ascending (Menaik)                 |\n");
                printf("| 2. Descending (Menurun)               |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        URUTKAN_JK_MENAIK();
                        return;
                        break;
                    case 2:
                        URUTKAN_JK_MENURUN();
                        return;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            return;
            break;
        case 4:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Pilih Model Pengurutan:               |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Ascending (Menaik)                 |\n");
                printf("| 2. Descending (Menurun)               |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        URUTKAN_NOTEL_MENAIK();
                        return;
                        break;
                    case 2:
                        URUTKAN_NOTEL_MENURUN();
                        return;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            return;
            break;
        case 5:
            do {
     
                printf(" --------------------------------------- \n");
                printf("| Pilih Model Pengurutan:               |\n");
                printf("|---------------------------------------|\n");
                printf("| 1. Ascending (Menaik)                 |\n");
                printf("| 2. Descending (Menurun)               |\n");
                printf("| 3. BATAL                              |\n");
                printf(" --------------------------------------- \n");
    
                printf("Pilihan: ");
                scanf("%d", &pilih);
                system("clear");

                switch (pilih) {
                    case 1:
                        URUTKAN_EMAIL_MENAIK();
                        return;
                        break;
                    case 2:
                        URUTKAN_EMAIL_MENURUN();
                        return;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n=========================================\n");
                        printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
                        printf("=========================================\n\n");
                        break;
                }
            }while (pilih != 3);
            return;
            break;
        case 6:
            break;
        default:
           printf("\n=========================================\n");
           printf("   MENU YANG ANDA PILIH TIDAK TERSEDIA   \n");
           printf("=========================================\n\n");
                        break;
    }
    }while (pilihan != 6);

}
void MENU10(){
    printf("\n=========================================\n");
    printf("           UNDO AKSI TERAKHIR            \n");
    printf("      (Input, Delete, Edit, & Urut)\n");
    printf("=========================================\n\n");
    if (undo==NULL){
        printf(" UNDO GAGAL : TIDAK ADA AKSI TERAKHIR        ");
        printf("\n\n=========================================\n");
        return;
    }
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    copyContactBook(undo, &head);
    printf("              UNDO BERHASIL                  \n");
    printf("KEMBALI KE KONDISI SEBELUM AKSI TERAKHIR\n");
    printf("\n\n=========================================\n");
    return;
    
}
void MENU11(){
    printf("\n=========================================\n");
    printf("       REDO SETELAH UNDO BERHASIL        \n");
    printf("=========================================\n\n");
    if(undo!=NULL){
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp); 
        }
    copyContactBook(redo, &head);
    printf("              REDO BERHASIL                  \n");
    printf("     KEMBALI KE KONDISI SEBELUM UNDO         \n");
    printf("\n\n=========================================\n");
    return;
    } else {
        printf(" REDO GAGAL : UNDO TIDAK PERNAH DILAKUKAN ");
        printf("\n\n=========================================\n");
        return;
    }
    
}

void LANJUT() {
    int lanjut;

    do {
        printf("\n-----------------------------------------\n");
        printf("| Masih ingin mengakses buku kontak?    |\n");
        printf("| Ketik 1 jika Ya                       |\n");
        printf("| Ketik 0 jika tidak                    |\n");
        printf("-----------------------------------------\n");
        printf("Keputusan : ");
        scanf("%d", &lanjut);
        

        switch (lanjut) {
            case 1:
                printf("\n=========================================\n");
                printf("        KEMBALI KE MENU UTAMA         \n");
                printf("=========================================\n\n");
                break;

            case 0:
                system("clear");
                printf("\n=========================================\n");
                printf("        TERIMA KASIH! SAMPAI JUMPA    \n");
                printf("=========================================\n\n");
                exit(0);

            default:
                system("clear");
                printf("\n=========================================\n");
                printf("      PILIHAN TIDAK VALID. ULANGI    \n");
                printf("=========================================\n\n");
                break;
        }

    } while (lanjut != 0 && lanjut!=1);
}

void inputAdjacencyMatrix(int ***adjacencyMatrix, char nodes[MAX_KONTAK][MAX_NAME_LENGTH], int numNodes) {
    // Alokasi memori untuk matriks adjacency
    *adjacencyMatrix = (int **)malloc(numNodes * sizeof(int *));
    for (int i = 0; i < numNodes; i++) {
        (*adjacencyMatrix)[i] = (int *)malloc(numNodes * sizeof(int));
    }

    printf("MASUKKAN RELASI KONTAK\n");
    printf("0. Tidak Terdapat Relasi\n");
    printf("1. Terdapat Relasi\n\n");

    for (int i = 0; i < numNodes; i++) {
        for (int j = i; j < numNodes; j++) {
            if (i == j) {
                (*adjacencyMatrix)[i][j] = 1; // Set nilai 1 untuk node yang sama
            } else {
                printf("%s dan %s : ", nodes[i], nodes[j]);
                scanf("%d", &(*adjacencyMatrix)[i][j]);

                // Isi nilai simetris
                (*adjacencyMatrix)[j][i] = (*adjacencyMatrix)[i][j];
            }
        }
    }
    
    printf("\n");
}
void displayAdjacencyMatrix(int **adjacencyMatrix, char nodes[MAX_KONTAK][MAX_NAME_LENGTH], int numNodes) {
    printf("\nTABEL RELASI/HUBUNGAN ANTAR KONTAK\n");
    
    printf("|---------------|");
    for (int i = 0; i < numNodes; i++) {
        printf("---------------|");
    }
    
    printf("\n|Kontak\t\t|");
    for (int i = 0; i < numNodes; i++) {
        printf("%-15s|", nodes[i]);
    }
    printf("\n");
    printf("|---------------|");
    for (int i = 0; i < numNodes; i++) {
        printf("---------------|");
    }
    printf("\n");

    for (int i = 0; i < numNodes; i++) {
        printf("|%-15s|", nodes[i]);
        for (int j = 0; j < numNodes; j++) {
            printf("%-15d|", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    printf("|---------------|");
    for (int i = 0; i < numNodes; i++) {
        printf("---------------|");
    }
    printf("\n");
    
}
void tambahrelasi() {
    if(head==NULL){
        printf("\n=========================================\n");
        printf("            BUKU KONTAK KOSONG        \n");
        printf("=========================================\n\n");
        return;
   }
    printf("\n=========================================\n");
    printf("        KONEKTIVITAS ANTAR KONTAK   \n");
    printf("=========================================\n\n");
    
   
    numNodes = 0;
    Node* curr = head;
    while (curr != NULL) {
        numNodes = numNodes + 1;
        curr = curr->next;
    }

     
    if (numNodes > MAX_KONTAK || numNodes <= 0) {
        printf("\n=========================================\n");
        printf("       JUMLAH KONTAK TERLALU BESAR       \n");
        printf("             ATAU TIDAK VALID    \n");
        printf("=========================================\n\n");
        return;
    }
    Node* current = head;
    int i = 0;
    while (current != NULL) {
        strcpy(nodes[i], current->nama);
        i++;
        current = current->next;
    }
    inputAdjacencyMatrix(&adjacencyMatrix, nodes, numNodes);
    printf("=========================================\n");
    printf("      BERHASIL MENAMBAH KONEKTIVITAS   \n");
    printf("=========================================\n\n");
    
}

int main() {
    int pilih;
    Node* input=NULL;
    tambahContactBook("Frans", 22, "L", "08884354223", "frans@gmail.com");
    tambahContactBook("Ade Putra", 22, "L", "08180203123", "putra@gmail.com");
    tambahContactBook("Dewi", 18, "P", "0883432123", "dewi@gmail.com");
    tambahContactBook("Peter Parker", 20, "L", "081392392123", "parker@gmail.com");
    tambahContactBook("Dede", 23, "P", "082312324123", "dede@gmail.com");

    do {
        MENU();
        printf("masukkan pilihan anda (1-13) : ");
        scanf("%d", &pilih);
         system("clear");

        switch (pilih) {
            case 1:
                while (undo != NULL) {
                    Node* temp = undo;
                    undo = undo->next;
                    free(temp);
                }
                copyContactBook(head, &undo);
                
                input_data();
                
                while (redo != NULL) {
                    Node* temp = redo;
                    redo = redo->next;
                    free(temp);
                }
                copyContactBook(head, &redo);
                break;
            case 2:
                MENU2();
                break;
            case 3:
                MENU3();
                break;
            case 4:
                while (undo != NULL) {
                    Node* temp = undo;
                    undo = undo->next;
                    free(temp);
                }
                copyContactBook(head, &undo);
                
                MENU4();
                
                while (redo != NULL) {
                    Node* temp = redo;
                    redo = redo->next;
                    free(temp);
                }
                copyContactBook(head, &redo);
                break;
            case 5:
                while (undo != NULL) {
                    Node* temp = undo;
                    undo = undo->next;
                    free(temp);
                }
                copyContactBook(head, &undo);
                
                MENU5();
                
                while (redo != NULL) {
                    Node* temp = redo;
                    redo = redo->next;
                    free(temp);
                }
                copyContactBook(head, &redo);
                break;
            case 6:
                while (undo != NULL) {
                    Node* temp = undo;
                    undo = undo->next;
                    free(temp);
                }
                copyContactBook(head, &undo);
                
                MENU6();
                
                while (redo != NULL) {
                    Node* temp = redo;
                    redo = redo->next;
                    free(temp);
                }
                copyContactBook(head, &redo);
                break;
            case 7:
                
                tambahrelasi();

                break;
            case 8:
                
                displayAdjacencyMatrix(adjacencyMatrix, nodes, numNodes);

                break;  
            case 9:
                saveToFile("data.txt"); 
                break;
            case 10:
                loadFromFile("data.txt");
                break;
            case 11:
                MENU10();
                break;
            case 12:
                MENU11();
                break;
            case 13:
                printf("\n=========================================\n");
                printf("        TERIMA KASIH! SAMPAI JUMPA \n");
                printf("=========================================\n\n");
                exit(0);
                break;
            default:
                printf("\n=========================================\n");
                printf("  MENU YANG ANDA PILIH TIDAK TERSEDIA \n");
                printf("=========================================\n\n");
                break;
        } LANJUT();
        system("clear");
        
    } while (pilih != 13);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    
    return 0;
}






