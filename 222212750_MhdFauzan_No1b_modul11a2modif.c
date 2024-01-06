#include <stdio.h>
#include <stdlib.h>
struct node{
 int value;
 struct node *next;
};

typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; //jumlah node

ptrnode insert(int nilai){
    ptrnode p,q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
        if(head==NULL) {
            head=p;
            q=head;
        }
        else {
            q = head;
                while(q->next!=NULL){
                q = q->next;
            }
            q->next = p;
        }   
 
 return(head);
}

void isi_data(){
    int k;
    printf("input jumlah node: ");
    scanf("%d",&jumnode);
        for(int j=1;j<=jumnode;j++){
            printf("input data ke-%d :",j);
            scanf("%d", &k);
            head=insert(k);
        }
}

int searchasc(int x){ //x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp=head;
        while(tmp != NULL){
            if(x==tmp->value){
                return j;
            }else if(tmp->value > x){
                break;
            }
            else{
                tmp = tmp->next;
                j++;
            }
        }
 return -1; //jika tidak ada yang dicari return -1
}

int searchdesc(int x){ //x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp=head;
        while(tmp != NULL){
            if(x==tmp->value){
                return j;
            }else if(tmp->value < x){
                break;
            }
            else{
                tmp = tmp->next;
                j++;
            }
        }
 return -1; //jika tidak ada yang dicari return -1
}

void bersihkan_memori(){
    while(head != NULL){
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}

void main(){
    int choice, c,x;
    do{
         printf("Searching Data Terurut Pada Linked List \n\n");

        printf("MENU-: \n1.Data Terurut Naik (Ascending)"
        "\n2.Data Terurut Turun (Descending)"
        "\n\n Please enter your choice-:");

        scanf("%d",&choice);

        switch(choice){
            case 1 :
                isi_data();
                printf("input nilai yang mau dicari: ");
                scanf("%d",&x);
                if (searchasc(x) == -1) printf("data tidak ditemukan");
                else printf("data ditemukan di node ke-%d",searchasc(x));
                bersihkan_memori();

                break;
            case 2:
                isi_data();
                printf("input nilai yang mau dicari: ");
                scanf("%d",&x);
                if (searchdesc(x) == -1) printf("data tidak ditemukan");
                else printf("data ditemukan di node ke-%d",searchdesc(x));
                bersihkan_memori();

                break;

            default :
                printf("Wrong Input\n");
        }

        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c==1);

}
