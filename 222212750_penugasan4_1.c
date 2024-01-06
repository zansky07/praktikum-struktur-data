#include<stdio.h>
#include<stdlib.h>

//membuat node
struct node {
    int nilai;
    struct node *next;
};

typedef struct node *ptrnode;

//Menghitung jumlah node
ptrnode hitungNode(ptrnode head){
    int n=0;
    ptrnode temp = head;
    while(temp != NULL){
        n += 1;
        temp = temp->next;
    }
    printf("Jumlah Node pada linked list adalah %d",n);
}

int main(){
    //inialisasi node
    ptrnode head = NULL;
    ptrnode dua = NULL;
    ptrnode tiga = NULL;

    //alokasi memori node
    head = (ptrnode)malloc(sizeof(struct node));
    dua = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));

    //mengisi nilai node
    head->nilai = 10;
    //menghubungkan node head ke node dua
    head->next = dua;

    dua->nilai = 22;
    dua->next = tiga;

    tiga->nilai = 33;
    tiga->next = NULL;

    hitungNode(head);
    
    return 0;
}