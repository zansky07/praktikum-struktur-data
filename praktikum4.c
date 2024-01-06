#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

// Cara ketiga, agar tidak perlu menuliskan potongan program di atas secara berulang-ulang setiap kali dibutuhkan untuk membuat node baru, maka potongan program 
// untuk membuat simpul baru tersebut kita simpan di dalam sebuah fungsi.
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    return (p);
}

//  Insert kiri, maksudnya menambahkan sebuah simpul baru diujung simpul paling kiri 
// atau paling awal atau simpul head dari Linked List yang sudah ada. 
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head = new_node;

    return (head);
}

//  Insert kanan, maksudnya menambahkan sebuah simpul baru diujung simpul paling 
// kanan atau paling akhir atau simpul tail dari Linked List yang sudah ada. 

ptrnode insert_tail(ptrnode head, int nilai){
    // iterasi mencari node terakhir
    ptrnode tail = head;
    while(tail-> next != NULL)
        tail = tail -> next;

    //buat node baru
    ptrnode new_code = createNode(nilai);
    tail->next = new_code;

    return(head);
}

// Menambahkan simpul baru setelah simpul tertentu. 
ptrnode insert_after(ptrnode head, int nilai, int prev_nilai){
    /* cari node sebelumnya, starting from the first node*/
    ptrnode cursor = head;
    while(cursor ->value != prev_nilai)
        cursor = cursor ->next;

    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next = new_node;

    return(head);
}

//Menambahkan simpul baru sebelum simpul tertentu
ptrnode insert_before(ptrnode head, int nilai, int next_nilai){
    if(head->value == next_nilai)
        head = insert_head(head, nilai);
    else {
        ptrnode cursor, prevcursor;
        cursor = head;
        do{
            prevcursor = cursor;
            cursor = cursor-> next;
        }
        while (cursor->value != next_nilai);

        ptrnode new_node = createNode(nilai);
        new_node->next = cursor;
        prevcursor->next = new_node;
    }
    return(head);
}

// Delete kiri atau delete awal, maksudnya adalah menghapus simpul yang ada di 
// ujung paling kiri atau paling awal atau simpul head dari Linked List yang sudah ada. 
ptrnode remove_first(ptrnode head){
    if(head == NULL)
        return;

    ptrnode first = head;
    head = head->next;
    first->next = NULL;

    free(first);

    return(head);
}

//  Delete kanan atau delete akhir, maksudnya adalah menghapus simpul yang ada di 
// ujung paling kanan atau paling akhir atau simpul tail dari Linked List yang sudah ada
ptrnode remove_last(ptrnode head){
    if(head == NULL)
        return;

    ptrnode tail = head;
    ptrnode prevtail = NULL;
    while(tail->next != NULL){
        prevtail = tail;
        tail = tail->next;
    }
    prevtail->next = NULL;
    free(tail);
    return(head);
}

// Delete tengah, maksudnya yaitu menghapus sebuah simpul yang berada di antara 
// dua buah simpul lain. Bukan menghapus simpul yang paling kiri dan juga bukan 
// menghapus simpul yang paling kanan.
ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while(cursor != NULL){
        if(cursor->next->value == nilai)
            break; //keluar dari iterasi
        cursor = cursor -> next;
    }

    if(cursor != NULL){
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }

    return head;
}

// Menggunakan salah satu cara penghapusan simpul di atas, kita dapat menghapus 
// keseluruhan simpul yang ada pada Linked List. Sebagai contoh, program di bawah 
// ini menjalankan algoritma yang sama dengan fungsi remove_first(), hanya 
// ditambahkan iterasi agar proses penghapusan dilakukan secara berulang-ulang 
// untuk keseluruhan simpul yang ada pada Linked List.
ptrnode dispose(ptrnode head){
    if (head == NULL)
        return 0;

    while(head != NULL){
        ptrnode tmp = head;
        head = head->next;

        tmp->next = NULL;
        free(tmp);
    }

    printf("Semua node telah dihapus \n");
    return(head);
}

int main(){
    ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    head->value = 10;
    head->next = NULL;

//kita mendeklarasikan node
// terlebih dahulu. Baru kemudian kita mendeklarasikan pointer, dimana pointer diisi 
// dengan alamat node yang telah sebelumnya dideklarasikan.
    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->next = NULL;

    head->next = dua;

// Kita deklarasikan pointer terlebih dahulu, baru kemudian kita 
// deklarasikan struct node, sekaligus mengalokasikan memori untuk struct node
// tersebut dan menyimpannya ke dalam pointer yang telah dideklarasikan. 
    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    dua->next = tiga;
    tiga->value = 30;
    tiga->next = empat;

    empat->value = 40;
    empat->next = NULL;

    ptrnode lima = createNode(50);
    empat->next =lima;

    /* Tambahkan node baru dengan value = 99 sebagai head 
*/
 head = insert_head(head, 99);

 /* Tambahkan node baru dengan value = 11 sebagai tail 
*/
 head = insert_tail(head, 11);

/* Tambahkan node baru dengan value = 60 setelah node 
dengan value 50 */
head = insert_after(head, 60, 50);

/* Tambahkan node baru dengan value = 35 sebelum node 
dengan value 99 */
head = insert_before(head, 35, 40);

/* Hapus node head */
head = remove_first(head);

/* Hapus node tail */
head = remove_last(head);

/* Hapus node di tengah */
head = remove_middle(head, 30);

/* Hapus/free linked list */
head = dispose(head);


    //Menampilkan isi node
    ptrnode temp = head;
    while(temp != NULL){
        printf("%d \n",temp -> value);
        temp = temp -> next;
    }
 


    return 0;
}