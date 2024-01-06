// Muhammad Fauzan Fadhil Kurnia
// 222212750
// 2KS2

#include <stdio.h>
#include <string.h>
#define MAX 100 //ukuran maksimum array

struct mahasiswa {
    int nim;
    char nama[50];
    int nilai;
  
};



void fill_data(struct mahasiswa datahead[], int size){ //mengisi data
 printf("Input data: ");
 for(int i=0;i<size;i++){
 printf("\nNama mahasiswa %d : ",i+1);
 scanf("%s",datahead[i].nama);
 printf("NIM mahasiswa %d : ",i+1);
 scanf("%d",&datahead[i].nim);
 printf("Nilai mahasiswa %d : ",i+1);
 scanf("%d",&datahead[i].nilai);
 }
}

void tampil_data(struct mahasiswa datamhs[], int size){
    int i; 
    for(int i=0; i<size; i++){
        printf("Data Mahasiswa ke %d\n", i+1);
        printf("Nama  : %s \n",datamhs[i].nama);
        printf("NIM   : %d \n",datamhs[i].nim);
        printf("Nilai : %d \n",datamhs[i].nilai);
    printf("\n");
    }
}

void insertionSort(struct mahasiswa datamhs[], int n, char arah,int dasar){
    int i, j;
    struct mahasiswa key;
    // dasar = 1 -> berdasarkan nama
    // dasar = 2 -> berdasarkan nim
    // dasar = 3 -> berdasarkan nilai
    if (dasar == 1){
        if(arah == 'N'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && strcmp(datamhs[j].nama,key.nama) > 0){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }else if (arah == 'T'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && strcmp(datamhs[j].nama,key.nama) < 0){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }
    }else if(dasar == 2){ //Berdasarkan NIM
        if(arah == 'N'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && datamhs[j].nim > key.nim){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }else if (arah == 'T'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && datamhs[j].nim < key.nim){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }
    }else if (dasar == 3){ //Berdasarkan nilai
        if(arah == 'N'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && datamhs[j].nilai > key.nilai){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }else if (arah == 'T'){
        for(i=1; i<n; i++){
            key = datamhs[i];
            j = i - 1;
            while (j>=0 && datamhs[j].nilai < key.nilai){
                datamhs[j + 1] = datamhs[j];
                j = j-1;
            }
            datamhs[j+1] = key;
        }
        }
    }
}

void swap(struct mahasiswa *a, struct mahasiswa *b){
    struct mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct mahasiswa datamhs[], int n,char arah, int dasar){
    int i, j;
    // dasar = 1 -> berdasarkan nama
    // dasar = 2 -> berdasarkan nim
    // dasar = 3 -> berdasarkan nilai
if(dasar == 1){
    // berdasarkan nama
    if(arah == 'N'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(strcmp(datamhs[j].nama , datamhs[j+1].nama) > 0)
                swap(&datamhs[j], &datamhs[j+1]);
    }else if(arah == 'T'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(strcmp(datamhs[j].nama , datamhs[j+1].nama) < 0)
                swap(&datamhs[j], &datamhs[j+1]);
    }
}else if(dasar == 2){
    // berdasarkan nim
    if(arah == 'N'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(datamhs[j].nim > datamhs[j+1].nim)
                swap(&datamhs[j], &datamhs[j+1]);
    }else if(arah == 'T'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(datamhs[j].nim < datamhs[j+1].nim) 
                swap(&datamhs[j], &datamhs[j+1]);
    }
}else if (dasar == 3){
    // berdasarkan nilai
    if(arah == 'N'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(datamhs[j].nilai > datamhs[j+1].nilai)
                swap(&datamhs[j], &datamhs[j+1]);
    }else if(arah == 'T'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(datamhs[j].nilai < datamhs[j+1].nilai) 
                swap(&datamhs[j], &datamhs[j+1]);
    }
}
}

void selection_sort(struct mahasiswa datamhs[], int size, char arah,int dasar){
    // dasar = 1 -> berdasarkan nama
    // dasar = 2 -> berdasarkan nim
    // dasar = 3 -> berdasarkan nilai
if(dasar == 1){
    if(arah == 'N'){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++)
            if(strcmp(datamhs[i].nama,datamhs[min_idx].nama) < 0)
                min_idx = i;
        swap(&datamhs[min_idx], &datamhs[step]);
    }
    }else if(arah == 'T'){
    for(int step = 0; step < size-1; step++){
        int max_idx = step;
        for(int i = step+1; i<size; i++)
            if(strcmp(datamhs[i].nama, datamhs[max_idx].nama) > 0)
                max_idx = i;
        swap(&datamhs[max_idx], &datamhs[step]);
    }
    }
}else if (dasar == 2){
    //berdasarkan nim
    if(arah == 'N'){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++)
            if(datamhs[i].nim < datamhs[min_idx].nim )
                min_idx = i;
        swap(&datamhs[min_idx], &datamhs[step]);
    }
    }else if(arah == 'T'){
    for(int step = 0; step < size-1; step++){
        int max_idx = step;
        for(int i = step+1; i<size; i++)
            if(datamhs[i].nim > datamhs[max_idx].nim) 
                max_idx = i;
        swap(&datamhs[max_idx], &datamhs[step]);
    }
    }
}else if (dasar == 3){
    //berdasarkan nilai
        if(arah == 'N'){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++)
            if(datamhs[i].nilai < datamhs[min_idx].nilai )
                min_idx = i;
        swap(&datamhs[min_idx], &datamhs[step]);
    }
    }else if(arah == 'T'){
    for(int step = 0; step < size-1; step++){
        int max_idx = step;
        for(int i = step+1; i<size; i++)
            if(datamhs[i].nilai > datamhs[max_idx].nilai) 
                max_idx = i;
        swap(&datamhs[max_idx], &datamhs[step]);
    }
    }
}

}

void merge(struct mahasiswa datamhs[], int l, int m, int r,char arah, int dasar){
 
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 
 struct mahasiswa L[n1], R[n2];
 
 for (i = 0; i < n1; i++)
    L[i] = datamhs[l + i];
 for (j = 0; j < n2; j++)
    R[j] = datamhs[m + 1 + j];
 
 i = 0;
 j = 0;
 k = l;

    // dasar = 1 -> berdasarkan nama
    // dasar = 2 -> berdasarkan nim
    // dasar = 3 -> berdasarkan nilai
if(dasar == 1){
    // berdasarkan nama
 if(arah == 'N'){
 while (i < n1 && j < n2){
    if (strcmp(L[i].nama, R[j].nama) <= 0 ) {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }else if(arah == 'T'){
    while (i < n1 && j < n2){
    if (strcmp(L[i].nama, R[j].nama) >= 0) {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }
}else if (dasar == 2){
// Berdasarkan NIM  
if(arah == 'N'){
 while (i < n1 && j < n2){
    if (L[i].nim <= R[j].nim)  {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }else if(arah == 'T'){
    while (i < n1 && j < n2){
    if (L[i].nim >= R[j].nim) {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }
}else if(dasar == 3){
    // berdasarkan nilai
if(arah == 'N'){
 while (i < n1 && j < n2){
    if (L[i].nilai <= R[j].nilai)  {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }else if(arah == 'T'){
    while (i < n1 && j < n2){
    if (L[i].nilai >= R[j].nilai) {
        datamhs[k] = L[i];
        i++;
    }
    else{
        datamhs[k] = R[j];
        j++;
    }
    k++;
 }
 }

}

 while (i < n1){
    datamhs[k] = L[i];
    i++;
    k++;
 }
 
 while (j < n2){
    datamhs[k] = R[j];
    j++;
    k++;
 }
}



void mergeSort(struct mahasiswa datamhs[], int l, int r, char arah,int dasar){
 if (l < r) {
    int m = l + (r - l) / 2;
    
    mergeSort(datamhs, l, m, arah, dasar);
    mergeSort(datamhs, m + 1, r, arah, dasar);
    
    
    merge(datamhs, l, m, r, arah, dasar);
    
    
 }
}

void main(){
 int data[MAX];
 int size; //ukuran array
 int choice,c,dasar;
 char carinama[50],arah;
 struct mahasiswa datamhs[MAX];
 
 

   do{
         printf("###PROGRAM SORTING DATA### \n");
         printf("Input Jumlah data = ");
         scanf("%d",&size);
        
        printf("Metode Sorting yang tersedia-: \n1. Insertion Sort"
        "\n2. Selection Sort "
        "\n3. Merge Sort "
        "\n4. Bubble Sort "
        "\nPilih Metode Sorting (1/2/3/4) :");
        scanf("%d",&choice);
        printf("Dasar Pengurutan yang tersedia-: \n1. Nama Mahasiswa"
        "\n2. Nomor Induk Mahasiswa "
        "\n3. Nilai Mahasiswa "
        "\nPilih Dasar Pengurutan (1/2/3) :");
        scanf("%d",&dasar);
        printf("Pilih pengurutan Naik/Turun (N/T) : ");
        scanf(" %c", &arah);
        fill_data(datamhs, size);

        switch(dasar){
            case 1 :
                printf("\nMenjalankan Sorting Berdasarkan Nama Mahasiswa");
            switch(choice){
                case 1 : 
                    printf("\nMenjalankan sorting dengan metode Insertion Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 2 : 
                    printf("Menjalankan sorting dengan metode Selection Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 3 : 
                    printf("Menjalankan sorting dengan metode Merge Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 4 : 
                    printf("Menjalankan sorting dengan metode Bubble Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                default :
                    printf("\nInput salah");
                    break;
             }
                break;
            case 2 :
                printf("\nMenjalankan Sorting Berdasarkan NIM Mahasiswa");
            switch(choice){
                case 1 : 
                    printf("\nMenjalankan sorting dengan metode Insertion Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 2 : 
                    printf("Menjalankan sorting dengan metode Selection Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 3 : 
                    printf("Menjalankan sorting dengan metode Merge Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 4 : 
                    printf("Menjalankan sorting dengan metode Bubble Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                default :
                    printf("\nInput salah");
                    break;
             }
                break;
            case 3 :
                printf("\nMenjalankan Sorting Berdasarkan Nilai Mahasiswa");
            switch(choice){
                case 1 : 
                    printf("\nMenjalankan sorting dengan metode Insertion Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            insertionSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 2 : 
                    printf("Menjalankan sorting dengan metode Selection Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            selection_sort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 3 : 
                    printf("Menjalankan sorting dengan metode Merge Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            mergeSort(datamhs,0,size-1,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                case 4 : 
                    printf("Menjalankan sorting dengan metode Bubble Sort");
                    switch(arah){
                        case 'N' :
                            printf("\nPilihan Pengurutan Naik");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        case 'T' :
                            printf("\nPilihan Pengurutan Turun");
                            bubbleSort(datamhs,size,arah,dasar);
                            break;
                        default :
                            printf("\nInput salah");
                            break;
                    }
                    break;
                default :
                    printf("\nInput salah");
                    break;
             }
                break;

            default :
                printf("\nInput salah");
                break;
        }

        printf("\nData setelah diurutkan: \n");
        tampil_data(datamhs,size);
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c==1);
}