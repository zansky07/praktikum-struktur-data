#include <stdio.h>
#define MAX 100 //Ukuran maksimum array

void fill_data(int data[], int size){
    //mengisi data
    printf("Input Data Anda: ");
    for(int i =0; i<size;i++){
        scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",data[i]);
    printf("\n");
}

void insertionSort(int arr[], int n, char arah){
    int i, key, j;
    if(arah == 'N'){
    for(i=1; i<n; i++){
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j] > key){
            arr[j + 1] = arr [j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    }else if (arah == 'T'){
    for(i=1; i<n; i++){
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j] < key){
            arr[j + 1] = arr [j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n,char arah){
    int i, j;
    if(arah == 'N'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }else if(arah == 'T'){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(arr[j] < arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

void selection_sort(int data[], int size, char arah){
    if(arah == 'N'){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++)
            if(data[i] < data[min_idx])
                min_idx = i;
        swap(&data[min_idx], &data[step]);
    }
    }else if(arah == 'T'){
    for(int step = 0; step < size-1; step++){
        int max_idx = step;
        for(int i = step+1; i<size; i++)
            if(data[i] > data[max_idx])
                max_idx = i;
        swap(&data[max_idx], &data[step]);
    }
    }
}

void merge(int arr[], int l, int m, int r,char arah){
 
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 
 int L[n1], R[n2];
 
 for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
 
 i = 0;
 j = 0;
 k = l;

 if(arah == 'N'){
 while (i < n1 && j < n2){
    if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
    }
    else{
        arr[k] = R[j];
        j++;
    }
    k++;
 }
 }else if(arah == 'T'){
    while (i < n1 && j < n2){
    if (L[i] >= R[j]) {
        arr[k] = L[i];
        i++;
    }
    else{
        arr[k] = R[j];
        j++;
    }
    k++;
 }
 }
 
 while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
 }
 
 while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
 }
}



void mergeSort(int arr[], int l, int r, char arah){
 if (l < r) {
    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m,arah);
    mergeSort(arr, m + 1, r,arah);
    
    
    merge(arr, l, m, r,arah);
    
    
 }
}

void main(){
  int data[MAX];
    int size,choice,c; //ukuran array yg dipakai
    char arah;
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
        printf("Pilih pengurutan Naik/Turun (N/T) : ");
        scanf(" %c", &arah);
        fill_data(data, size);
        switch(choice){
            case 1 : 
                printf("Menjalankan sorting dengan metode Insertion Sort");
                switch(arah){
                    case 'N' :
                        printf("\nPilihan Pengurutan Naik");
                        insertionSort(data,size,arah);
                        break;
                    case 'T' :
                        printf("\nPilihan Pengurutan Turun");
                        insertionSort(data,size,arah);
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
                        selection_sort(data,size,arah);
                        break;
                    case 'T' :
                        printf("\nPilihan Pengurutan Turun");
                        selection_sort(data,size,arah);
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
                        mergeSort(data,0,size-1,arah);
                        break;
                    case 'T' :
                        printf("\nPilihan Pengurutan Turun");
                        mergeSort(data,0,size-1,arah);
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
                        bubbleSort(data,size,arah);
                        break;
                    case 'T' :
                        printf("\nPilihan Pengurutan Turun");
                        bubbleSort(data,size,arah);
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


        printf("\nData setelah diurutkan: ");
        tampil_data(data,size);
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c==1);

}