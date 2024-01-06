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

int seq_search_asc(int data[], int size, int x){
 for (int i=0;i<size;i++){
    if(data[i]==x) {
        return i;
    }else if(data[i] > x){
      break;
    }
 }
 return -1;
}

int seq_search_desc(int data[], int size, int x){
    for (int i=0;i<size;i++){
         if(data[i]==x) {
             return i;
        }else if(data[i] < x){
             break;
        }
     }
 return -1;
}

void main(){
 int data[MAX];
 int size; //ukuran array
 int choice,c,x;

 do{
    printf("Searching Data Terurut Pada Array \n\n");

        printf("MENU-: \n1.Data Terurut Naik (Ascending)"
        "\n2.Data Terurut Turun (Descending)"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);
    
    switch(choice){
        case 1:
            fill_data(data,&size);
            printf("nilai yang mau dicari: ");
            scanf("%d", &x);
            if(seq_search_asc(data,size,x)==-1) printf("tidak ditemukan");
            else printf("ditemukan pada indeks ke-%d",seq_search_asc(data,size,x));

            break;

        case 2:
            fill_data(data,&size);
            printf("nilai yang mau dicari: ");
            scanf("%d", &x);
            if(seq_search_desc(data,size,x)==-1) printf("tidak ditemukan");
            else printf("ditemukan pada indeks ke-%d",seq_search_desc(data,size,x));

            break;

        default:
            printf("\nInput salah\n");
    }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
 }while(c==1);

}