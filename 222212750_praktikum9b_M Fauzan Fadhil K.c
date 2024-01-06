// Nama : Muhammad Fauzan Fadhil K
// NIM  : 222212750
// Kelas : 2KS2
// Tugas Strukdat Pertemuan 9
// Nomor 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[30];
    struct node *left;
    struct node *right;
    int height;
};

struct node *newNode(char data[]){
    struct node *node = (struct node*)malloc(sizeof(struct node));

   strcpy( node->data , data);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}
int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int getHeight(struct node* N){
    if (N== NULL)
        return 0;
    return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct node *N){
    if (N== NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

struct node* rightRotate(struct node *T){
    struct node *new_root = T->left;
    struct node *orphan = new_root->right;

    // Lakukan rotasi
    new_root->right = T;
    T->left = orphan;

    // Update height
    T->height = max(getHeight(T->left), getHeight(T->right)) +1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) +1;

    // Return root baru
    return new_root;
}

struct node* leftRotate(struct node*T){
    struct node *new_root = T->right;
    struct node *orphan = new_root->left;

    // Lakukan rotasi
    new_root->left = T;
    T->right = orphan;

    // Update height
    T->height = max(getHeight(T->left), getHeight(T->right)) +1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

    // Return root baru
    return new_root;
}

//insert 
struct node* insert(struct node* root, char newData[]){
    // 1. Lakukan BST insert biasa
    if(root== NULL)
        root = newNode(newData);
    //asumsi tidak boleh ada nilai yang sama dalam BST
    if(strcmp(newData, root->data) <0) 
        root->left = insert(root->left, newData);
    else if (strcmp(newData, root->data) >0)
        root->right = insert(root->right, newData);

    // 2. Update height dari node baru sampai root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Hitung balance factor untuk menentukan apakah node unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
    // Kasus 1: Left Left
    if (balance > 1 && strcmp(newData, root->left->data) <0) 
        return rightRotate(root);
    // Kasus 2: Right right
    if (balance < -1 && strcmp(newData, root->right->data) >0)
        return leftRotate(root);

    // Kasus 3 : Right Left
    if(balance < -1 && strcmp(newData, root->right->data) <0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if(balance > 1 && strcmp(newData, root->left->data) >0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //return node jika balanced
    return root;

}

// Cari node minimum di suatu subtree
struct node *minValueNode(struct node *node){
    struct node *current = node;

    // loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, char deleted_data[]){
    // 1. Lakukan BST delete biasa
    if(root == NULL)
        return root;

    if (strcmp(deleted_data, root->data) <0) 
        root->left = deleteNode(root->left,deleted_data);
    else if (strcmp(deleted_data, root->data) > 0)
        root->right = deleteNode(root->right, deleted_data);
    else{
        // jika ditemukan node yg akan dihapus
        // 1 child atau no child
            struct node* cursor;
            if(root->left == NULL){
                cursor = root->right;
                free(root);
                root = cursor;
            }
            else if (root->right == NULL){
                cursor = root->left;
                free(cursor);
                root = cursor;
            }
            // 2CHILDS
            else{
                // cari minimum di subtree kanan
                cursor = minValueNode(root->right);

                strcpy(root->data, cursor->data);

                // Delete data yang telah dipindahkan sebagai root
                root->right = deleteNode(root->right, cursor->data);
            }
    }

    // Jika setelah dilakukan delete, tree kosong maka return root
    if (root == NULL)
        return root;

    // 2.Update height dari node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Hitung balance factor untuk menentukan apakah root unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
        // Kasus 1: Left Left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && getBalanceFactor(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // Kasus 4: Left Right
    if(balance > 1 && getBalanceFactor(root->left) <0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // return root jika balanced
    return root;
}


//display
void displayPreorder(struct node* node){
    if(node == NULL)
        return;

    printf("%s ",node->data);//root
    displayPreorder(node->left);//subtree kiri
    displayPreorder(node->right);//subtree kanan
}

void displayInorder(struct node* node){
    if(node==NULL)
    return;

    displayInorder(node->left);//subtree kiri
    printf("%s ",node->data);//root
    displayInorder(node->right);//subtree kanan
}

void displayPostorder(struct node* node){
    if(node == NULL)
        return;

    displayPostorder(node->left);//subtree kiri
    displayPostorder(node->right);//subtree kanan
    printf("%s ",node->data);//root
}

//search
void search_node(struct node*root,char data[]){
    struct node* cursor = root;

    while(cursor ->data != data){
        if(cursor != NULL){
            if(strcmp(data, cursor->data) >0){ 
                cursor = cursor->right;
            }else {
                cursor = cursor->left;
            }

            if(cursor == NULL){
                printf("\nNode %s tidak ditemukan",data);
                return;
            }
        }
    }

    printf("\nNode %s ditemukan", data);
    return;
}



int main(){

    struct node* root = NULL;


    root = insert(root, "fauzan");    
    root = insert(root, "ella");
    root = insert(root, "flora");
    root = insert(root, "ashel");
    root = insert(root, "fania");
    root = insert(root, "freya");
    root = insert(root, "adel");
    root = insert(root, "elin");
    root = insert(root, "elki");
    

    /* AVL Tree
          fauzan
           /  \
        elin    flora
        /  \     \
    ashel   ella   freya
      /    /  \
    adel elki fania
    */
    
    printf("\nDisplay Pre Order \n");
    displayPreorder(root);

    printf("\nDisplay In Order \n");
    displayInorder(root);

    printf("\nDisplay Post Order\n");
    displayPostorder(root);


    root = deleteNode(root, "flora");
 /*AVL Tree setelah delete 10
           elin
           /  \
        ashel  fauzan
        /     /  \
      adel  ella   freya
           /  \
        elki   fania
    */

    printf("\n===== Setelah Delete =========\n");
    printf("\nDisplay Pre Order \n");
    displayPreorder(root);

    printf("\nDisplay In Order \n");
    displayInorder(root);

    printf("\nDisplay Post Order\n");
    displayPostorder(root);

    return 0;
}