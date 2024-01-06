#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;

    return(p);
}

// Insert kiri, maksudnya menambahkan sebuah simpul baru diujung simpul paling kiri 
// atau paling awal atau simpul head dari Linked List yang sudah ada. Tambahkan 
// fungsi insert_head() berikut di luar fungsi main().
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    return(head);
}

// Insert kanan, maksudnya menambahkan sebuah simpul baru diujung simpul paling 
// kanan atau paling akhir atau simpul tail dari Linked List yang sudah ada.
ptrnode insert_tail(ptrnode head, int nilai){
    // iterasi mencari node terakhir
    ptrnode tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    // buat node baru
    ptrnode new_node = createNode(nilai);
    tail->next = new_node;
    new_node->prev = tail;
    new_node->next = NULL;
    return (head);
}
//Menambahkan simpul baru setelah simpul tertentu. 
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari){
    //cari node sebelumnya, starting from the first node
    ptrnode cursor = head;
    while(cursor->value != nilai_dicari)
        cursor = cursor->next;

    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;

    return(head);
}

//Menambahkan simpul baru sebelum simpul tertentu.
ptrnode insert_before(ptrnode head, int nilai_dicari, int next_nilai){
    if(head->value == next_nilai)
        head = insert_head(head, nilai_dicari);
    else{
        //pencarian nilai sama seperti insert after, tidak perlu 2 cursor
        ptrnode cursor = head;
        while(cursor->value != next_nilai)
            cursor = cursor->next;

        ptrnode new_node = createNode(nilai_dicari);
        new_node->prev =cursor->prev;
        cursor->prev->next = new_node;
        new_node->next = cursor;
        cursor->prev = new_node;

       
    }
     return(head);
}

// Delete kiri atau delete awal, maksudnya adalah menghapus simpul yang ada di 
// ujung paling kiri atau paling awal atau simpul head dari Linked List yang sudah ada.
ptrnode remove_first(ptrnode head){
    if (head == NULL )
        return NULL;

    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;

    free(first);

    return(head);
}

//  Delete kanan atau delete akhir, maksudnya adalah menghapus simpul yang ada di 
// ujung paling kanan atau paling akhir atau simpul tail dari Linked List yang sudah ada. 
ptrnode remove_last(ptrnode head){
    if(head == NULL)
        return NULL;

    //cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    ptrnode tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    
    tail->prev->next = NULL;
    tail->prev = NULL;

    free(tail);

    return(head);
}

//  Delete tengah, maksudnya yaitu menghapus sebuah simpul yang berada di antara 
// dua buah simpul lain. Bukan menghapus simpul yang paling kiri dan juga bukan 
// menghapus simpul yang paling kanan.
ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while(cursor != NULL){
        if(cursor->next->value == nilai)
            break;
        cursor = cursor->next;
    }

    if(cursor != NULL){
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next->prev = cursor;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }

    return(head);
}


int main(){
    ptrnode head = NULL;
    ptrnode tail = NULL;

    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;

    head->value=10;
    head->next = NULL;
    head->prev=NULL;
 

    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->next = NULL;
    dua->prev = NULL;

    head->next = dua;
    dua->prev = head;

    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    dua->next = tiga;

    tiga->value = 30;
    tiga->next = empat;
    tiga->prev = dua;

    empat->value = 40;
    empat->next = NULL;
    empat->prev = tiga;

    ptrnode lima = createNode(50);
    empat->next = lima;
    lima->prev = empat;

    /* Tambahkan node baru dengan value = 99 sebagai head */
 head = insert_head(head, 99);

 /* Tambahkan node baru dengan value = 11 sebagai tail */
 head = insert_tail(head, 11);

/* Tambahkan node baru dengan value = 60 setelah node 
dengan value 50 */
head = insert_after(head, 60, 50);

/* Tambahkan node baru dengan value = 35 sebelum node 
dengan value 40 */
head = insert_before(head, 35, 40);

/* Hapus node head */
head = remove_first(head);

/* Hapus node tail */
head = remove_last(head);

/* Hapus node di tengah */
head = remove_middle(head, 30);

    ptrnode tmp = NULL;
    tmp = head;
    while(tmp != NULL){
        printf("%d \n",tmp->value);
        tmp = tmp->next;
    }

return 0;
}