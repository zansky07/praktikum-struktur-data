#include <stdio.h>
#include <string.h>

struct Buku{
    char judul[50];
    char pengarang[50];
    int id;
};

int main(){
    struct Buku Buku1;
    struct Buku Buku2;

    // Spek Buku 1
    strcpy( Buku1.judul, "C Programming");
    strcpy( Buku1.pengarang, "Firdaus");
    Buku1.id = 6495407;

    // Spek Buku 1
    strcpy( Buku2.judul, "Telecom Billing");
    strcpy( Buku2.pengarang, "Nori Wilantika");
    Buku2.id = 6495700;

    // Cetak info buku 1
    printf("Judul Buku 1 : %s\n",Buku1.judul);
    printf("Pengarang Buku 1 : %s\n",Buku1.pengarang);
    printf("Id Buku 1 : %d\n\n",Buku1.id);
    
    // Cetak info buku 1
    printf("Judul Buku 2 : %s\n",Buku2.judul);
    printf("Pengarang Buku 2 : %s\n",Buku2.pengarang);
    printf("Id Buku 2 : %d\n\n",Buku2.id);

    return 0;
}