#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){
    //mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: ");
    for(int i=0;i<*size;i++){
      scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
 for(int i=0;i<size;i++) printf("%d ",data[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int data[], int size, int choice){
    if(choice == 1){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++)
            if(data[i] < data[min_idx])
                min_idx = i;
        swap(&data[min_idx], &data[step]);
    }
    }else if(choice == 2){
    for(int step = 0; step < size-1; step++){
        int max_idx = step;
        for(int i = step+1; i<size; i++)
            if(data[i] > data[max_idx])
                max_idx = i;
        swap(&data[max_idx], &data[step]);
    }
    }
}

void main(){
  int data[MAX];
    int size,choice,c; //ukuran array yg dipakai

    do{
         printf("Sorting Data Metode Selection Sort Pada Array \n\n");
        
        printf("MENU-: \n1.Mengurutkan secara Menaik (Ascending)"
        "\n2.Mengurutkan secara Menurun (Descending)"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);

        if (choice == 1 || choice == 2){
        fill_data(data, &size);
        selection_sort(data,size,choice);
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
