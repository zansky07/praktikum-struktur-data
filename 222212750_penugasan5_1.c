#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;

    return(p);
}

ptrnode insert_tail(int nilai,ptrnode tail){
    // iterasi mencari node terakhir
    ptrnode temp = tail;
    // buat node baru
    ptrnode new_node = createNode(nilai);
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
    tail = new_node;
    return (tail);
}

ptrnode remove_last(ptrnode tail){
    if(tail == NULL)
        return NULL;

    //cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    
    ptrnode temp = tail;
    
    temp->prev->next = NULL;
    tail = temp->prev;
    temp->prev = NULL;
    

    free(temp);

    return(tail);
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
    printf("\nIsi tail : %d",tail->value);
    
    tail = insert_tail(90,tail);
    
     tmp = head;
    printf("\nIsi Node Setelah Insert Node bernilai 90  \n");
    while(tmp != NULL){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("\nIsi tail : %d",tail->value);

    tail = remove_last(tail);
    tmp = head;
    printf("\nIsi Node Setelah Remove Tail  \n");
    while(tmp != NULL){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("\nIsi tail : %d",tail->value);

    return 0;
}