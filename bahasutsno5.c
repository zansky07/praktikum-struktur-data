#include <stdio.h>

int a[50] ={65,70,53,95,80,74,62},b[50];
int topA,topB;

void pindah (int a[50], int b[50]){
    int temp[50],toptemp;
    toptemp =-1;
    while(topA != -1){
    
        toptemp++;
        temp[toptemp] = a[topA];
        topA--;
        
        }
    
    while(toptemp != -1){
    
        topB++;
        b[topB] = temp[toptemp];
        toptemp--;
        
        }
    }

void display(int a[50],int b[50]){
    int i;
printf("A\n");    
    for (i=0 ; i <=topA ; i++){
        printf("%d\n",a[i]);
    }
printf("B\n");
    for (i=0 ; i <=topB ; i++){
        printf("%d\n",b[i]);
    }
}

int main(){
    topA=6;
    topB=-1;


    printf("Isi antrian sebelum pindah \n");
    display(a,b);
    printf("Isi antrian sesudah pindah \n");
    pindah(a,b);
    display(a,b);

    return 0;
}