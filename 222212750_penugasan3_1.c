#include <stdio.h>

    struct Mahasiswa {
        char nim[15];
        char nama[30];
        char kelas[10];
        int nilai[3];
    };
int main(){
    struct Mahasiswa mahasiswa;
    int n,i,j;
    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d",&n);
    struct Mahasiswa data[n];
    // proses input data mahasiswa
    printf("===INPUT===\n");
    for (i=0;i<n;i++){
        printf("Masukkan data mahasiswa %d \n",i+1);
        printf("NIM : ");
        scanf("%s",data[i].nim);

        printf("Nama : ");
        scanf("%s",data[i].nama);

        printf("Kelas : ");
        scanf("%s",data[i].kelas);
        
        for (j=0;j<3;j++){
            printf("Nilai Kuis ke-%d: ",j+1);
            scanf("%d",&data[i].nilai[j]);
        }
    }
    printf("===OUTPUT===\n");
    // Menampilkan data mahasiswa
        for (i=0;i<n;i++){
        printf("Masukkan data mahasiswa %d \n",i+1);
        printf("NIM : %s \n",data[i].nim);
        

        printf("Nama : %s\n",data[i].nama);
       

        printf("Kelas : %s\n",data[i].kelas);
      
        
        for (j=0;j<3;j++){
            printf("Nilai Kuis ke-%d: %d \n",j+1,data[i].nilai[j]);
           
        }
    }
    return 0;
}    