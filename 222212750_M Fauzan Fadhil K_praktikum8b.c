#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[30];
    struct node *left;
    struct node *right;
};

struct node *newNode(char data[]){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;

    return node;
}

//insert 
struct node* insert(struct node* root, char newData[]){
    if(root== NULL){
        root = newNode(newData);
    }else{
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;

        while(cursor != NULL){
            prev = cursor;
            if(strcmp(newData, cursor->data) <0) {
                is_left = 1;
                cursor = cursor->left;
            }else if(strcmp(newData, cursor->data) >0){
                is_left = 0;
                cursor = cursor->right;
            }
        }

        if(is_left == 1)
            prev->left =newNode(newData);
        else
            prev->right = newNode(newData);
    }

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

    while(strcmp(cursor->data, data) !=0) {
        if(cursor != NULL){
            if(strcmp(data, cursor->data) >0) {
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

//hapus
struct node* delete_node(struct node* root, char deletedData[20]){
    
    if(root == NULL)
        return NULL;

    struct node* cursor;
    if(strcmp(deletedData, root->data) >0) 
        root->right = delete_node(root->right, deletedData);
    else if (strcmp(deletedData, root->data) < 0)
        root->left = delete_node(root->left, deletedData);
    else{
        //1 CHILD
        if(root->left == NULL){
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if(root->right == NULL){
            cursor = root->left;
            free(root);
            root = cursor;
        }    
        //2 CHILDS NODE
        else{
            cursor = root->right;
            while(cursor->left != NULL){
                cursor = cursor->left;
            }
            strcpy( root->data , cursor->data);
            root->right = delete_node(root->right, cursor->data);
        }
    }
    return root;
}

int main(){

    struct node* root = newNode("fauzan");

    root = insert(root, "callie");
    root = insert(root, "adel");
    root = insert(root, "danella");
    root = insert(root, "daisy");
    root = insert(root, "ella");
    root = insert(root, "fiony");
    root = insert(root, "freya");
    root = insert(root, "flora");
    

    
    printf("\nDisplay Pre Order \n");
    displayPreorder(root);

    printf("\nDisplay In Order \n");
    displayInorder(root);

    printf("\nDisplay Post Order\n");
    displayPostorder(root);

    root=delete_node(root, "callie");
    root=delete_node(root, "zee");

    printf("\n===== Setelah Delete =========\n");
    printf("\nDisplay Pre Order \n");
    displayPreorder(root);

    printf("\nDisplay In Order \n");
    displayInorder(root);

    printf("\nDisplay Post Order\n");
    displayPostorder(root);


    search_node(root, "freya");
    search_node(root, "jessi");
    return 0;
}