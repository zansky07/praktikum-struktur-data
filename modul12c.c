#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: ");
    for(int i=0;i<*size;i++){
         scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
    for(int i=0;i<size;i++) 
        printf("%d ",data[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1 ;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 +j];

    i = 0;
    j = 0;
    k = 1;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
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

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r); 
    }
}

void main(){
    int data[MAX];
    int size; //ukuran array yg dipakai
    fill_data(data, &size);
    mergeSort(data,0,size-1);
    printf("data setelah diurutkan:\n");
    tampil_data(data,size);
}