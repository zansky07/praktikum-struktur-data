#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode revese_node(ptrnode head){

    ptrnode cursor = head;
    ptrnode temp =NULL;

    while(cursor != NULL){
    cursor->prev = cursor->next;
    cursor->next = temp;
    temp = cursor;
    cursor = cursor->prev;
    }
    head = temp;
    return (head);
}

int main(){
    ptrnode head = NULL;
    ptrnode dua = NULL;
    ptrnode tiga = NULL;
    ptrnode tail = NULL;

    head = (ptrnode)malloc(sizeof(struct node));
    dua = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));
    tail = (ptrnode)malloc(sizeof(struct node));

    head->value = 10;
    head->next = dua;
    head->prev = NULL;

    dua->value = 20;
    dua->next = tiga;
    dua->prev = head;

    tiga->value = 30;
    tiga->next = tail;
    tiga->prev = dua;

    tail->value = 40;
    tail->next = NULL;
    tail->prev = tiga;



    ptrnode tmp = head;
    printf("Isi Node Awal \n");
    while(tmp != NULL){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
   
    head =revese_node(head);

   tmp = head;
    printf("\n Isi Node Stelah Reverse \n");
    while(tmp != NULL){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
   

    return 0;
}