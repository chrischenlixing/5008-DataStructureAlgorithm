// name: <your name here>
// email: <your email here>

// Hash table with doubly linked list for chaning/
#include <stdio.h>
#include <stdlib.h> 

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; 

// node struct
struct node {
    int key;
    int value;
    struct node* next;
    struct node* previous;

};

// bucket struct
struct bucket{
    struct node* head;
    int count;
    // Add your code here

};

// create a new node
struct node* createNode(int key, int value){

    // Add your code here    struct node* newNode;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> key = key;
    newNode -> value = value;
    newNode -> next = NULL;
    newNode -> previous = NULL;

    return newNode;
}

//  hash function with %
int hashFunction(int key){
    return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value){
    int hashIndex = hashFunction(key);
    
    // Add your code here
    struct node* newNode = createNode(key, value);
    if (hashTable[hashIndex].count == 0){
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count += 1;
    } else{
        hashTable[hashIndex].head -> previous = newNode;
        newNode -> next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count += 1;

    }

}

// remove a key
void remove_key(int key){
    int hashIndex = hashFunction(key);

    // Add your code here
    struct node * node = hashTable[hashIndex].head;
    if (node == NULL){
        printf("\nno key found. \n");
        return;
    }
    while (node != NULL) {
        if (node->key == key) {
            if (node -> previous == NULL && node->next == NULL) {
                hashTable[hashIndex].head = NULL;
            }
            else if (node -> previous == NULL){
                node->next->previous = NULL;
                hashTable[hashIndex].head = node->next;
            }
            else if (node -> next == NULL){
                node->previous->next = NULL;
            }
            else{
                node->previous->next = node->next;
                node->next->previous = node->previous;
            }
            hashTable[hashIndex].count--;
            free(node);
            printf("\n[ %d ] is removed. \n", key);
            return;
        }
        node = node -> next;
    }
    printf("\n[ %d ] is not found.\n", key);
    return;

}

// search a value using a key
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;

    // Add your code here

    if(node == NULL){
        printf("\nno key found. \n");
        return;
    }
    while (node != NULL)
    {
        if (node->key == key){
            printf("\nkey = [ %d ], value = [ %d ].\n", node->key, node->value);
            return;
        }
        node = node->next;
    }
    printf("\nno key found. \n");
    return;

}

void display(){
    struct node* iterator;

    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

int main(){
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    add(0, 1);
    add(1, 10);
    add(11, 12);
    add(21, 14);
    add(31, 16);
    add(5, 18);
    add(7, 19);

    display();

    remove_key(31);
    remove_key(11);

    display();

    search(11);
    search(1);
}
