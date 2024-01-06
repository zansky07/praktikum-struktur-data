#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <limits.h>
#define N 100

//_id digunakan untuk primary key
static int _id = 1;
//Bagian Single Linked List untuk menyimpan kontak

//Membuat setiap node dari linked list untuk menyimpan kontaknya
typedef struct node kontak;
struct node{
	int _id;
	char nama[20];
    unsigned umur;
    bool jk; // 1 untuk laki-laki, 0 untuk perempuan
    char no_telp[15];
    char email[20];
	kontak* next;
};
typedef kontak* ptrnode;


//Membuat Linked List
typedef struct SinglyLinkedList SLL;
struct SinglyLinkedList{
	ptrnode head;
	unsigned size;
};
typedef SLL* ptrSLL;

//Implementasi node relasi Kontak untuk menyimpan relasi sehingga dinamis ke kanan
typedef struct node_1D Tnode_1D;
struct node_1D{
	int data;
	Tnode_1D* next;
};
typedef Tnode_1D* ptrnode_1D;

//Bungkus linkedlist yang ke dinamis ke samping
typedef struct SinglyLinkedList_1D SLL_1D;
struct SinglyLinkedList_1D{
	ptrnode_1D head;
	int size;
};
typedef SLL_1D* ptrSLL_1D;

//Implementasi node adjacency List
//node dari adjacency list adalah sebuah pointer ke sebuah linkedlist 1D
typedef struct adjacencyListNode adjListNode;
struct adjacencyListNode{
	ptrSLL_1D data_list;
	adjListNode* next;
};
typedef adjListNode* ptrAdjListNode;


typedef struct adjacencyList adjList;
struct adjacencyList{
	ptrAdjListNode head;
	int size;
};
typedef adjList* ptrAdjList;

//Implementasi item dalam hash table digunakan untuk pemetaan primary key ID ke pointer yang merujuk ke kontak
typedef struct item Titem;
struct item{
	int key;
	ptrnode data;
	Titem* next;
};
typedef Titem* ptritem;

//Bungkus lagi hashtable nya agar lebih rapi juga :D
typedef struct hash_table HashTable;
struct hash_table{
	ptritem head;
	int capacity;
};
typedef HashTable* ptrHashTable;

typedef struct {
    ptrSLL kontakList;
    ptrnode undoEditBuffer[N]; // Assuming N is a predefined constant
    int jumlah;
    int indeksUndoEdit;
    ptrnode redoEditBuffer[N];
    int indeksRedoEdit;
    ptrnode undoDeleteBuffer[N];
    int indeksUndoDelete;
    ptrnode redoDeleteBuffer[N];
    int indeksRedoDelete;
    ptrnode undoInsertBuffer[N];
    int indeksUndoInsert;
    ptrnode redoInsertBuffer[N];
    int indeksRedoInsert;
} BukuKontak;

//List subprogram yang berhubungan dengan linkedlist yang menyimpan kontak

//subprogram untuk node nya
ptrnode createNode(char pNama[], unsigned pUmur, bool pJenis_kelamin, char pNo_telp[], char pEmail[]); //Membuat node kontak
void printNode(ptrnode tmp); //Mencetak suatu kontak

//Subprogram untuk linkedlist-nya
void SLL_init(ptrSLL tmpList); //Inisialisasi struct untuk ngebungkus Single Linked List
void SLL_insert(ptrSLL currList, ptrnode currNode, ptrAdjList currAdjList, ptrHashTable currHashTable); //Insert kontak ke SLL
void SLL_popFront(ptrSLL currList); //Menghapus head linked list
void SLL_popBack(ptrSLL currList); //Menghapus tail linked list
void SLL_deleteNama(ptrSLL currList, char nama[]); //Menghapus suatu kontak berdasarkan nama


//subprogram untuk node
ptrnode_1D createNode_1D(int Pnum); //Membuat node relasi

//Subprogram untuk linkedlist
void SLL_1D_init(ptrSLL_1D tmpList); //Inisialisasi struct
void SLL_1D_pushBack(ptrSLL_1D currList, int data); //insert tail ke SLL 1D
void SLL_1D_popFront(ptrSLL_1D currList); //delete head dari SLL 1D
void SLL_1D_popBack(ptrSLL_1D currList); //delete tail dari SLL 1D
void SLL_1D_deleteNode(ptrSLL_1D currList, int idName); //menghapus suatu node berdasarkan ID

//subprogram untuk node
void adjListNode_init(ptrAdjListNode currAdjListNode); //Inisialisasi row
ptrAdjListNode createNode_adj(int src); //Membuat subuah row, src adalah nama row tsb

//Subprogram untuk Adjlist
void adjList_init(ptrAdjList currAdjList); //inisiasi adjlist
void adjList_pushBack(ptrAdjList currAdjList, int src);//Membuat insert relasi di baris ke sekian
void adjList_insertRelation(ptrAdjList currAdjList, int src, int fin); //insert tail (fin) pada baris ke (src)
void adjList_deleteRelation(ptrAdjList currAdjList, int src, int fin); //hapus (fin) pada baris ke (src)

//List subprogram yang berhubungan dengan hashTable

//Subprogram untuk item
ptritem createItem(int Pkey, ptrnode Pnode); //Membuat item

//Subprogram untuk Hash Table
void hashTable_init(ptrHashTable currHashTable); //Inisiasi hash table
void hashTable_pushBack(ptrHashTable currHashTable, int key, ptrnode currnode); //insert tail indexing baru ke hash table
ptrnode hashTable_getData(ptrHashTable currHashTable, int Pkey); //mengambil pointer ke kontak dengan id

//Fungsi yang dipakai di program utama
void menu1(ptrSLL daftarKontak);
void menu2(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu3(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu4(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu5(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu6(ptrSLL daftarKontak, ptrHashTable indeksID);
void menu7(ptrSLL daftarKontak);
void menu8(ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu9(ptrSLL daftarKontak);
void menu10(ptrSLL daftarKontak,ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu11(ptrSLL daftarKontak);
void menu12(BukuKontak *buku);

//Subprogram sampingan untuk menunjang program

//bagian dari mergesort berdasarkan nama
ptrnode merge(ptrnode firstNode, ptrnode secondNode);
ptrnode mid_SLL(ptrnode head);
ptrnode sortNama(ptrnode daftarKontak);

//bagian dari search biasa
ptrnode middle(ptrnode start, ptrnode last);
ptrnode cariBinarySearch_nama(ptrSLL daftarKontak, char nama[]);
ptrnode cariLinearSearch_noTelp(ptrSLL daftarKontak, char no_telp[]);
ptrnode cariLinearSearch_email(ptrSLL daftarKontak, char email[]);

//bagian dari wildcard search
ptrnode cariWildcardSearch_nama(ptrSLL daftarKontak, char* nama_pattern);
ptrnode cariWildcardSearch_email(ptrSLL daftarKontak, char* email_pattern);
ptrnode cariWildcardSearch_noTelp(ptrSLL daftarKontak, char* no_telp_pattern);

//bagian dari 'and 'or search

// Mode pencarian
typedef enum { AND, OR } SearchMode;
// Fungsi pencarian
ptrnode cari(ptrSLL daftarKontak, char nama[], bool useNama, unsigned umur, bool useUmur, bool jk, bool useJk, char email[], bool useEmail, SearchMode mode) {
    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        int matchCount = 0;
        int criteriaCount = 0;

        if (useNama) {
            criteriaCount++;
            if (strcmp(current->nama, nama) == 0) matchCount++;
        }
        if (useUmur) {
            criteriaCount++;
            if (current->umur == umur) matchCount++;
        }
        if (useJk) {
            criteriaCount++;
            if (current->jk == jk) matchCount++;
        }
        if (useEmail) {
            criteriaCount++;
            if (strcmp(current->email, email) == 0) matchCount++;
        }

        if ((mode == AND && matchCount == criteriaCount) || (mode == OR && matchCount > 0)) {
            return current;
        }

        current = current->next;
    }
    return NULL;
}


//bagian lain
int cariID(ptrSLL daftarKontak, char nama[]); //Mencari ID dari nama kontak
void editProp(ptrSLL daftarKontak, int flag, int _id, ptrHashTable indeksID);
void hitungUmur(ptrSLL daftarKontak, unsigned *maxUmur, unsigned *minUmur, double *rataUmur);

//bagian save dan load
void save(ptrSLL daftarKontak, char *namafile);
void load(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID, char *namafile);


//Undo Redo Program


void undoEdit(BukuKontak *buku);
void undoInsert(BukuKontak *buku);
void undoDelete(BukuKontak *buku);

void mengundo(BukuKontak *buku) {
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
        memcpy(buku->redoInsertBuffer, buku->kontakList, sizeof(kontak) * N);
        buku->indeksRedoInsert++;

        // Pulihkan informasi kontak sebelumnya
        memcpy(buku->kontakList, buku->undoInsertBuffer, sizeof(kontak) * N);

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
        memcpy(buku->redoEditBuffer, buku->kontakList, sizeof(kontak) * N);
        buku->indeksRedoEdit++;

        // Pulihkan informasi kontak sebelumnya
        memcpy(buku->kontakList, buku->undoEditBuffer, sizeof(kontak) * N);

        printf("Undo Edit berhasil.\n");
    } else {
        printf("Tidak ada langkah undo edit lebih lanjut.\n");
    }
}

void undoDelete(BukuKontak *buku) {
    if (buku->indeksUndoDelete > 0) {
        buku->indeksUndoDelete--;

        // Copy data yang akan dihapus ke redo buffer
        memcpy(&buku->redoDeleteBuffer[buku->indeksRedoDelete], &buku->kontakList[buku->jumlah], sizeof(kontak));

        // Copy data dari undo buffer ke kontak
        memcpy(&buku->kontakList[buku->jumlah], &buku->undoDeleteBuffer[buku->indeksUndoDelete], sizeof(kontak));

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

void menguredo(BukuKontak *buku){
    int choice;
    printf("--------------------------------------------------\n");
    printf("\t\tAPLIKASI BUKU KONTAK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU REDO\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Redo Insert\n");
    printf("| 2. Redo Edit \n");
    printf("| 3. Redo Delete\n");
    printf("| 4. Kembali ke Menu Utama\n");
    printf("| 5. Keluar\n");
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
        memcpy(buku->undoInsertBuffer, buku->kontakList, sizeof(kontak) * N);
        buku->indeksUndoInsert++;

        // Pulihkan informasi kontak berikutnya
        memcpy(buku->kontakList, buku->redoInsertBuffer, sizeof(kontak) * N);

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
        memcpy(buku->undoEditBuffer, buku->kontakList, sizeof(kontak) * N);
        buku->indeksUndoEdit++;

        // Pulihkan informasi kontak berikutnya
        memcpy(buku->kontakList, buku->redoEditBuffer, sizeof(kontak) * N);

        printf("Redo Edit berhasil.\n");
    } else {
        printf("Tidak ada langkah redo edit lebih lanjut.\n");
    }
}

void redoDelete(BukuKontak *buku) {
    if (buku->indeksRedoDelete > 0) {
        buku->indeksRedoDelete--;

        // Copy data yang akan dihapus ke undo buffer
        memcpy(&buku->undoDeleteBuffer[buku->indeksUndoDelete], &buku->kontakList[buku->jumlah - 1], sizeof(kontak));

        // Copy data dari redo buffer ke kontak
        memcpy(&buku->kontakList[buku->jumlah - 1], &buku->redoDeleteBuffer[buku->indeksRedoDelete], sizeof(kontak));

        buku->indeksUndoDelete++;
        buku->jumlah--;
        printf("Redo Delete berhasil.\n");
    } else {
        printf("Tidak ada langkah redo delete lebih lanjut.\n");
    }
}


int main(){
	//inisiasi daftar kontak
    ptrSLL daftarKontak = (ptrSLL) malloc(sizeof(SLL));;
    SLL_init(daftarKontak);

	//inisiasi daftar relasi
	ptrAdjList daftarRelasi = (ptrAdjList) malloc(sizeof(adjList));
	adjList_init(daftarRelasi);

	//inisiasi indexing
	ptrHashTable indeksID = (ptrHashTable) malloc(sizeof(HashTable));
	hashTable_init(indeksID);

    //inisiasasi untuk undo redo
    BukuKontak buku;

	//Kontak yang tersedia
    SLL_insert(daftarKontak, createNode("Fauzan", 18, true, "08124643", "fauzan@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Radja", 16, true, "08537884", "radja@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Astuti", 21, false, "08966433", "astuti@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Zaenab", 17, false, "08765569", "zaenab@gmail.com"), daftarRelasi, indeksID);

	//Relasi yang tersedia
	adjList_insertRelation(daftarRelasi, 1, 4);
	adjList_insertRelation(daftarRelasi, 2, 3);
	adjList_insertRelation(daftarRelasi, 2, 4);
	adjList_insertRelation(daftarRelasi, 3, 4);

	bool isFinished = false;
	int _menu = 0;

	daftarKontak->head = sortNama(daftarKontak->head);
	do{
		printf("===========================================\n");
		printf("                Buku Kontak                \n");
		printf("===========================================\n");

		printf("Menu: \n");
		printf("1. Cari Kontak\n");
		printf("2. Tambah Kontak\n");
		printf("3. Tambah Relasi\n");
		printf("4. Hapus Kontak\n");
		printf("5. Hapus Relasi\n");
		printf("6. Sunting Kontak\n");
		printf("7. Tampilkan Kontak (Sorting) \n");
		printf("8. Tampilkan Relasi\n");
		printf("9. Save Kontak\n");
		printf("10. Load Kontak\n");
		printf("11. Hitung Max, Min, dan Rata-Rata Umur Kontak\n");
		printf("12. Undo Redo Program\n");
		printf("12. Keluar\n");
		printf("Masukkan menu: ");

		scanf("%d", &_menu);

		system("cls");
		switch (_menu){
		case 1:
			menu1(daftarKontak);
			break;
		case 2:
			menu2(daftarKontak, daftarRelasi, indeksID);
			break;
		case 3:
			menu3(daftarKontak, daftarRelasi, indeksID);
			break;
		case 4:
			menu4(daftarKontak, daftarRelasi, indeksID);
			break;
		case 5:
			menu5(daftarKontak, daftarRelasi, indeksID);
			break;
		case 6:
			menu6(daftarKontak, indeksID);
			break;
		case 7:
			menu7(daftarKontak);
			break;
		case 8:
			menu8(daftarRelasi, indeksID);
			break;
        case 9:
            menu9(daftarKontak);
            break;
        case 10:
            menu10(daftarKontak, daftarRelasi, indeksID);
            break;
        case 11:
            menu11(daftarKontak);
        case 12:
            menu12(&buku);
		case 13:
			isFinished = true;
			printf("Anda keluar...\n");
			break;
		default:
			system("cls");
			printf("Masukan salah!\n\n");
		}
	}while(!isFinished);
}


void menu1(ptrSLL daftarKontak) {
    char nama[20], no_telp[15], email[20], input[20];
    unsigned umur;
    bool jk;
    int useNama = 0, useUmur = 0, useJk = 0, useEmail = 0, mode;
    int pilihan, pilihan2, pencarianTipe;
    ptrnode tmp = NULL;

    printf("===========================================\n");
    printf("                Cari Kontak                \n");
    printf("===========================================\n");

    // Memilih tipe pencarian
    printf("Pilih tipe pencarian:\n");
    printf("1. Pencarian Biasa\n");
    printf("2. Pencarian Wildcard\n");
    printf("3. Pencarian And/Or\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pencarianTipe);
    getchar();

    switch (pencarianTipe) {
        case 1: // Pencarian Biasa
            printf("Pilih kriteria pencarian:\n");
            printf("1. Nama\n");
            printf("2. No Telepon\n");
            printf("3. Email\n");
            printf("Pilihan Anda: ");
            scanf("%d", &pilihan);
            getchar();

            printf("Masukkan kriteria pencarian: ");
            fgets(input, 20, stdin);
            input[strcspn(input, "\n")] = 0; // Menghapus newline

            switch (pilihan) {
                case 1:
                    // Implementasi cariBinarySearch_nama
                    daftarKontak->head = sortNama(daftarKontak->head);
                    tmp = cariBinarySearch_nama(daftarKontak, input);
                    break;
                case 2:
                    // Implementasi cariLinearSearch_noTelp
                    tmp = cariLinearSearch_noTelp(daftarKontak, input);
                    break;
                case 3:
                    // Implementasi cariLinearSearch_email
                    tmp = cariLinearSearch_email(daftarKontak, input);
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
            }
            break;

        case 2: // Pencarian Wildcard
            printf("Pilih kriteria pencarian:\n");
            printf("1. Nama\n");
            printf("2. No Telepon\n");
            printf("3. Email\n");
            printf("Pilihan Anda: ");
            scanf("%d", &pilihan2);
            getchar();
            printf("Masukkan kriteria pencarian: ");
            fgets(input, 20, stdin);
            input[strcspn(input, "\n")] = 0; // Menghapus newline

             switch (pilihan2) {
            case 1:
                // Fungsi untuk pencarian wildcard nama (jika ada)
                tmp = cariWildcardSearch_nama(daftarKontak, input);
                break;
            case 2:
                tmp = cariWildcardSearch_noTelp(daftarKontak, input);
                break;
            case 3:
                // Fungsi untuk pencarian wildcard email (jika ada)
                tmp = cariWildcardSearch_email(daftarKontak, input);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                return;
        }
        break;

        case 3: // Pencarian And/Or
            // Implementasi pencarian And/Or
            printf("Gunakan nama dalam pencarian? (1 = ya, 0 = tidak): ");
        scanf("%d", &useNama);
        if (useNama) {
            printf("Masukkan nama: ");
            scanf("%19s", nama);
        }

        printf("Gunakan umur dalam pencarian? (1 = ya, 0 = tidak): ");
        scanf("%d", &useUmur);
        if (useUmur) {
            printf("Masukkan umur: ");
            scanf("%u", &umur);
        }

        printf("Gunakan jenis kelamin dalam pencarian? (1 = ya, 0 = tidak): ");
        scanf("%d", &useJk);
        if (useJk) {
            printf("Masukkan jenis kelamin (1 untuk laki-laki, 0 untuk perempuan): ");
            scanf("%d", &jk);
        }

        printf("Gunakan email dalam pencarian? (1 = ya, 0 = tidak): ");
        scanf("%d", &useEmail);
        if (useEmail) {
            printf("Masukkan email: ");
            scanf("%19s", email);
        }

        printf("Pilih mode pencarian (0 untuk AND, 1 untuk OR): ");
            scanf("%d", &mode);
            getchar();
        tmp = cari(daftarKontak, nama, useNama, umur, useUmur, jk, useJk, email, useEmail, (mode == 0) ? AND : OR);
        break;
        }
        if (tmp != NULL) {
             printNode(tmp);
        } else {
            printf("Tidak ada kontak yang cocok.\n");
        }
        printf("Tekan untuk melanjutkan...");
        getchar();
        system("cls");

}


void menu2(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];
    unsigned umur;
    int jenis_kelamin; // 1 untuk laki-laki, 0 untuk perempuan (lebih hemat memori)
    char telpNo[15];
    char email[20];

	printf("===========================================\n");
	printf("               Tambah Kontak               \n");
	printf("===========================================\n");

	printf("%-15s: ", "Nama");
	getchar();
	gets(nama);

	printf("%-15s: ", "Umur");
	scanf("%d", &umur);

	printf("%-15s: ", "Jenis Kelamin");
	scanf("%d", &jenis_kelamin);

	printf("%-15s: ", "Nomor Telefon");
	getchar();
	gets(telpNo);

	printf("%-15s: ", "Alamat Email");
	gets(email);

	SLL_insert(daftarKontak, createNode(nama, umur, (bool) jenis_kelamin, telpNo, email), daftarRelasi, indeksID);
	daftarKontak->head = sortNama(daftarKontak->head);

	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu3(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char src[20];
	char fin[20];
	int i = 0, n = 0;

	printf("===========================================\n");
	printf("               Tambah Relasi               \n");
	printf("===========================================\n");

	printf("Format input: \n");
	printf("[Nama 1], [Nama 2]\n\n");
	printf("Contoh: \n");
	printf("Budiman, Jaka\n\n");

	printf("Banyak relasi yang ingin dimasukkan: ");
	scanf("%d", &n);
	getchar();

	for(i = 0; i<n; i++){
		printf("Relasi ke-%d: ", i+1);
		scanf("%19[^,], %19[^\n]", &src, &fin);
		getchar();
		ptrnode id_src = hashTable_getData(indeksID, cariID(daftarKontak, src));
		ptrnode id_fin = hashTable_getData(indeksID, cariID(daftarKontak, fin));

		if(id_src == NULL || id_fin == NULL){
			printf("Relasi gagal ditambahkan, pastikan data yang dimasukkan sudah tersedia!\n");
			i--;
		}else adjList_insertRelation(daftarRelasi, id_src->_id, id_fin->_id);
	}

	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu4(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];

	printf("===========================================\n");
	printf("              Hapus  Kontak                \n");
	printf("===========================================\n");

	printf("Masukkan nama: ");

	getchar();
	gets(nama);

	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	system("cls");

	if(tmp == NULL){
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	}else{
		SLL_deleteNama(daftarKontak, tmp->nama);
		printf("Data Berhasil dihapus!\n");
	}
	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu5(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];
	char nama2[20];
	printf("===========================================\n");
	printf("=             Hapus  Relasi               =\n");
	printf("===========================================\n");

	printf("Masukkan nama orang pertama: ");

	getchar();
	gets(nama);

	printf("Masukkan nama orang kedua  : ");

	gets(nama2);

	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	ptrnode tmp2 = cariBinarySearch_nama(daftarKontak, nama2);
	system("cls");

	if(tmp == NULL || tmp2 == NULL){
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	}else{
		int tmp_id = tmp->_id;
		int tmp2_id = tmp2->_id;

		adjList_deleteRelation(daftarRelasi, tmp_id, tmp2_id);
		printf("Data berhasil dihapus!\n");
	}

	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu6(ptrSLL daftarKontak, ptrHashTable indeksID){
	char nama[20];
	int _flag = 0;

	printf("===========================================\n");
	printf("=            Sunting Kontak               =\n");
	printf("===========================================\n");

	printf("Masukkan nama: ");

	getchar();
	gets(nama);

	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);

	if(tmp != NULL){
		printf("\nApa yang ingin disunting? \n");
		printf("1. Nama\n");
		printf("2. Umur\n");
		printf("3. Jenis kelamin\n");
		printf("4. Nomor Telefon\n");
		printf("5. Alamat Email\n");
		printf("Masukkan nama: ");

		scanf("%d", &_flag);

		editProp(daftarKontak, _flag, tmp->_id, indeksID);
	}else{
		printf("\nData tidak ditemukan!\n");
	}

	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void swapNodes(ptrnode a, ptrnode b) {
    int tempId = a->_id;
    char tempNama[20];
    strcpy(tempNama, a->nama);
    unsigned tempUmur = a->umur;
    bool tempJk = a->jk;
    char tempNoTelp[15];
    strcpy(tempNoTelp, a->no_telp);
    char tempEmail[20];
    strcpy(tempEmail, a->email);

    a->_id = b->_id;
    strcpy(a->nama, b->nama);
    a->umur = b->umur;
    a->jk = b->jk;
    strcpy(a->no_telp, b->no_telp);
    strcpy(a->email, b->email);

    b->_id = tempId;
    strcpy(b->nama, tempNama);
    b->umur = tempUmur;
    b->jk = tempJk;
    strcpy(b->no_telp, tempNoTelp);
    strcpy(b->email, tempEmail);
}

void sorting(SLL* buku, int criteria, bool ascending) {
    if (buku->size == 0) {
        printf("Daftar Kontak Kosong\n");
        return;
    }

    bool swapped;
    ptrnode ptr;
    ptrnode lptr = NULL;

    do {
        swapped = false;
        ptr = buku->head;

        while (ptr->next != lptr) {
            bool condition = false;
            switch (criteria) {
                case 1: // Sort by name
                    condition = ascending ? (strcmp(ptr->nama, ptr->next->nama) > 0) : (strcmp(ptr->nama, ptr->next->nama) < 0);
                    break;
                case 2: // Sort by age
                    condition = ascending ? (ptr->umur > ptr->next->umur) : (ptr->umur < ptr->next->umur);
                    break;
                case 3: // Sort by gender
                    condition = ascending ? (ptr->jk > ptr->next->jk) : (ptr->jk < ptr->next->jk);
                    break;
                case 4: // Sort by phone number
                    condition = ascending ? (strcmp(ptr->no_telp, ptr->next->no_telp) > 0) : (strcmp(ptr->no_telp, ptr->next->no_telp) < 0);
                    break;
                case 5: // Sort by email
                    condition = ascending ? (strcmp(ptr->email, ptr->next->email) > 0) : (strcmp(ptr->email, ptr->next->email) < 0);
                    break;
            }
            if (condition) {
                swapNodes(ptr, ptr->next);
                swapped = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);

    printf("Kontak berhasil diurutkan.\n");
}

void displayContacts(SLL *buku) {
    ptrnode current = buku->head;
    while (current != NULL) {
        // Display each contact's details
        // Example: printf("Name: %s, Age: %u, ...\n", current->nama, current->umur);
        printf("ID: %d\n", current->_id);
        printf("Name: %s\n", current->nama);
        printf("Age: %u\n", current->umur);
        printf("Gender: %s\n", current->jk ? "Male" : "Female");
        printf("Phone Number: %s\n", current->no_telp);
        printf("Email: %s\n", current->email);
        printf("\n");
        current = current->next;
    }
}

void menu7(SLL *buku) {
    if (buku->head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    int criteria;
    bool ascending;
    printf("Enter sorting criteria (1-Nama, 2-Umur, 3-Jenis Kelamin, 4-Nomor Telepon, 5-Email): ");
    scanf("%d", &criteria);
    printf("Ascending (1 for yes, 0 for no): ");
    scanf("%d", &ascending);

    sorting(buku, criteria, ascending);
    printf("Contacts sorted successfully.\n");

    displayContacts(buku);
}

void menu8(ptrAdjList daftarRelasi, ptrHashTable indeksID){
	printf("===========================================\n");
	printf("=              Tampil Relasi              =\n");
	printf("===========================================\n");

	if(daftarRelasi->size == 0){
		printf("Relasi Kosong! \n");
	}else{
		ptrAdjListNode cursor = daftarRelasi->head;
		ptrnode_1D cursor2 = cursor->data_list->head;

		while(cursor != NULL){
			printf("%-20s: ", hashTable_getData(indeksID, cursor2->data)->nama);
			cursor2 = cursor2->next;

			while(cursor2 != NULL){
				printf("(%s) ", hashTable_getData(indeksID, cursor2->data)->nama);
				cursor2 = cursor2->next;
			}
			printf("\n");
			cursor = cursor->next;
			if(cursor != NULL) cursor2 = cursor->data_list->head;
		}

		printf("===========================================\n");
		printf("Tekan untuk melanjutkan...");
		getchar();
		getchar();
		system("cls");
	}
}

void menu9(ptrSLL daftarKontak) {
    char namafile[100];
    printf("Masukkan nama file untuk menyimpan kontak: ");
    scanf("%99s", namafile); // Mengambil input nama file dari pengguna
    save(daftarKontak, namafile); // Memanggil fungsi save
}

void menu10(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID) {
    char namafile[100];
    printf("Masukkan nama file untuk memuat kontak: ");
    scanf("%99s", namafile); // Mengambil input nama file dari pengguna
    load(daftarKontak, daftarRelasi, indeksID, namafile); // Memanggil fungsi load
}

// Fungsi untuk menghitung dan mencetak maksimal, minimum, dan rata-rata umur
void menu11(ptrSLL daftarKontak) {
    if (daftarKontak == NULL || daftarKontak->head == NULL) {
        printf("Daftar kontak kosong.\n");
        return;
    }

    unsigned maxUmur = 0;
    unsigned minUmur = UINT_MAX;
    double rataUmur = 0.0;
    unsigned totalUmur = 0;
    unsigned jumlahKontak = 0;

    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        if (current->umur > maxUmur) {
            maxUmur = current->umur;
        }
        if (current->umur < minUmur) {
            minUmur = current->umur;
        }
        totalUmur += current->umur;
        jumlahKontak++;

        current = current->next;
    }

    rataUmur = (double)totalUmur / jumlahKontak;

    printf("Maksimal umur: %u\n", maxUmur);
    printf("Minimal umur: %u\n", minUmur);
    printf("Rata-rata umur: %.2f\n", rataUmur);
}

void menu12(BukuKontak *buku) {
    int choice;

    while (1) {
        printf("--------------------------------------------------\n");
        printf("\t\tAPLIKASI BUKU KONTAK\n");
        printf("--------------------------------------------------\n");
        printf("| Pilih Opsi:                                      |\n");
        printf("| 1. Undo Actions                                  |\n");
        printf("| 2. Redo Actions                                  |\n");
        printf("| 3. Exit                                          |\n");
        printf("--------------------------------------------------\n");
        printf("Pilihan Kamu: ");
        scanf("%d", &choice);
        printf("--------------------------------------------------\n");

        switch (choice) {
            case 1:
                mengundo(buku);
                break;
            case 2:
                menguredo(buku);
                break;
            case 3:
                printf("Exiting...\n");
                return; // Exit the function
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}



ptrnode createNode(char pNama[], unsigned pUmur, bool pJenis_kelamin, char pNo_telp[], char pEmail[]){
	ptrnode tmpNode = (ptrnode) malloc(sizeof(kontak)); //Alokasi memori

	//Masukin data
	tmpNode->_id = _id++;
	strcpy(tmpNode->nama, pNama);
    tmpNode->umur = pUmur;
    tmpNode->jk = pJenis_kelamin;
	strcpy(tmpNode->no_telp, pNo_telp);
	strcpy(tmpNode->email, pEmail);
	tmpNode->next = NULL;

	return tmpNode;
}

void printNode(ptrnode tmp){
	printf("%-15s: %d\n", "ID", tmp->_id);
	printf("%-15s: %s\n", "Nama", tmp->nama);
	printf("%-15s: %u\n", "Umur", tmp->umur);
	tmp->jk ? printf("%-15s: Laki-laki\n", "Jenis Kelamin") : printf("%-15s: Perempuan\n", "Jenis Kelamin");
	printf("%-15s: %s\n", "Nomor Telepon", tmp->no_telp);
	printf("%-15s: %s\n", "Alamat Email", tmp->email);
}

void SLL_init(ptrSLL tmpList){
	tmpList->head = NULL; //Inisialisasi head awalnya nunjuk ke NULL
	tmpList->size = 0; //Sizenya juga 0 karena linkedlist masih kosong
}

//curr kepanjangan dari current, artinya yang saat ini
//currList = list saat ini

void SLL_insert(ptrSLL currList, ptrnode currNode, ptrAdjList currAdjList, ptrHashTable currHashTable){
	//Kalo SLL kosong, langsung add jadi head, trus size = 1;
    if(currList->head == NULL){
		currList->size++;
		currList->head = currNode;
	}else{
		//Kalo ga kosong ya insert ke tail
		ptrnode tmp = currList->head;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currNode;
		currNode->next = NULL;
		currList->size++;

	}

	//Jangan lupa inisialisasi kontak yang baru itu sbg suatu node dalam daftar relasi
	adjList_pushBack(currAdjList, currNode->_id);

	//Ini untuk indexing id nya dengan kontaknya
	hashTable_pushBack(currHashTable, currNode->_id, currNode);
}

void SLL_popFront(ptrSLL currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}else if(currList->size == 1){

		ptrnode tmpNode = currList->head;
		currList->head = NULL;
		currList->size = 0;

		free(tmpNode);
	}else{

		ptrnode tmpNode = currList->head;

		currList->head = currList->head->next;
		tmpNode->next = NULL;
		currList->size--;

		free(tmpNode);
	}
}

void SLL_popBack(ptrSLL currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}if(currList->size == 1){
		ptrnode tmpNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tmpNode);
	}else{
		ptrnode tmpNode = currList->head;
		ptrnode prev = NULL;

		while(tmpNode->next != NULL){
			prev = tmpNode;
			tmpNode = tmpNode->next;
		}

		prev->next = NULL;
		currList->size--;

		free(tmpNode);
	}
}


void SLL_deleteNama(ptrSLL currList, char toBeDeleted[]){
	//apabila nilai yang mau dihapus ada di head, maka delete head
	if(strcmp(currList->head->nama, toBeDeleted) == 0){
		SLL_popFront(currList);
	}else{
		ptrnode cursor = currList->head;
		ptrnode tmp_node = NULL;
		int cnt = 0;

		while(cursor != NULL && strcmp(cursor->nama, toBeDeleted) != 0){
			tmp_node = cursor;
			cursor = cursor->next;
			cnt++;
		}

		//if ini untuk ngecek dia ada di akhir atau bukan
		if(cnt == currList->size){
			//kalo di akhir trus nama yang mau di hapus ada di akhir, maka delete tail
			//tapi klo gaada ya bilang aja gaada karena udh di akhir kan?
			(strcmp(tmp_node->nama, toBeDeleted) != 0) ? printf("Data tidak ditemukan, tidak ada yang dihapus!\n") : SLL_popBack(currList);
		}else{
			//ini kalo misalnya cursor gaada di akhir
			//berarti gabisa popFront atau popBack
			//harus menghapus antara 2 node

			tmp_node->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

ptrnode_1D createNode_1D(int Pnum){
	ptrnode_1D newNode = (ptrnode_1D) malloc(sizeof(Tnode_1D)); //alokasi memori

	//Masukin data
	newNode->data = Pnum;
	newNode->next = NULL;
	return newNode;
}

void SLL_1D_init(ptrSLL_1D tmpList){
	//Sama kaya SLL sebelumnya
	tmpList->head = NULL;
	tmpList->size = 0;
}

void SLL_1D_pushBack(ptrSLL_1D currList, int data){ //currList -> current List, currNode -> current node
	//Kalo SLL kosong, langsung add jadi head, trus size = 1;
	ptrnode_1D currNode = createNode_1D(data);

    if(currList->head == NULL){
		currList->size++;
		currList->head = currNode;
	}else{
		ptrnode_1D tmp = currList->head;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currNode;
		currList->size++;

	}
}

void SLL_1D_popFront(ptrSLL_1D currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}else if(currList->size == 1){
		ptrnode_1D tmpNode = currList->head;
		currList->head = NULL;
		currList->size = 0;

		free(tmpNode);
	}else{
		ptrnode_1D tmpNode = currList->head;

		currList->head = currList->head->next;
		tmpNode->next = NULL;
		currList->size--;

		free(tmpNode);
	}
}

void SLL_1D_popBack(ptrSLL_1D currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}if(currList->size == 1){
		ptrnode_1D tmpNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tmpNode);
	}else{
		ptrnode_1D tmpNode = currList->head;
		ptrnode_1D prev = NULL;

		while(tmpNode->next != NULL){
			prev = tmpNode;
			tmpNode = tmpNode->next;
		}

		prev->next = NULL;
		currList->size--;

		free(tmpNode);
	}
}

void SLL_1D_deleteNode(ptrSLL_1D currList, int idName){
	//Kurleb sama lah dgn SLL
	ptrnode_1D cursor = currList->head;

	if(cursor->data == idName){
		SLL_1D_popFront(currList);
	}else{
		ptrnode_1D cursor = currList->head;
		ptrnode_1D tmp_node = NULL;
		int cnt = 0;

		while(cursor != NULL && cursor->data != idName){
			tmp_node = cursor;
			cursor = cursor->next;
			cnt++;
		}

		if(cnt == currList->size){
			(tmp_node->data != idName) ? printf("Data tidak ditemukan, tidak ada yang dihapus!\n") : SLL_1D_popBack(currList);
		}else{
			tmp_node->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

void adjListNode_init(ptrAdjListNode currAdjListNode){
	currAdjListNode->data_list = NULL; //inisialisasi data_list (row) awalnya kosong
	currAdjListNode->next = NULL;
}

ptrAdjListNode createNode_adj(int src){
	ptrSLL_1D tmp_SLL = (ptrSLL_1D) malloc(sizeof(SLL_1D));
	SLL_1D_init(tmp_SLL);
	SLL_1D_pushBack(tmp_SLL, src);

	ptrAdjListNode tmp_adj = (ptrAdjListNode) malloc(sizeof(adjListNode));
	adjListNode_init(tmp_adj);
	tmp_adj->data_list = tmp_SLL;

	return tmp_adj;
}

void adjList_init(ptrAdjList currAdjList){
	//kurleb sama lah sama SLL
	currAdjList->head = NULL;
	currAdjList->size = 0;
}

void adjList_pushBack(ptrAdjList currAdjList, int src){
	ptrAdjListNode tmpNode = createNode_adj(src); //buat dulu BARIS/ROW nya

	//Kalau adjlist-nya kosong, langsung aja tambah baris
	if(currAdjList->head == NULL){
		currAdjList->head = tmpNode;
		currAdjList->size = 1;
	}else{
		//Kalau ga kosong, ya insert tail
		ptrAdjListNode tmp_cursor;
		tmp_cursor = currAdjList->head;

		while(tmp_cursor->next != NULL){
			tmp_cursor = tmp_cursor->next;
		}

		tmp_cursor->next = tmpNode;
		currAdjList->size++;
	}
}

//src adalah source, fin adalah final
void adjList_insertRelation(ptrAdjList currAdjList, int src, int fin){
	ptrAdjListNode cursor = currAdjList->head;

	//Cari letak baris src di adjlist-nya
	while(cursor->data_list->head->data != src){
		cursor = cursor->next;
	}

	//kalau ketemu, insert fin di baris src
	SLL_1D_pushBack(cursor->data_list, fin);
}

void adjList_deleteRelation(ptrAdjList currAdjList, int src, int fin){
	ptrAdjListNode cursor = currAdjList->head;

	//Cari letak baris src di adjlist-nya
	while(cursor->data_list->head->data != src){
		cursor = cursor->next;
	}

	//kalau ketemu, hapus fin dari baris src
	SLL_1D_deleteNode(cursor->data_list, fin);
}

ptritem createItem(int Pkey, ptrnode Pnode){
	ptritem tmp = (ptritem) malloc(sizeof(Titem)); //inisiasi pointer ke item
	ptrnode cpy_node = (ptrnode) malloc(sizeof(kontak)); //inisiasi pointer ke kontak

	//copy data di kontak ke dalam cpy_node agar indexing tidak terpengaruh saat data dihapus
	cpy_node->_id = Pnode->_id;
	strcpy(cpy_node->nama, Pnode->nama);
    cpy_node->umur = Pnode->umur;
    cpy_node->jk = Pnode->jk;
	strcpy(cpy_node->no_telp, Pnode->no_telp);
	strcpy(cpy_node->email, Pnode->email);
	cpy_node->next = NULL;

	tmp->key = Pkey;
	tmp->data = cpy_node;
	tmp->next = NULL;

	return tmp;
}

void hashTable_init(ptrHashTable currHashTable){
	//inisiasi lah ya
	currHashTable->head = NULL;
	currHashTable->capacity = 0;
}

void hashTable_pushBack(ptrHashTable currHashTable, int key, ptrnode currNode){
	ptritem currItem = createItem(key, currNode); //buat dulu itemnya

	//kalo hash table kosong, langsung add ke head, trus capacity ditambah
	if(currHashTable->head == NULL){
		currHashTable->capacity++;
		currHashTable->head = currItem;
	}else{
		//kalo ga ya insert tail
		ptritem tmp = currHashTable->head;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currItem;
		currItem->next = NULL;
		currHashTable->capacity++;
	}
}

ptrnode hashTable_getData(ptrHashTable currHashTable, int Pkey){
	ptritem cursor = currHashTable->head;

	while(cursor != NULL){
		if(cursor->key == Pkey) return cursor->data;
		cursor = cursor->next;
	}

	return NULL;
}



ptrnode merge(ptrnode firstNode, ptrnode secondNode){
    ptrnode merged = (ptrnode)malloc(sizeof(kontak));
    ptrnode temp = (ptrnode)malloc(sizeof(kontak));

    merged = temp;

    // while salah satu node menjadi NULL
    while (firstNode != NULL && secondNode != NULL) {
        if (strcmp(firstNode->nama, secondNode->nama) < 0) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }

    // sisa node di firstNode atau secondNode di-insert ke temp
    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }

    // return head dari linked list yang terurut setelah dimerge
    return merged->next;
}

// fungsi untuk mengambil node tengah
ptrnode mid_SLL(ptrnode head){
    ptrnode slow = head;
    ptrnode fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


ptrnode sortNama(ptrnode head){
    if (head->next == NULL) {
        return head;
    }

    ptrnode mid = (ptrnode)malloc(sizeof(kontak));
    ptrnode head2 = (ptrnode)malloc(sizeof(kontak));
    mid = mid_SLL(head);
    head2 = mid->next;
    mid->next = NULL; //potong jadi 2 linked list: head, head2 (head dan head2 tidak tersambung)

    //merge 2 linked list yang telah terurut
    ptrnode finalhead = merge(sortNama(head), sortNama(head2));

    return finalhead;
}

ptrnode middle(ptrnode start, ptrnode last){
    // untuk mendapatkan node tengah
    if (start == NULL)
        return NULL;
    ptrnode slow = start;
    ptrnode fast = start->next;
    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

ptrnode cariBinarySearch_nama(ptrSLL daftarKontak, char nama[]){
    ptrnode start = daftarKontak->head;
    ptrnode last = NULL;

    do{
        // temukan node tengah
        ptrnode mid = middle(start, last);

		// jika node tengah NULL
        if (mid == NULL)
            return NULL;

		// Jika x ditemukan di node tengah
        if (strcmp(mid->nama, nama) == 0)
            return mid;

		// Jika nilai x lebih dari node tengah
        else if (strcmp(mid->nama, nama) < 0)
            start = mid->next;

		// Jika nilai x kurang dari node tengah
        else
            last = mid;
    } while (last == NULL || last != start);

	// jika tidak ditemukan
    return NULL;
}

ptrnode cariLinearSearch_noTelp(ptrSLL daftarKontak, char no_telp[]) {
    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        if (strcmp(current->no_telp, no_telp) == 0) {
            return current; // No telepon ditemukan
        }
        current = current->next;
    }
    return NULL; // No telepon tidak ditemukan
}

ptrnode cariLinearSearch_email(ptrSLL daftarKontak, char email[]) {
    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            return current; // Email ditemukan
        }
        current = current->next;
    }
    return NULL; // Email tidak ditemukan
}

ptrnode cariWildcardSearch_nama(ptrSLL daftarKontak, char* nama_pattern) {
    ptrnode current = daftarKontak->head;
    size_t pattern_length = strlen(nama_pattern);

    // Jika pattern berakhir dengan '*', potong karakter tersebut untuk pencocokan
    if (nama_pattern[pattern_length - 1] == '*') {
        pattern_length--;
    }

    while (current != NULL) {
        // Membandingkan awal dari nama dengan pattern
        if (strncmp(current->nama, nama_pattern, pattern_length) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

ptrnode cariWildcardSearch_email(ptrSLL daftarKontak, char* email_pattern) {
    ptrnode current = daftarKontak->head;
    size_t pattern_length = strlen(email_pattern);

    // Jika pattern berakhir dengan '*', potong karakter tersebut untuk pencocokan
    if (email_pattern[pattern_length - 1] == '*') {
        pattern_length--;
    }

    while (current != NULL) {
        if (strncmp(current->email, email_pattern, pattern_length) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

ptrnode cariWildcardSearch_noTelp(ptrSLL daftarKontak, char* no_telp_pattern) {
    ptrnode current = daftarKontak->head;
    size_t pattern_length = strlen(no_telp_pattern);

    // Jika pattern berakhir dengan '*', potong karakter tersebut untuk pencocokan
    if (no_telp_pattern[pattern_length - 1] == '*') {
        pattern_length--;
    }

    while (current != NULL) {
        if (strncmp(current->no_telp, no_telp_pattern, pattern_length) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}




int cariID(ptrSLL daftarKontak, char nama[]){
	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	return tmp == NULL ? -1 : tmp->_id;
}


void editProp(ptrSLL daftarKontak, int flag, int _id, ptrHashTable indeksID){

	char in[20];
	int input=0;

	if(flag < 1 || flag > 5){
		printf("Masukan salah!\n");
		getchar();
	}else{
		ptrnode tmp = daftarKontak->head;

		while(tmp->next != NULL && tmp->_id != _id){
			tmp = tmp->next;
		}

		printf("Masukkan data baru: ");
		switch (flag){
			//Nama, No_telp, Email
			case 1:
				getchar();
				gets(in);

				strcpy(tmp->nama, in);
				strcpy(hashTable_getData(indeksID, _id)->nama, in);
				break;
			case 4:
				getchar();
				gets(in);

				strcpy(tmp->no_telp, in);
				strcpy(hashTable_getData(indeksID, _id)->no_telp, in);
				break;
			case 5:
				getchar();
				gets(in);

				strcpy(tmp->no_telp, in);
				strcpy(hashTable_getData(indeksID, _id)->email, in);
				break;
			case 2:
				scanf("%d", &input);

				tmp->umur = input;
				hashTable_getData(indeksID, _id)->umur = input;
				break;
			case 3:
				//Jenis Kelamin
				scanf("%d", &input);

				tmp->jk = (bool) input;
				hashTable_getData(indeksID, _id)->jk = (bool) input;
				break;
		}

		printf("Data berhasil diperbarui!\n");
	}
}

void save(ptrSLL daftarKontak, char *namafile) {
    FILE *filecontact = fopen(namafile, "w");
    if (filecontact == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        char jenisKelamin = (current->jk) ? 'L' : 'P'; // 'L' untuk laki-laki, 'P' untuk perempuan

        fprintf(filecontact, "| %-20s | %-4d | %-1c | %-14s | %-20s |\n",
                current->nama, current->umur,
                jenisKelamin, current->no_telp,
                current->email);

        current = current->next;
    }

    fclose(filecontact);
    printf("--------------------------------------------------\n");
    printf("| Kontak berhasil disimpan ke dalam file: %s\n", namafile);
}


void load(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID, char *namafile) {
    FILE *file = fopen(namafile, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char nama[20], no_telp[15], email[20];
    unsigned umur;
    char jk; // untuk membaca jenis kelamin sebagai karakter

    while (fscanf(file, " | %19[^|] | %4u | %c | %14[^|] | %19[^|] |\n",
                  nama, &umur, &jk, no_telp, email) == 5) {
        if (umur > 150) { // Validasi umur
            printf("Umur tidak valid.\n");
            continue;
        }
        bool jenisKelamin = (jk == 'L' || jk == 'l'); // Mengubah kembali menjadi bool
        ptrnode newNode = createNode(nama, umur, jenisKelamin, no_telp, email);
		SLL_insert(daftarKontak, newNode, daftarRelasi, indeksID);
		daftarKontak->head = sortNama(daftarKontak->head);
        if (newNode == NULL) {
            printf("Gagal membuat kontak baru.\n");
            continue;
        }

    }

    fclose(file);
    printf("--------------------------------------------------\n");
    printf("| Kontak berhasil dimuat dari file: %s\n", namafile);
}

// Fungsi untuk menghitung maksimal, minimum, dan rata-rata umur
void hitungUmur(ptrSLL daftarKontak, unsigned *maxUmur, unsigned *minUmur, double *rataUmur) {
    if (daftarKontak == NULL || daftarKontak->head == NULL) {
        printf("Daftar kontak kosong.\n");
        return;
    }

    *maxUmur = 0; // Inisialisasi dengan nilai minimum mungkin
    *minUmur = UINT_MAX; // Inisialisasi dengan nilai maksimum mungkin
    *rataUmur = 0.0;
    unsigned totalUmur = 0;
    unsigned jumlahKontak = 0;

    ptrnode current = daftarKontak->head;
    while (current != NULL) {
        if (current->umur > *maxUmur) {
            *maxUmur = current->umur;
        }
        if (current->umur < *minUmur) {
            *minUmur = current->umur;
        }
        totalUmur += current->umur;
        jumlahKontak++;

        current = current->next;
    }

    *rataUmur = (double)totalUmur / jumlahKontak;
}

