
#include <stdio.h>

int main()
{
    int kuis, uts, uas;
    float akhir;
    char nim[15], nama[30];
    
    printf("---INPUT DATA---\n");
    printf("NIM : ");
    fgets(nim, sizeof(nim), stdin);
    
    printf("Nama : ");
    fgets(nama, sizeof(nama), stdin);
    
    printf("Nilai Kuis : ");
    scanf("%d",&kuis);
    
    printf("Nilai UTS : ");
    scanf("%d",&uts);
    
    printf("Nilai UAS : ");
    scanf("%d",&uas);
    
    akhir = 0.2 * kuis + 0.3 * uts + 0.5 * uas;
    printf("=================\n");
    printf("Nama : %s",nama);
    printf("NIM : %s",nim);
    printf("Nilai Kuis : %d\n",kuis);
    printf("Nilai UTS : %d\n",uts);
    printf("Nilai UAS : %d\n",uas);
    printf("Nilai Akhir : %.2f\n",akhir);


    return 0;
}


