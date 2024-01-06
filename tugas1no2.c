#include <stdio.h>

int hitungKeliling(int x,int y){
    return 2*(x+y);
}
int hitungLuas(int x,int y){
    return x*y;
}

int main()
{   
    int panjang,lebar;
    
    printf("---INPUT---\n");
    
    printf("Panjang : ");
    scanf("%d",&panjang);

    printf("Lebar : ");
    scanf("%d",&lebar);
    
    printf("==========\n");
    printf("Keliling Persegi Panjang : %d\n",hitungKeliling(panjang,lebar));
    printf("Luas Persegi Panjang : %d",hitungLuas(panjang,lebar));
    return 0;
}
