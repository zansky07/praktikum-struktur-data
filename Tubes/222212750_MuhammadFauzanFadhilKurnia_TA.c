// MUHAMMAD FAUZAN FADHIL KURNIA
// 222212750
// 2KS2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct contact{
    char nama[30];
    int umur;
    char jeniskelamin;
    char notelp[14];
    char email[30];
    
};

typedef struct contact *kontak;
int size;
int main();
void display();
kontak Kontak[N];

int undoIndex = 0;
int redoIndex = 0;
struct contact undoBuffer[N];
struct contact redoBuffer[N];


kontak newdata(kontak temp){

    kontak newkontak = (kontak)malloc(sizeof(struct contact));


    return newkontak;
}

void forminput(int jlhinput, struct contact undoBuffer[], struct contact redoBuffer[], int *undoIndex, int *redoIndex){
    
    int i;
    kontak temp;
    char buffer[100]; // Buffer tambahan untuk membersihkan newline character

    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tTAMBAH DAFTAR CONTACT\t\t |\n");
    printf("--------------------------------------------------\n");
    
    for( i = 0; i < jlhinput; i++){
     
        kontak temp = (kontak)malloc(sizeof(struct contact));
        printf("| Kontak %d\n", i+1);
        printf("| Nama : ");
        fgets(buffer, sizeof(buffer), stdin); // Membersihkan newline character dari buffer
        fgets(temp->nama, sizeof(temp->nama), stdin);
        temp->nama[strcspn(temp->nama, "\n")] = '\0'; // Menghilangkan newline character
        printf("| Umur : ");
        scanf("%d", &temp->umur);
        printf("| Jenis Kelamin (L/P) : ");
        scanf(" %c", &temp->jeniskelamin);
        printf("| Nomor Telepon : ");
        scanf("%s", temp->notelp);
        printf("| Email : ");
        scanf("%s", temp-> email);

        // Menyimpan salinan data ke buffer undo
        memcpy(&undoBuffer[*undoIndex], temp, sizeof(kontak) * N);
        (*undoIndex)++;
    
        Kontak[size] = temp;
        size++;

        printf("--------------------------------------------------\n");
    }
}

void delete(int criteria, struct contact undoBuffer[], struct contact redoBuffer[], int *undoIndex, int *redoIndex){

    if(size == 0){
        printf("Data Kontak Tidak Tersedia\n");
        return;
    }

    int found = 0;
     char target[30];
     int target2;
     char target3;
     char target4[14];
     char target5[30];

    switch(criteria){
        case 1 :
               
                printf("Masukkan Nama Daftar Kontak yang ingin Anda Hapus : ");
               getchar(); // Membersihkan buffer stdin
               fgets(target, sizeof(target), stdin);
               target[strcspn(target, "\n")] = '\0';    
                    for (int i=0;i<size;i++){
                    if(strcmp(Kontak[i]->nama , target) == 0) {
                        // Menyimpan salinan data ke buffer undo
                        memcpy(&undoBuffer[*undoIndex], Kontak, sizeof(kontak) * N);
                        (*undoIndex)++;
                        
                        found++;
                        free(Kontak[i]);
                        for(int j = i; j < size; j++){
                        Kontak[j] =Kontak[j+1];
                        }
                    size--;
                    }
                }
                
                break;
        case 2 :
                
                printf("Masukkan Umur Daftar Kontak yang ingin Anda Hapus : ");
                scanf("%d",&target2);    
                    for (int i=0;i<size;i++){
                    if(Kontak[i]->umur==target2) {
                        // Menyimpan salinan data ke buffer undo
                        memcpy(&undoBuffer[*undoIndex], Kontak, sizeof(kontak) * N);
                        (*undoIndex)++;

                        found++;
                        free(Kontak[i]);
                        for(int j = i; j < size; j++){
                        Kontak[j] =Kontak[j+1];
                        }
                        size--;
                    }
                }
                
                break;
        case 3 :
                
                printf("Masukkan Jenis Kelamin Daftar Kontak yang ingin Anda Hapus : ");
                scanf(" %c",&target);    
                    for (int i=0;i<size;i++){
                    if(Kontak[i]->jeniskelamin == target3)  {
                        // Menyimpan salinan data ke buffer undo
                        memcpy(&undoBuffer[*undoIndex], Kontak, sizeof(kontak) * N);
                        (*undoIndex)++;
                        
                        found++;
                        free(Kontak[i]);
                        for(int j = i; j < size; j++){
                        Kontak[j] =Kontak[j+1];
                        }
                    size--;
                    }
                }
                
                break;
        case 4 :
                
                printf("Masukkan Nomor Telepon Daftar Kontak yang ingin Anda Hapus : ");
                scanf("%s",target4);    
                    for (int i=0;i<size;i++){
                    if(strcmp(Kontak[i]->notelp , target4) == 0) {
                        // Menyimpan salinan data ke buffer undo
                        memcpy(&undoBuffer[*undoIndex], Kontak, sizeof(kontak) * N);
                        (*undoIndex)++;
                        
                        found++;
                        free(Kontak[i]);
                        for(int j = i; j < size; j++){
                        Kontak[j] =Kontak[j+1];
                        }
                    size--;
                    }
                }
                
                break;
        case 5 :
                
                printf("Masukkan Email Daftar Kontak yang ingin Anda Hapus : ");
                scanf("%s",target5);    
                    for (int i=0;i<size;i++){
                    if(strcmp(Kontak[i]->email , target5) == 0) {
                        // Menyimpan salinan data ke buffer undo
                        memcpy(&undoBuffer[*undoIndex], Kontak, sizeof(kontak) * N);
                        (*undoIndex)++;
                        
                        found++;
                        free(Kontak[i]);
                        for(int j = i; j < size; j++){
                        Kontak[j] =Kontak[j+1];
                        }
                    size--;
                    }
                }
                
                break;
    }



    if (found == 0){
        printf("Data Tidak Ditemukan\n");
    }
}

void menudelete(){
    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU DELETE\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Hapus Berdasarkan Nama\t\t\t |\n");
    printf("| 2. Hapus Berdasarkan Umur\t\t\t |\n");
    printf("| 3. Hapus Berdasarkan Jenis Kelamin\t\t |\n");
    printf("| 4. Hapus Berdasarkan No Telepon\t\t |\n");
    printf("| 5. Hapus Berdasarkan Email\t\t\t |\n");
    printf("| 6. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 7. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");

    
        switch(choice){
            case 1: delete(1, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                    break;
            case 2: delete(2, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                    break;
            case 3: delete(3, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                    break;
            case 4: delete(4, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                    break;
            case 5: delete(5, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                    break;
            case 6: main();
                    break;
            case 7: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}

void edit (kontak data[], struct contact undoBuffer[], struct contact redoBuffer[], int *undoIndex, int *redoIndex){
    char oldname[30];
    int found = 0;
    char buffer[100]; // Buffer tambahan untuk membersihkan newline character

    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tEDIT DAFTAR CONTACT\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| Masukkan Nama Kontak yang ingin Anda Ubah : ");
    fgets(buffer, sizeof(buffer), stdin); // Membersihkan newline character dari buffer
    fgets(oldname, sizeof(oldname), stdin);
    oldname[strcspn(oldname, "\n")] = '\0'; // Menghilangkan newline character
    printf("--------------------------------------------------\n");
    for (int i=0;i<size;i++){
     if(strcmp(data[i]->nama, oldname) == 0) {
        found++;
       
        // Backup data for undo
        memcpy(&undoBuffer[*undoIndex], data, sizeof(kontak) * N);
        (*undoIndex)++;

        printf("| Kontak %d\n", i+1);
        printf("| Nama : %s\n",data[i]->nama);
        printf("| Umur : %d\n",data[i]->umur);
        printf("| Jenis Kelamin (L/P) : %c\n", data[i]->jeniskelamin);
        printf("| Nomor Telepon : %s\n", data[i]->notelp);
        printf("| Email : %s\n",data[i]->email);



        printf("--------------------------------------------------\n");
        printf("| Ubah Kontak %d\n", i+1);
        printf("| Nama : ");
        fgets(data[i]->nama, sizeof(data[i]->nama), stdin);
        data[i]->nama[strcspn(data[i]->nama, "\n")] = '\0'; // Menghilangkan newline character
        printf("| Umur : ");
        scanf("%d", &data[i]->umur);
        printf("| Jenis Kelamin (L/P) : ");
        scanf(" %c", &data[i]->jeniskelamin);
        printf("| Nomor Telepon : ");
        scanf("%s", data[i]->notelp);
        printf("| Email : ");
        scanf("%s", data[i]-> email);
        printf("--------------------------------------------------\n");
     }
 }
    if(found == 0){
        printf(" Data Kontak Tidak Ditemukan\n");
    }
}

void hasilsearch(kontak data){
    printf("| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
    data->nama, data->umur, data->jeniskelamin,
    data->notelp, data->email);
}

void headertable(){
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("|\t\t\t\t\tDAFTAR CONTACT\t\t\t\t\t       |\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("| %-30s | %-4s | %-2s | %-14s | %-30s |\n", "Nama", "Umur", "JK", "No. Telepon", "Email");
    printf("| %s | %s | %s | %s | %s |\n", "------------------------------", "----", "--", "--------------", "------------------------------");
}

void  search(int criteria){
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;
    char target_notelp[14];
    char target_email[30];

 
    switch(criteria){
    case 1 :
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 2 :
            printf("Masukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
            headertable();
            for (int i=0;i<size;i++){
                if(Kontak[i]->umur==target_umur) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 3 :
            printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 4 :
            printf("Masukkan Nomor Telepon Kontak yang ingin Anda cari : ");
            scanf("%s", target_notelp);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->notelp, target_notelp) == 0) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 5 :
            printf("Masukkan Email Kontak yang ingin Anda cari : ");
            scanf("%s", target_email);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->email, target_email) == 0) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    }
    
        if(found == 0){
            printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
            printf("------------------------------------------------------------------------------------------------\n");
        }
}

void menusearchtunggal(){
    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SEARCH TUNGGAL\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama\t\t\t |\n");
    printf("| 2. Search Berdasarkan Umur\t\t\t |\n");
    printf("| 3. Search Berdasarkan Jenis Kelamin (L/P)\t |\n");
    printf("| 4. Search Berdasarkan Nomor Telepon\t\t |\n");
    printf("| 5. Search Berdasarkan Email\t\t\t |\n");
    printf("| 6. Kembali ke Menu Utama\t\t\t |\n");
    printf("| 7. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");
   
        switch(choice){
            case 1: search(1);
                    break;
            case 2: search(2);
                    break;
            case 3: search(3);
                    break;
            case 4: search(4);
                    break;
            case 5: search(5);
                    break;
            case 6: main();
                    break;
            case 7: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}

void searchand(int criteria){
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;

 
    switch(criteria){
    case 1 :
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';

            printf("Masukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 && Kontak[i]->umur==target_umur) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 2 :
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';
            
            printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 && Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 3 :
            printf("Masukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
          
            printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(Kontak[i]->umur==target_umur && Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 4 :
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';

            printf("\nMasukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
          
            printf("\nMasukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 && Kontak[i]->umur==target_umur && Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    }
    
        if(found == 0){
            printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
            printf("------------------------------------------------------------------------------------------------\n");
        }
}


void menusearchand(){
    
    int choice;
    printf("\t\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------------------------------\n");
    printf("|\t\t\t\tMENU SEARCH AND\t\t\t\t |\n");
    printf("--------------------------------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama dan Umur\t\t\t\t\t |\n");
    printf("| 2. Search Berdasarkan Nama dan Jenis Kelamin\t\t\t\t |\n");
    printf("| 3. Search Berdasarkan Umur dan Jenis Kelamin\t\t\t\t |\n");
    printf("| 4. Search Berdasarkan Nama, Umur, dan Jenis Kelamin\t\t\t |\n");
    printf("| 5. Kembali ke Menu Utama\t\t\t\t\t\t |\n");
    printf("| 6. Keluar\t\t\t\t\t\t\t\t |\n");
    printf("--------------------------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------------------------------\n");
   
        switch(choice){
            case 1: searchand(1);
                    break;
            case 2: searchand(2);
                    break;
            case 3: searchand(3);
                    break;
            case 4: searchand(4);
                    break;
            case 5: main();
                    break;
            case 6: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}

void searchor(int criteria){
    int found = 0;
    char target_nama[30];
    int target_umur;
    char target_jk;

 
    switch(criteria){
    case 1 : 
            // NAMA OR UMUR
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';

            printf("Masukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 || Kontak[i]->umur==target_umur) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 2 :
            // NAMA OR JENIS KELAMIN
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';

            printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 || Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 3 :
            // UMUR OR JENIS KELAMIN
            printf("Masukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
            printf("Masukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(Kontak[i]->umur==target_umur || Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 4 :
            // NAMA OR UMUR OR JENIS KELAMIN
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target_nama, sizeof(target_nama), stdin);
            target_nama[strcspn(target_nama, "\n")] = '\0';

            printf("\nMasukkan Umur Kontak yang ingin Anda cari : ");
            scanf("%d", &target_umur);
            printf("\nMasukkan Jenis Kelamin Kontak yang ingin Anda cari : ");
            scanf(" %c", &target_jk);
            headertable();
            for (int i=0;i<size;i++){
                if(strcmp(Kontak[i]->nama, target_nama) == 0 || Kontak[i]->umur==target_umur || Kontak[i]->jeniskelamin==target_jk) {
                found++;
                hasilsearch(Kontak[i]);
                }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    }
    
        if(found == 0){
            printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
            printf("------------------------------------------------------------------------------------------------\n");
        }
}


void menusearchor(){
    
    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
     printf("--------------------------------------------------------------------------\n");
    printf("|\t\t\tMENU SEARCH OR\t\t\t\t\t |\n");
     printf("--------------------------------------------------------------------------\n");
    printf("| 1. Search Berdasarkan Nama atau Umur\t\t\t\t\t |\n");
    printf("| 2. Search Berdasarkan Nama atau Jenis Kelamin\t\t\t\t |\n");
    printf("| 3. Search Berdasarkan Umur atau Jenis Kelamin\t\t\t\t |\n");
    printf("| 4. Search Berdasarkan Nama, Umur, atau Jenis Kelamin\t\t\t |\n");
    printf("| 5. Kembali ke Menu Utama\t\t\t\t\t\t |\n");
    printf("| 6. Keluar\t\t\t\t\t\t\t\t |\n");
     printf("--------------------------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
     printf("--------------------------------------------------------------------------\n");
   
        switch(choice){
            case 1: searchor(1);
                    break;
            case 2: searchor(2);
                    break;
            case 3: searchor(3);
                    break;
            case 4: searchor(4);
                    break;
            case 5: main();
                    break;
            case 6: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}

void  searchwildcard(int criteria){
    int found = 0, cocok = 0;
    char target[30];
 
    switch(criteria){
    case 1 :
            // WILDCARD NAMA
            printf("Masukkan Nama Kontak yang ingin Anda cari : ");
            getchar(); // Membersihkan buffer stdin
            fgets(target, sizeof(target), stdin);
            target[strcspn(target, "\n")] = '\0';

            headertable();
                
            if (target[strlen(target)-1] != '*') {
                    break;
            }    

            for (int i=0;i<size;i++){
                cocok = 1;
                for(int j = 0; j < strlen(target) - 1; j++){
                    if(  target[j] != Kontak[i]->nama[j] ) {
                    cocok = 0;
                    break;
                }
                }
                if (cocok != 0 ) {
                    found++;
                    hasilsearch(Kontak[i]);
            }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 2 :
            // WILDCARD NOMOR TELEPON
            printf("Masukkan Nomor Telepon Kontak yang ingin Anda cari : ");
            scanf("%s", target);
            headertable();
                
            if (target[strlen(target)-1] != '*') {
                    break;
            }    

            
            for (int i=0;i<size;i++){
                cocok = 1;
                for(int j = 0; j < strlen(target) - 1; j++){
                    if(  target[j] != Kontak[i]->notelp[j] ) {
                    cocok = 0;
                    break;
                }
                }
                if (cocok != 0 ) {
                    found++;
                    hasilsearch(Kontak[i]);
            }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    case 3 :
            printf("Masukkan Email Kontak yang ingin Anda cari : ");
            scanf("%s", target);
            headertable();
                
            if (target[strlen(target)-1] != '*') {
                    break;
            }    

            
            for (int i=0;i<size;i++){
                cocok = 1;
                for(int j = 0; j < strlen(target) - 1; j++){
                    if(  target[j] != Kontak[i]->email[j] ) {
                    cocok = 0;
                    break;
                }
                }
                if (cocok != 0 ) {
                    found++;
                    hasilsearch(Kontak[i]);
            }
            }
            printf("------------------------------------------------------------------------------------------------\n");
            break;
    }
    
        if(found == 0 && cocok == 0){
            if (target[strlen(target)-1] != '*') {
                    printf("| \t\t\tKriteria tidak valid (wajib diakhiri *)\t\t\t |\n");
                    
            }    else 
            printf("|\t\t\t\tData Kontak Tidak Ditemukan\t\t\t\t       |\n");
            printf("------------------------------------------------------------------------------------------------\n");
        }
}

void menusearchwildcard(){
    
    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
     printf("------------------------------------------------------------------\n");
    printf("|\t\tMENU SEARCH WILDCARD\t\t\t\t |\n");
     printf("------------------------------------------------------------------\n");
    printf("| 1. Search Wildcard Berdasarkan Nama\t\t\t\t |\n");
    printf("| 2. Search Wildcard Berdasarkan Nomor Telepon\t\t\t |\n");
    printf("| 3. Search Wildcard Berdasarkan Email\t\t\t\t |\n");
    printf("| 4. Kembali ke Menu Utama\t\t\t\t\t |\n");
    printf("| 5. Keluar\t\t\t\t\t\t\t |\n");
     printf("------------------------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice);
     printf("------------------------------------------------------------------\n");
   
        switch(choice){
            case 1: searchwildcard(1);
                    break;
            case 2: searchwildcard(2);
                    break;
            case 3: searchwildcard(3);
                    break;
            case 4: main();
                    break;
            case 5: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}

void menusearch(){
    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
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
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");
   
        switch(choice){
            case 1: menusearchtunggal();
                    break;
            case 2: menusearchand();
                    break;
            case 3: menusearchor();
                    break;
            case 4: menusearchwildcard();
                    break;
            case 5: main();
                    break;
            case 6: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }
}


void sorting(int criteria ,int criteria2) {
if ( size == 0){
    printf("Daftar Kontak Kosong\n");
    return;
    
}
    switch(criteria){

        case 1 :    //Sorting Berdasarkan Nama
                switch(criteria2){
                    //Menaik
                    case 1 : 
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->nama , Kontak[j + 1]->nama) > 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                    //Menurun
                    case 2 :
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->nama , Kontak[j + 1]->nama) < 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                }
                printf("Kontak berhasil diurutkan berdasarkan nama.\n");
                break;
        case 2 :    //Sorting Berdasarkan Umur
                switch(criteria2){
                    //Menaik
                    case 1 : 
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (Kontak[j]->umur > Kontak[j + 1]->umur) {
                                        // Swap contacts if they are in the wrong order
                                        kontak temp = Kontak[j];
                                        Kontak[j] = Kontak[j + 1];
                                        Kontak[j + 1] = temp;
                                    }
                                }
                            }
                            break;
                    //Menurun
                    case 2 :
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (Kontak[j]->umur < Kontak[j + 1]->umur) {
                                        // Swap contacts if they are in the wrong order
                                        kontak temp = Kontak[j];
                                        Kontak[j] = Kontak[j + 1];
                                        Kontak[j + 1] = temp;
                                    }
                                }
                            }
                            break;
                }
                printf("Kontak berhasil diurutkan berdasarkan umur.\n");
                break;
        case 3 :    //Sorting Berdasarkan Jenis Kelamin
                switch(criteria2){
                    //Menaik
                    case 1 : 
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (Kontak[j]->jeniskelamin > Kontak[j + 1]->jeniskelamin)  {
                                        // Swap contacts if they are in the wrong order
                                        kontak temp = Kontak[j];
                                        Kontak[j] = Kontak[j + 1];
                                        Kontak[j + 1] = temp;
                                    }
                                }
                            }
                            break;
                    //Menurun
                    case 2 :
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (Kontak[j]->jeniskelamin < Kontak[j + 1]->jeniskelamin)  {
                                        // Swap contacts if they are in the wrong order
                                        kontak temp = Kontak[j];
                                        Kontak[j] = Kontak[j + 1];
                                        Kontak[j + 1] = temp;
                                    }
                                }
                            }
                            break;
                }
                printf("Kontak berhasil diurutkan berdasarkan jenis kelamin.\n");
                break;
        case 4 :    //Sorting Berdasarkan Nomor Telepon
                switch(criteria2){
                    //Menaik
                    case 1 : 
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->notelp , Kontak[j + 1]->notelp) > 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                    //Menurun
                    case 2 :
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->notelp , Kontak[j + 1]->notelp) < 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                }
                printf("Kontak berhasil diurutkan berdasarkan nomor telepon.\n");
                break;
        case 5 :    //Sorting Berdasarkan Email
                switch(criteria2){
                    //Menaik
                    case 1 : 
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->email , Kontak[j + 1]->email) > 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                    //Menurun
                    case 2 :
                            for (int i = 0; i < size - 1; i++) {
                                for (int j = 0; j < size - i - 1; j++) {
                                    if (strcmp(Kontak[j]->email , Kontak[j + 1]->email) < 0) {
                                    // Swap contacts if they are in the wrong order
                                    kontak temp = Kontak[j];
                                    Kontak[j] = Kontak[j + 1];
                                    Kontak[j + 1] = temp;
                                     }
                                }
                            }
                            break;
                }
                printf("Kontak berhasil diurutkan berdasarkan email.\n");
                break;
    
    }

   
}

void menusorting(){
    int choice;
    int choice2;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
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

    if(choice > 0 && choice < 6){
    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\tMENU SORTING\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Sorting Menaik (Ascending)\t\t\t |\n");
    printf("| 2. Sorting Menurun (Descending)\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Kamu : ");
    scanf("%d",&choice2);
    printf("--------------------------------------------------\n");
    }
        switch(choice){
            case 1: //Sorting Berdasarkan Nama
                    switch(choice2){
                        // Menaik
                    case 1 : sorting(1,1);
                             break;
                        // Menurun  
                    case 2 : sorting(1,2);
                             break;
                     default : printf("Input Tidak Valid\n");
                             break;
                    }
                    break;
            case 2: //Sorting Berdasarkan Umur
                    switch(choice2){
                        // Menaik
                    case 1 : sorting(2,1);
                             break;
                        // Menurun
                    case 2 : sorting(2,2);
                             break;
                     default : printf("Input Tidak Valid\n");
                             break;
                    }
                    break;
            case 3: //Sorting Berdasarkan JK
                    switch(choice2){
                        //Menaik
                    case 1 : sorting(3,1);
                             break;
                        //Menurun
                    case 2 : sorting(3,2);
                             break;
                    default : printf("Input Tidak Valid\n");
                             break;
                    }
                    break;
            case 4: //Sorting Berdasarkan No Telepon
                    switch(choice2){
                        //Menaik
                    case 1 : sorting(4,1);
                             break;
                        //Menurun
                    case 2 : sorting(4,2);
                             break;
                    default : printf("Input Tidak Valid\n");
                              break;
                    }
                    break;
            case 5: //Sorting Berdasarkan Email
                    switch(choice2){
                        //Menaik
                    case 1 : sorting(5,1);
                             break;
                        //Menurun
                    case 2 : sorting(5,2);
                             break;
                    default : printf("Input Tidak Valid\n");
                             break;
                    }
                    break;
            case 6: main();
                    break;
            case 7: exit(0);
                    break;
            default : printf("Input Tidak Valid\n");
                     break;
        }

}

void save(char *namafile){
    FILE *filecontact = fopen(namafile, "w");
    
    if (filecontact == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(filecontact, "| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
                Kontak[i]->nama, Kontak[i]->umur,
                Kontak[i]->jeniskelamin, Kontak[i]->notelp,
                Kontak[i]->email);
    }

    fclose(filecontact);
    printf("Kontak berhasil disimpan ke dalam file: %s\n", namafile);
}

void load(char *namafile) {
    FILE *file = fopen(namafile, "r");
    if (file == NULL) {
        printf("Terjadi Kesalahan Saat Membuka atau Membaca File.\n");
        return;
    }
    
 char line[256]; // Sesuaikan dengan panjang maksimum baris
    while (fgets(line, sizeof(line), file) != NULL) {
        kontak temp = newdata(Kontak[size]);

        if (sscanf(line, "| %29[^|] | %d | %c | %13[^|] | %29[^|] |",
                   temp->nama, &temp->umur, &temp->jeniskelamin,
                   temp->notelp, temp->email) == 5) {
            Kontak[size] = temp;
            size++;
        } else {
            free(temp);
        }
    }

    fclose(file);
    printf("Kontak berhasil dimuat dari file: %s\n", namafile);
}

void aggregate(int criteria){

int min_idx, max_idx,total;
float rerata;

    switch(criteria){
        // maksimum
        case 1: max_idx = 0;
                for(int i = 1; i < size ; i++){
                    if( Kontak[i]->umur > Kontak[max_idx]->umur)
                    max_idx = i;
                }
                printf("Kontak Tertua mempunyai umur :%d \n", Kontak[max_idx]->umur);
                printf("Data Kontak Tertua : \n");
                headertable();
                hasilsearch(Kontak[max_idx]);
                break;
        // minimum
        case 2: min_idx = 0;
                for(int i = 1; i < size ; i++){
                    if( Kontak[i]->umur < Kontak[min_idx]->umur)
                    min_idx = i;
                }
                printf("Kontak Termuda mempunyai umur :%d \n", Kontak[min_idx]->umur);
                printf("Data Kontak Termuda : \n");
                headertable();
                hasilsearch(Kontak[min_idx]);
                break;
        // average
        case 3: total = 0;
                for(int i = 0; i < size ; i++){
                    total = total + Kontak[i]->umur;
                }
                rerata = total / size;
                printf("Rata- Rata Umur Kontak adalah : %.2f tahun\n", rerata);
                break;
    }
}


void menuaggregat(){

    int choice;
        printf("\t\tAPLIKASI CONTACT BOOK\n");
        printf("--------------------------------------------------\n");
        printf("|\t\tMENU AGGREGATE\t\t\t |\n");
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
                case 1: aggregate(1);
                        break;
                case 2: aggregate(2);
                        break;
                case 3: aggregate(3);
                        break;
                case 4: main();
                        break;
                case 5: exit(0);
                        break;
                default : printf("Input Tidak Valid\n");
                     break;
            }

}

void undo() {
    if (undoIndex > 0) {
        undoIndex--;
        memcpy(&redoBuffer[redoIndex], &Kontak, sizeof(kontak) * N );
        memcpy(&Kontak, &undoBuffer[undoIndex], sizeof(kontak) * N);
        redoIndex++;
        size--;
        printf("Undo berhasil.\n");
    } else {
        printf("Undo tidak memungkinkan. Tidak ada tindakan sebelumnya.\n");
    }
}

void redo() {
    if (redoIndex > 0) {
        redoIndex--;
        memcpy(&undoBuffer[undoIndex], &Kontak, sizeof(kontak) * N);
        memcpy(&Kontak, &redoBuffer[redoIndex], sizeof(kontak) * N);
        undoIndex++;
        size++;
        printf("Redo berhasil.\n");
    } else {
        printf("Redo tidak memungkinkan. Tidak ada tindakan yang belum terselesaikan.\n");
    }
}

void buat_tabel_relasi(int relasi_kontak[N][N], kontak daftar_kontak[N], int jumlah_kontak) {
    printf("-------------------------------------------------------------------------\n");
    printf("|                          BUAT TABEL RELASI                            |\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\nMasukkan relasi antar kontak:\n");
    for (int i = 0; i < jumlah_kontak; i++) {
        for (int j = 0; j < jumlah_kontak; j++) {
            printf("Apakah %s memiliki hubungan dengan %s? (1 (YA) / 0 (TIDAK)): ", daftar_kontak[i]->nama, daftar_kontak[j]->nama);
            scanf("%d", &relasi_kontak[i][j]);
        }
    }
    printf("-------------------------------------------------------------------------\n\n");
}

void tampilkan_tabel_relasi(int relasi_kontak[N][N], kontak daftar_kontak[N], int jumlah_kontak) {
    printf("----------------------------------------------------------\n");
    printf("|                    TABEL RELASI                        |\n");
    printf("----------------------------------------------------------\n\n");
    printf("| Kontak\t\t|");
    
    for (int i = 0; i < jumlah_kontak; i++) {
        printf("%22s         |", daftar_kontak[i]->nama);
    }
    
    printf("\n|-----------------------|");

    for (int i = 0; i < jumlah_kontak; i++) {
        printf("-------------------------------|");
    }
    
    printf("\n");

    for (int i = 0; i < jumlah_kontak; i++) {
        printf("| %-21s |", daftar_kontak[i]->nama);
        
        for (int j = 0; j < jumlah_kontak; j++) {
            printf("%22d         |", relasi_kontak[i][j]);
        }
        
        printf("\n");
    }

}

void display(){

   headertable();

    for (int i = 0; i<size; i++){
    printf("| %-30s | %-4d | %-2c | %-14s | %-30s |\n",
               Kontak[i]->nama, Kontak[i]->umur, Kontak[i]->jeniskelamin,
               Kontak[i]->notelp, Kontak[i]->email);
    }
    printf("------------------------------------------------------------------------------------------------\n");
}

int menu(){

    int choice;
    printf("\t\tAPLIKASI CONTACT BOOK\n");
    printf("--------------------------------------------------\n");
    printf("|\t\t\tMENU\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Tampilkan Contact\t\t\t\t |\n");
    printf("| 2. Tambah Contact\t\t\t\t |\n");
    printf("| 3. Edit Contact\t\t\t\t |\n");
    printf("| 4. Hapus Contact\t\t\t\t |\n");
    printf("| 5. Cari Contact\t\t\t\t |\n");
    printf("| 6. Urutkan Contact\t\t\t\t |\n");
    printf("| 7. Save Data Contact\t\t\t\t |\n");
    printf("| 8. Load Data Contact\t\t\t\t |\n");
    printf("| 9. Fungsi Aggregate\t\t\t\t |\n");
    printf("| 10. Undo\t\t\t\t\t |\n");
    printf("| 11. Redo\t\t\t\t\t |\n");
    printf("| 12. Buat Tabel Relasi\t\t\t\t |\n");
    printf("| 13. Tampilkan Tabel Relasi\t\t\t |\n");
    printf("| 14. Keluar\t\t\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf(" Pilihan Anda : ");
    scanf("%d",&choice);
    printf("--------------------------------------------------\n");

    return choice;
}


int main(){
    int choice, c, jlhinput;
    char namafile[N];
     int relasi_kontak[N][N];
    Kontak[size] = newdata(Kontak[size]);
    do{
        choice = menu();
    
    switch(choice){
        case 1 : display();
                 system("pause");
                 break;
        
        case 2 : printf("Masukkan jumlah kontak yang ingin ditambahkan : ");
                 scanf("%d",&jlhinput);
                 if(jlhinput <=0 || jlhinput > N){
                    printf("Inputan Tidak Valid\n");
                    break;
                 }
                 forminput(jlhinput, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                 break;
        case 3 : edit(Kontak, undoBuffer, redoBuffer, &undoIndex, &redoIndex);
                 break;
        case 4 : menudelete();
                 break;
        case 5 : menusearch();
                  break;
        case 6 :  menusorting();
                  break;
        case 7 :  printf("Masukkan Nama File Untuk Menyimpan Data (File Berekstensi .txt) : ");
                  scanf("%s",namafile);
                  save(namafile);
                  break;
        case 8 :  printf("Masukkan Nama File Untuk Me-Load Data (File Berekstensi .txt) : ");
                  scanf("%s",namafile);
                  load(namafile);
                  break;
        case 9 :  menuaggregat();
                  break;
        case 10 : undo();
                 break;
        case 11 : redo();
                 break;
        case 12 :if (size > 0) {
                    buat_tabel_relasi(relasi_kontak, Kontak, size);
                    printf("Matriks relasi antar kontak berhasil dibuat!\n");
                } else {
                    printf("Tambahkan daftar kontak terlebih dahulu.\n");
                }
                break;
        case 13 :if (size > 0) {
                    tampilkan_tabel_relasi(relasi_kontak, Kontak, size);
                } else {
                    printf("Tambahkan daftar kontak terlebih dahulu.\n");
                }
                break;
        case 14 : exit(0);
                 break;
        default : printf("Input Tidak Valid\n");
                 break;
    }

    printf("--------------------------------------------------\n");
    printf("|\tApakah Kamu Ingin Keluar \t\t |\n");
    printf("--------------------------------------------------\n");
    printf("| 1. Keluar \t\t\t\t\t | \n");
    printf("| 2. Kembali Ke Menu Utama\t\t\t |\n");
    printf("--------------------------------------------------\n");
    printf("Pilihan Anda : ");
    scanf("%d",&c);
    }while( c != 1);

    



 return 0;   
}