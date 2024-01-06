#include <stdio.h>

#define N 50
int QUEUE[N], rear, front;


void q_insert(int item){
    if (rear == N-1){
        printf("Antrian penuh \n");
        return;
    }

    if(front == -1);
        front = 0;

    rear ++;
    QUEUE[rear] = item;
}

void q_remove(){
    if (rear == -1){
        printf("Antrian Kosong \n");
        return;
    }

    if(front == rear)
        front = rear = -1;
    else{
        for(int i =0;i<rear;i++){
            QUEUE[i] = QUEUE[i+1];
        }
        rear--;
        front = 0;
    }
}

void q_display(){
    if (rear == -1){
        printf("Antrian Kosong \n");
    }
    else{
        printf("Daftar antrian : \n");
        for(int i=front; i<=rear; i++){
            printf("%d\n",QUEUE[i]);
        }
    }
}

int main(){
    rear = -1;
    front = -1;

    q_insert(40);
    q_insert(50);
    q_insert(60);
    q_insert(70);
    q_insert(80);

    q_remove();
    q_remove();

    q_display();

    printf("\n\n%d %d",front, rear);
    return 0;
}