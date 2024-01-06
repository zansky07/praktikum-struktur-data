#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
 int nilai;
 char nama[50];
 struct node *next;
};

typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; //jumlah node

ptrnode insert(int nilai,char nama[]){
    ptrnode p,q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->nilai = nilai;
    strcpy(p->nama, nama);
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
    char nama[50];
    printf("input jumlah node: ");
    scanf("%d",&jumnode);
        for(int j=1;j<=jumnode;j++){
            printf("\nInput nilai mahasiswa ke-%d :",j);
            scanf("%d", &k);
            printf("Input nama mahasiswa ke-%d :",j);
            scanf("%s", nama);
            head=insert(k,nama);
        }
}

int searchnilai(int x){ //x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp=head;
        while(tmp != NULL){
            if(x==tmp->nilai){
                return j;
            }
            else{
                tmp = tmp->next;
                j++;
            }
        }
 return -1; //jika tidak ada yang dicari return -1
}

int searchnama(char x[]){ //x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp=head;
        while(tmp != NULL){
            if(strcmp(x, tmp->nama)==0){
                return j;
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
    char nama[50];
    int choice, c,x;
    
    do{
         printf("Searching Data Mahasiswa Pada Linked List \n\n");
         isi_data();
        printf("MENU-: \n1.Cari Berdasarkan Nilai"
        "\n2.Cari Berdasarkan Nama"
        "\n\n Please enter your choice-:");

        
        scanf("%d",&choice);

        switch(choice){
            case 1 :

                printf("input nilai yang mau dicari: ");
                scanf("%d",&x);
                if (searchnilai(x) == -1) printf("data tidak ditemukan");
                else printf("data ditemukan di node ke-%d",searchnilai(x));
                bersihkan_memori();

                break;
            case 2:
                
                printf("input nama yang mau dicari: ");
                scanf("%s",nama);
                if (searchnama(nama) == -1) printf("data tidak ditemukan");
                else printf("data ditemukan di node ke-%d",searchnama(nama));
                bersihkan_memori();

                break;

            default :
                printf("Wrong Input\n");
        }

        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c==1);
}
