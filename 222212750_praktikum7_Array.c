#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6

typedef struct node{
    char nama[20];
    int alpro;
    int kalkulus;
} mhs;

mhs *QUEUE[N]; 
int rear, front;

// Function to Create A New Node
mhs* newmhs(char a[], int alp, int kal){
    mhs* temp = (mhs*)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;

    return temp;
}

void swap(mhs *a, mhs *b){
    mhs temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(char n[], int alp, int kal){
    mhs* temp = newmhs(n, alp, kal);
        if (rear == N-1){
        printf("Antrian penuh \n");
        return;
    }

    if(front == -1);
        front = 0;

    rear ++;
    int i,k;
    for(k = 0; k<=rear; k++){
    if(QUEUE[front] == NULL){
    QUEUE[rear] = temp;
    }else if(QUEUE[k]->alpro < alp){
        for(i=N; i>k; i--){
            QUEUE[i] = QUEUE[i-1];
            QUEUE[i-1] = temp;
        }
        break;
    }else if(QUEUE[k]->alpro > alp){
        QUEUE[rear] = temp;
        
        break;
    }else if(QUEUE[k]->alpro == alp){
        if(QUEUE[k]->kalkulus < kal){
        for(i=N; i>k; i--){
            QUEUE[i] = QUEUE[i-1];
            QUEUE[i-1] = temp;
        }
        }else if(QUEUE[k]->kalkulus >= kal){
            for(i=N; i>k; i--){
            QUEUE[i+1] = QUEUE[i];
            QUEUE[i] = temp;
        }
        }
        break;
    }
}
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
        for(int i=front; i<=4; i++){
             printf("Nama:%s Alpro: %d Kalkulus: %d\n", QUEUE[i]->nama,QUEUE[i]->alpro,QUEUE[i]->kalkulus);
        }
        printf("Hanya Menampilkan 5 teratas");
    }
}

int main(){
    rear = -1;
    front = -1;

    enqueue("Eko", 50,20);
    enqueue("Budi", 50,20);
    enqueue("bambang", 60,20);
    enqueue("Eka", 60,20);
    enqueue("wawo", 60,20);
    enqueue("Ame", 60,30);
    
    q_display();
    return 0;
}