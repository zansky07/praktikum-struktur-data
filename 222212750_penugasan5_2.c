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

ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    return(head);
}

int main(){
    int n,i,nilai;

    printf("Input the number of nodes : ");
    scanf("%d",&n);
    ptrnode new_node = NULL;
    ptrnode head = NULL;
    
    for(i=1;i<=n;i++){
        if(head == NULL){
            printf("Input data for node 1 : ");
            scanf("%d",&nilai);
            new_node = createNode(nilai);
            head = new_node;
        }else{
            printf("Input data for node %d : ",i);
            scanf("%d", &nilai);
            ptrnode tail = head;
            while(tail->next != NULL){
                tail = tail->next;
            }

            // buat node baru
            ptrnode new_node = createNode(nilai);
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = NULL;
        }
    }
    ptrnode temp = head;
    printf("\nData entered in the list are : ");
    for(i=1;i<=n;i++){
        printf("\nNode %d : %d",i,temp->value);
        temp = temp->next;
    }
    printf("\nInput data for the first node : ");
    scanf("%d",&nilai);
    head = insert_head(head,nilai);

    temp = head;
    printf("\nAfter insertion the new list are : ");
    for(i=1;i<=n+1;i++){
        printf("\nNode %d : %d",i,temp->value);
        temp = temp->next;
    }
    return 0;
}