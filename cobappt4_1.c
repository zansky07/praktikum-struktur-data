#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    struct Node* head = NULL;
    struct Node* dua = NULL;
    struct Node* tiga = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    dua = (struct Node*)malloc(sizeof(struct Node));
    tiga = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = dua;

    dua->data = 20;
    dua->next = tiga;

    tiga->data = 30;
    tiga->next = NULL;

    printf("Isi dari linked list : \n");
    struct Node* n = head;
    while(n != NULL){
        printf("%d\n", n->data);
        n = n->next;
    }
    return 0;

}