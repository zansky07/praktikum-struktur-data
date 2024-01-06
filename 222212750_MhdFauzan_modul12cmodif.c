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

void merge(int arr[], int l, int m, int r,int choice){
 
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

 if(choice == 1){
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
 }else if(choice ==2){
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



void mergeSort(int arr[], int l, int r,int choice){
 if (l < r) {
    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m,choice);
    mergeSort(arr, m + 1, r,choice);
    
    
    merge(arr, l, m, r,choice);
    
    
 }
}

void main(){
  int data[MAX];
    int size,choice,c; //ukuran array yg dipakai

    do{
         printf("Sorting Data Metode Merge Sort Pada Array \n\n");
        
        printf("MENU-: \n1.Mengurutkan secara Menaik (Ascending)"
        "\n2.Mengurutkan secara Menurun (Descending)"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);

        if (choice == 1 || choice == 2){
        fill_data(data, &size);
        mergeSort(data,0,size-1,choice);
        printf("Data setelah diurutkan: \n");
        tampil_data(data,size);
        }
        else{
        printf("\nInput salah\n");
        }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c==1);

}