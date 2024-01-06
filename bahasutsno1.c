#include <stdio.h>
#include <string.h>

#define MAX 5

struct KalimatInfo{
    char kalimat[100];
    int jumlahKata;
};

struct KalimatInfo pragraf[MAX];
int LAST,i;

void insert (char kal[100], int jmlkata){
    if(LAST < MAX-1){
        LAST++;
        strcpy(pragraf[LAST].kalimat , kal);
        pragraf[LAST].jumlahKata = jmlkata;
    }else{
        printf("\n Paragraf sudah penuh\n");
    }
}

void insertKe(char kal[100], int jmlkata, int n){
    if(LAST < MAX -1 && n >= 0 && n <= LAST){
        for(i= LAST; i >= n; i--){
            strcpy(pragraf[i+1].kalimat, pragraf[i].kalimat);
            pragraf[i+1].jumlahKata = pragraf[i].jumlahKata;
        }
     strcpy(pragraf[n].kalimat, kal);
     pragraf[n].jumlahKata = jmlkata;  
     LAST++; 
    }else{
        printf("\n Sisipan diluar jangkauan atau pragraf sudah penuh");
    }
}

int jmlKalimatN(int n){
    int count;
    for(i=count;i<=LAST;i++){
        if(pragraf[i].jumlahKata = n){
            count++;
        }
    }
}

void display(){
    for(i=0; i<=LAST; i++){
        printf("\n%s  (%d kata)",pragraf[i].kalimat,pragraf[i].jumlahKata);
    }
}

int main(){
    LAST = -1;
    insert("kalimat contoh",2);
    insert("kalimat contoh kedua",3);
    insert("kalimat contoh ketiga",3);

    insertKe("kalimat contoh sisip kedua",4,2);
    display();

    printf("\n Jumlah kalimat dengan 3 kata adalah %d",jmlKalimatN(3));
    return 0;

}