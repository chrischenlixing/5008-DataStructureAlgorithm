// name: Lixing Chen
// email: chen.lixin@northeastern.edu

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

struct node {
    int key;
    int value;
    struct node* next;
    struct node* previous;
};

struct bucket {
    struct node* head;
    int count;
};

struct bucket* hashTable;

struct node* createNode(int key, int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode -> previous = NULL;
    return newNode;
}

int hashFunction(int key){
    return key % BUCKET_SIZE;
}

void add(int key, int value) {
      int hashIndex = hashFunction(key);
    struct node* newNode = createNode(key, value);

    if (hashTable[hashIndex].count == 0) {
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count = 1;
    } else {
            hashTable[hashIndex].head->previous = newNode;
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
}

void remove_key(int key) {
    int hashIndex = hashFunction(key);
    struct node* currentNode = hashTable[hashIndex].head;
    struct node* previousNode = NULL;

    if (currentNode == NULL) {
        printf("\nKey not found\n");
        return;
    }

    while (currentNode != NULL && currentNode->key != key) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("\nKey not found\n");
        return;
    }

    if (previousNode == NULL) {
        hashTable[hashIndex].head = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }

    free(currentNode);
    hashTable[hashIndex].count--;
    printf("\nKey (%d) is removed\n", key);
}

void search(int key) {
    int hashIndex = key % BUCKET_SIZE;
    struct node* currentNode = hashTable[hashIndex].head;

    if (currentNode == NULL) {
        printf("\nKey not found\n");
        return;
    }

    while (currentNode != NULL && currentNode->key != key) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("\nKey is not found\n");
    } else {
        printf("\nKey: %d, Value: %d\n", currentNode->key, currentNode->value);
    }
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

int main() {
    int i;
    hashTable = (struct bucket*) malloc(BUCKET_SIZE * sizeof(struct bucket));

    for (i = 0; i < BUCKET_SIZE; i++) {
        hashTable[i].head = NULL;
        hashTable[i].count = 0;
    }

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
