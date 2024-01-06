#include <stdio.h>
#include <string.h>
#define MAX 100 //ukuran maksimum array

struct mahasiswa {
    int nilai;
    char nama[50];
};



void fill_data(struct mahasiswa datahead[], int *size){ //mengisi data
 printf("Input ukuran array (max 100): ");
 scanf("%d", size);
 printf("Input data: ");
 for(int i=0;i<*size;i++){
 printf("\nNilai mahasiswa %d : ",i+1);
 scanf("%d",&datahead[i].nilai);
 printf("Nama mahasiswa %d : ",i+1);
 scanf("%s",datahead[i].nama);
 }
}

int seq_search_nilai(struct mahasiswa datamhs[], int size, int x){
 for (int i=0;i<size;i++){
 if(datamhs[i].nilai==x){
     return i;
 }
 }
 return -1;
}

int seq_search_nama(struct mahasiswa datamhs[], int size, char x[]){
 for (int i=0;i<size;i++){
 if(strcmp(datamhs[i].nama,x) == 0){
     return i;
 }
 }
 return -1;
}

void main(){
 int data[MAX];
 int size; //ukuran array
 int x,choice,c;
 char carinama[50];
 struct mahasiswa datamhs[MAX];
 
 fill_data(datamhs , &size);

 do{
    printf("Searching Data Mahasiswa Pada Array \n\n");

        printf("MENU-: \n1.Cari Berdasarkan Nilai"
        "\n2.Cari Berdasarkan Nama"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("Nilai yang mau dicari: ");
            scanf("%d", &x);
            if(seq_search_nilai(datamhs,size,x)==-1) printf("tidak ditemukan");
            else printf("ditemukan pada indeks ke-%d",seq_search_nilai(datamhs,size,x));

            break;

        case 2:
            printf("Nama yang mau dicari: ");
            scanf("%s", carinama);
            if(seq_search_nama(datamhs,size,carinama)==-1) printf("tidak ditemukan");
            else printf("ditemukan pada indeks ke-%d",seq_search_nama(datamhs,size,carinama));

            break;

        default:
            printf("\nInput salah\n");
    }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
 }while(c==1);
}