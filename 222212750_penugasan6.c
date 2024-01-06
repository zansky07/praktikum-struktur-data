#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct node {
    int data ;
    int jml_item;
    struct node *next;
};

typedef struct node *stack;

   stack top;
   int N;
    int bil_desimal;
    int sisa_bagi;

//menyiapkan tumpukan kosong
void initializestack(){
    top = NULL;
}

//jika tumpukan kosong maka nilai fungsinya 1 (true),
//jika tidak 0(false)
int isEmpty(stack s){
    return (s->jml_item == 0);
}

// jika tumpukan sudah full(dlm deklarasi stack, field item
// adalah array dgn jumlah elemen sebanyak 50)maka nilai fungsinya 1, jika tidak 0
int isFull (stack s){
    return (s->jml_item == 50);
}

void push(int x){
    if(N == 50)
        printf("Bilangan terlalu besar !\n");
    else{
    stack new_node;
    new_node = (stack)malloc(sizeof(struct node));
    new_node -> data = abs(x);
    new_node -> next = top;
    top = new_node;
    N++;
    }
}

int pop(){
    if(N==0)
        return (0);
    else {
        stack tmp;
        tmp = top;
        top = top->next;
        --N;
        return (tmp->data);
    }
}

void konversi(int nilai){
    if (nilai == 0){
        printf("Hasil konversi ke biner = 0");
     printf("\n");
    }
    else {
        int n;
        for (n= nilai;n>0 || n<0;n=n/2){
            sisa_bagi = n%2;
            push(sisa_bagi);
        }
        //Bila angka desimal positif maka diberi nilai 0 sebagai penanda
        if (nilai > 0){
            push(0);
        }
        //Bila angka desimal negatif maka diberi nilai 1 sebagai penanda
        else{
            push(1);
        }

        int i;
        printf("Hasil konversi ke biner = ");
        for(i=N;i>0;i--){
            printf("%d", pop());
        }
         printf("\n");
    }
}

void konversiOktal(int nilai){
    if (nilai == 0){
        printf("Hasil konversi ke Oktal = 0");
     printf("\n");
    }
    else {
        int n;
        for (n= nilai;n>0 || n<0;n=n/8){
            sisa_bagi = n%8;
            push(sisa_bagi);
        }
        //Bila angka desimal positif maka diberi nilai 0 sebagai penanda
        if (nilai > 0){
            push(0);
        }
        //Bila angka desimal negatif maka diberi nilai 1 sebagai penanda
        else{
            push(1);
        }

        int i;
        printf("\nHasil konversi ke Oktal = ");
        for(i=N;i>0;i--){
            printf("%d", pop());
        }
        printf("\n");
    }
}

void main(){
        initializestack();
         int choice = 0;
    do{
    printf("Program konversi Desimal ke Biner dan Oktal \n\n");
   
    printf("Pilihan: \n1.Desimal \n2.Oktal  \n3.Keluar \nPilihanmu :");
    scanf("%d",&choice);

    switch(choice){
        case 1 :
            printf("\nMasukkan bilangan desimal = ");
            scanf("%d", &bil_desimal);
            konversi(bil_desimal);
            break;
        case 2 :
            printf("\nMasukkan bilangan desimal = ");
            scanf("%d", &bil_desimal);
            konversiOktal(bil_desimal);
            break;
        case 3 :
            printf("\nKeluar");
            break;
        default :
            printf("\n Pilihanmu tidak valid\n");
    }
    }while(choice != 3);

}