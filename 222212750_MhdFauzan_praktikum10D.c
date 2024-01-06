#include <stdio.h>
#include <stdlib.h>


struct hashtable_item{
    int flag;

    // flag = 0 : Tidak ada data
    // flag = 1 : Ada data
    // flag = 2 : Sebelumnya ada datanya
    int key;
    int value;
};


int max ;
struct hashtable_item array[100];
// initializing hash table array
void init_array(){
    
    int i;
    for(i=0; i<max ; i++){
        array[i].flag = 0;
        array[i].key = 0;
        array[i].value = 0;
    }

}

// to every key, it will generate a corresponding index
int hashcode(int key){
    return (key % max);
}

int size = 0; //size dari hashtable

int size_of_hashtable(){
    return size;
}

void insert(int key, int value){

    int index = hashcode(key);
    int i = index;
    int j = 1;
  


    // probing through the array until we reach an empty space
    // LINEAR PROBING
    while (array[i].flag == 1 ){

        if (array[i].key == key){
            // case where already existing key matches the given key
            printf("\n Key already exists, hence updating its value \n");
            array[i].value = value;
            return;
        }

        i = (i+ j * j) % max; //maju satu langkah
        j++;
        if(i==index)
        // jika sudah menegecek satu-satu index sampai balik lagi ke index penuh
        {
            printf("\n Hash table is full, cannot insert any more item \n");
            return;
        }
    }

     if(array[i].flag == 2){
            printf("\nBaris sudah tidak dapat diisi \n");
            return;
         }
    

    array[i].flag = 1;
    array[i].key = key;
    array[i].value = value;
    size++;
    printf("\n Key (%d) has been inserted \n", key);

}

void remove_element(int key){

    int index = hashcode(key);
    int i = index;
    int j = 1;
    // probing through array until we reach an empty
    // space where not even once an element had been present

    while(array[i].flag != 0){

        if(array[i].flag == 1 && array[i].key == key)
        {
            // case when data key matches the given key
            array[i].flag = 2;
            array[i].key = 0;
            array[i].value = 0;
            size--;
            printf("\n Key (%d) has been removed \n", key);
            return;
        }

        i = (i+ j * j) % max;
        j++;
        if(i== index){
            break;
        }
    }
    printf("\n This key does not exist \n");
}

// to display all the elements of hash table
void display(){
    int i;
    for (i=0; i<max; i++){
        struct hashtable_item current = array[i];
        
        if(current.flag ==1){
            printf("\n Array[%d] has elements -: \n %d(key) and %d(value) ", i, current.key, current.value);
        }else{
            printf("\n Array [%d] has no elements \n",i);
        }
    }
}

int main(){

    int choice, key, value, n, c;
    printf("Masukkan ukuran hash tabel \n");
    scanf("%d",&max);
    

    init_array();

    do{
        printf("Implementation of Hash Table in C with Linear Probing \n\n");

        printf("MENU-: \n1.Inserting item in the Hashtable"
        "\n2.Removing item from the Hashtable"
        "\n3.Check the size of Hashtable"
        "\n4.Display Hashtable"
        "\n\n Please enter your choice-:");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Inserting element in Hashtable\n");
                printf("Enter key-:\t");
                scanf("%d", &key);
                printf("Enter value-:\t");
                scanf("%d", &value);
                insert(key, value);

                break;

            case 2:
                printf("Deleting in Hashtable \n"
                "Enter the key to delete-:");
                scanf("%d", &key);
                remove_element(key);

                break;

            case 3:
                n = size_of_hashtable();
                printf("Size of Hashtable is-:%d\n",n);
                
                break;

            case 4:
                display();
                break;
            default :
                printf("Wrong Input\n");
        }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);

    }while(c == 1);
getchar();
    return 0;

}