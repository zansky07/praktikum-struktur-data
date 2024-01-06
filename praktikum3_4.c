#include <stdio.h>

struct data_tanggal {
    int tahun;
    int bulan;
    int tanggal;
}ultah;

int main(){
    ultah.tanggal = 30;
    ultah.bulan = 7;
    ultah.tahun = 1998;

    printf("tanggal = %d, bulan = %d, tahun = %d",ultah.tanggal, ultah.bulan, ultah.tahun);
    return 0;
}