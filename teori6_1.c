#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node* item;
item top;

void initialize(){
    top = NULL;
}

void push(int value){
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> next = top;
    top = new_node;
}

void pop(){
    item tmp;
    tmp = top;
    top = top->next;
    free(tmp);
}

void display(item head){
    if(head == NULL){
        printf("STACK kosong\n");
    }
    else{
        
        while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
        }
    }
    printf("\n\n");
}

int DisplayTop(){
    return top->data;
}

int main(){
    initialize();
    int choice = 0;
    do{
        printf("Masukkan Pilihan\n 1: Display\n 2: Tambah (PUSH)\n 3: Hapus(POP)\n 4: Lihat Top\n 5:EXIT\n Pilihan:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display(top);
                break;
            case 2:
                printf("Masukkan Item untuk Ditambahkan :");
                int ITEM = 0;
                scanf("%d",&ITEM);
                push(ITEM);
                break;
            case 3:
                pop();
                break;
            case 4:
                printf("Top dari stack adalah %d\n",DisplayTop());
                break;
            case 5:
                printf("\n KELUAR");
                break;
            default :
                printf("\n Pilihan Tidak Valid.");
        }
    }
    while(choice != 5);
    return 0;
}