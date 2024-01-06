#include <stdio.h>

    struct Mahasiswa {
        int nim;
        char nama[50];
    };
int main(){
  
    int n,i,j;
    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d",&n);
    struct Mahasiswa data[n];

    // proses input data mahasiswa
    printf("===INPUT===\n");
    for (i=0;i<n;i++){
        printf("Masukkan data mahasiswa %d \n",i+1);
        printf("NIM : ");
        scanf("%d",&data[i].nim);

        printf("Nama : ");
        scanf("%s",data[i].nama);
    }
    printf("===OUTPUT===\n");
    // Menampilkan data mahasiswa
        for (i=0;i<n;i++){
        printf("Data mahasiswa ke %d \n",i+1);
        printf("NIM : %d \n",data[i].nim);
        

        printf("Nama : %s\n",data[i].nama);
       
    }
    return 0;
}    