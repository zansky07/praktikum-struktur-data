#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *right;
    struct node *left;
};
typedef struct node *ptrnode;

ptrnode initialize(int n){
    ptrnode new_node;
    new_node = (ptrnode)malloc(sizeof(struct node));
    new_node->info = n;
    new_node->right = NULL;
    new_node->left = NULL;

    return(new_node);
}

ptrnode sisip(ptrnode head,int n){
    ptrnode cursor;
    cursor = head;
    ptrnode temp = initialize(n);

    while(cursor != NULL && cursor->right->info < n){
        cursor = cursor->right;
    }

    temp->right = cursor->right;
    cursor->right->left = temp;
    cursor->right = temp;
    temp->left = cursor;

    return (head);
}

void display(ptrnode head){
    ptrnode temp = head;
    while(temp != NULL){
        printf("%d\n",temp->info);
        temp = temp->right;
    }
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

    head->info = 10;
    head->right = dua;
    head->left = NULL;

    dua->info = 12;
    dua->right = tiga;
    dua->left = head;

    tiga->info = 17;
    tiga->right = tail;
    tiga->left = dua;

    tail->info = 40;
    tail->right = NULL;
    tail->left = tiga;

    sisip(head,15);
    display(head);

    return 0;
}