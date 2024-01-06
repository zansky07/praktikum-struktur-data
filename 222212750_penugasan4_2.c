#include<stdio.h>
#include<stdlib.h>

int n;

struct node{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

    ptrnode balikNode(ptrnode head){
        ptrnode current = head;
        ptrnode prev = NULL;
        ptrnode Next;

        while(current!=NULL){
            Next = current -> next;
            current -> next = prev;
            prev = current;
            current = Next;
        }
        head = prev;
        return(head);
    }

int main(){

    //Membuat node
    ptrnode head = NULL;
    ptrnode dua = NULL;
    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    ptrnode tail = NULL;

    //Alokasi memori node
    head = (ptrnode)malloc(sizeof(struct node));
    dua = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));
    tail = (ptrnode)malloc(sizeof(struct node));

    head->value = 5;
    head->next = dua;

    dua->value = 4;
    dua->next = tiga;

    tiga->value = 3;
    tiga->next = empat;

    empat->value = 2;
    empat->next = tail;
  
    tail->value = 1;
    tail->next = NULL;

    ptrnode temp = head;
    printf("Isi node sebelum dibalik : ");
    while(temp != NULL){
        n += 1;
        printf("%d",temp->value);
        temp = temp->next;
    }
    
    head = balikNode(head);

    ptrnode Temp = head;
    printf("\nIsi node sesudah dibalik : ");
      while(Temp != NULL){
        n += 1;
        printf("%d",Temp->value);
        Temp = Temp->next;
    }
    
    return 0;
}