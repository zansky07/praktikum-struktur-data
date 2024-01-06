#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node* item;

struct queue{
    int count;
    item front;
    item rear;
};
typedef struct queue* antrian;

void initialize(antrian q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

bool isempty(antrian q){
    return (q->rear == NULL);
}

void q_insert(antrian q, int value){
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if(!isempty(q)){
        q->rear->next = new_node;
        q->rear = new_node;
    }else{
        q->front = q->rear = new_node;
    }
    q->count++;
}

void q_remove(antrian q){
    item tmp;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
}
void display(antrian q){
    item n;
    n = q->front;
    if(q->front == NULL){
        printf("\nQueue masih kosong\n");
    }else{
        while(n!=NULL){
            printf("%d\n", n->data);
            n = n->next;
        }
    }
}

int main(){
    antrian q;
    q = (antrian)malloc(sizeof(struct node));
    initialize(q);
    q_insert(q,10);
    q_insert(q,20);
    q_insert(q,30);
    q_insert(q,40);
    printf("Queue sebelum dequeue \n");
    display(q);
    q_remove(q);
    printf("Queue setelah dequeue \n");
    display(q);

    return 0;
}