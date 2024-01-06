#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[],int *size){
    // mengisi data
    printf("Input ukuran array (max 100) : ");
    scanf("%d", size);
    printf("Input data: ");
    for(int i=0; i<*size; i++){
        scanf("%d", &data[i]);
    }
} 

void tampil_data(int data[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",data[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n,int choice){
    int i, j;
    if(choice == 1){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }else if(choice == 2){
    for (i=0; i< n-1;i++)
        for(j=0; j<n-i-1; j++)
            if(arr[j] < arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

void main(){
int data[MAX];
    int size,choice,c; //ukuran array yg dipakai

    do{
         printf("Sorting Data Metode Bubble Sort Pada Array \n\n");
        
        printf("MENU-: \n1.Mengurutkan secara Menaik (Ascending)"
        "\n2.Mengurutkan secara Menurun (Descending)"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);

        if (choice == 1 || choice == 2){
        fill_data(data, &size);
        bubbleSort(data,size,choice);
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