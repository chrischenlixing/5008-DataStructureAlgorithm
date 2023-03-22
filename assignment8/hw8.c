// name: Lixing Chen
// email: chen.lixin@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

#define BUCKET_SIZE 400


typedef struct node {
    char key[MAXSTRING];
    int value;
    struct node* next;
    struct node* previous;
} node;

typedef struct bucket {
    struct node* head;
    int count;
} bucket;

bucket* hashTable1, *hashTable2, *hashTable3;

struct node* createNode(char* key, int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    memcpy(newNode->key, key, strlen(key) + 1);
    newNode->value = value;
    newNode->next = NULL;
    newNode -> previous = NULL;
    return newNode;
}

int hashFunction1(char* key){
    return strlen(key) % BUCKET_SIZE;
}

int hashFunction2(char* key){
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i ++) sum += key[i];
    return sum % BUCKET_SIZE;
}

int hashFunction3(char* key){
    return (key[0]*key[1]) % BUCKET_SIZE;
}

void add(char* key, int value,int function) {
    int hashIndex;
    struct node* newNode = createNode(key, value);

    if (function == 1){
    hashIndex = hashFunction1(key);
    if (hashTable1[hashIndex].count == 0) {
        hashTable1[hashIndex].head = newNode;
        hashTable1[hashIndex].count = 1;
    } else {
        hashTable1[hashIndex].head->previous = newNode;
        newNode->next = hashTable1[hashIndex].head;
        hashTable1[hashIndex].head = newNode;
        hashTable1[hashIndex].count++;
      }
    }

    if (function == 2){
    hashIndex = hashFunction2(key);
    if (hashTable2[hashIndex].count == 0) {
        hashTable2[hashIndex].head = newNode;
        hashTable2[hashIndex].count = 1;
    } else {
        hashTable2[hashIndex].head->previous = newNode;
        newNode->next = hashTable2[hashIndex].head;
        hashTable2[hashIndex].head = newNode;
        hashTable2[hashIndex].count++;
      }
    }


    if (function == 3){
    hashIndex = hashFunction3(key);
    if (hashTable3[hashIndex].count == 0) {
        hashTable3[hashIndex].head = newNode;
        hashTable3[hashIndex].count = 1;
    } else {
        hashTable3[hashIndex].head->previous = newNode;
        newNode->next = hashTable3[hashIndex].head;
        hashTable3[hashIndex].head = newNode;
        hashTable3[hashIndex].count++;
    }
}
  }

void display(){
    struct node* iterator;

    printf("\n========= display for HT1 start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable1[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %s, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display for HT1 complete ========= \n");

    printf("\n========= display for HT2 start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable2[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %s, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display for HT2 complete ========= \n");
    printf("\n========= display for HT3 start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable3[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %s, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display for HT3 complete ========= \n");
}


// check if a character c is a digit
bool isDigit(char c) {
    if ('0' <= c && c <= '9') {
        return true;
    } else {
        return false;
    }
}

// append character c to string s
void appendChar(char* s, char c) {
    char charToStr[2];           // convert char to string
    charToStr[0] = c;
    charToStr[1] = '\0';          // put NUL to terminate string of one character
    strcat(s, charToStr);
}



int main() {
  
    char inputLine[MAXSTRING];   // temporary string to hold input line
    char cityStr[MAXSTRING];     // city name
    int  lineNum;                // line number (city rank)
    int  popInt;      // population
    int  state;                  // FSM state
    int  nextChar;               // index of next character in input string
    char temp[MAXSTRING];        // temp string to build up extracted strings from input characters


    FILE* fp;
    fp = fopen("pop.csv","r");
    
    hashTable1 = (bucket*) malloc(BUCKET_SIZE * sizeof(bucket));
    hashTable2 = (bucket*) malloc(BUCKET_SIZE * sizeof(bucket));
    hashTable3 = (bucket*) malloc(BUCKET_SIZE * sizeof(bucket));

    if (fp != NULL) {
        fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

        // ***** BEGIN FINTITE STATE MACHINE *****

        // STARTSTATE: digit -> S1
        // S1: digit -> S1; , -> S2
        // S2: " -> S3
        // S3: !" -> S3; " -> S4
        // S4: , -> S5
        // S5: " -> S6; ( -> ACCEPTSTATE
        // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE;
        // ACCEPTSTATE: done!
        // else go to ERRORSTATE
        //
        while (feof(fp) == 0){

            nextChar = 0;
            state = STARTSTATE;
            strcpy(temp,"");       // temp = ""

            if (nextChar >= strlen(inputLine)){
                // if no input string then go to ERRORSTATE
                state = ERRORSTATE;
            }

            while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
                switch (state) {
                    case STARTSTATE:
                        // look a digit to confirm a valid line
                        if (isDigit(inputLine[nextChar])) {
                            state = S1;
                            appendChar(temp, inputLine[nextChar]);
                        } else {
                            state = ERRORSTATE;
                        }
                        break;


                        // ADD YOUR CODE HERE
                    case S1:
                        // look for population digits
                        if (isDigit(inputLine[nextChar])) {
                            state = S1;
                            appendChar(temp, inputLine[nextChar]);
                        } else if (inputLine[nextChar] == ',') {
                            state = S2;
                        } else {
                            state = ERRORSTATE;
                        }
                        break;

                    case S2:
                        // look for opening quote of city name
                        if (inputLine[nextChar] == '\"') {
                            state = S3;
                            strcpy(cityStr,"");
                        } else {
                            state = ERRORSTATE;
                        }
                        break;

                    case S3:
                        // look for city name characters
                        if (inputLine[nextChar] != '\"') {
                            state = S3;
                            appendChar(cityStr, inputLine[nextChar]);
                        } else if (inputLine[nextChar] == '\"') {
                            state = S4;
                        } else {
                            state = ERRORSTATE;
                        }
                        break;

                    case S4:
                        // look for comma separator after city name
                        if (inputLine[nextChar] == ',') {
                            state = S5;
                        } else {
                            state = ERRORSTATE;
                        }
                        break;

                    case S5:
                        // look for opening parenthesis for state abbreviation
                        if (inputLine[nextChar] == '(') {
                            state = ACCEPTSTATE;
                            popInt = 0;
                        } else if (inputLine[nextChar] == '\"') {
                            popInt = 0;
                            state = S6;
                        } else {
                            state = ERRORSTATE;
                        }
                        break;

                    case S6:
                        // look for additional digits for population (optional)
                        if (isDigit(inputLine[nextChar])) {

                            popInt = popInt * 10 + (inputLine[nextChar] - '0');

                            state = S6;
                        } else if (inputLine[nextChar] == ',') {
                            state = S6;
                        }
                        else if (inputLine[nextChar] == '\"') {
                            state = ACCEPTSTATE;
                        } else {
                            state = ERRORSTATE;
                        }
                        break;


                    case ACCEPTSTATE:
                        // nothing to do - we are done!
                        break;

                    default:
                        state = ERRORSTATE;
                        break;
                } // end switch

                // advance input
                nextChar++;

            }	// end while state machine loop

            // ***** END FINITE STATE MACHINE *****
            
            add(cityStr, popInt, 1);
            add(cityStr, popInt, 2);
            add(cityStr, popInt, 3);

            // process the line - print out raw line and the parsed field

            // get next line
            fgets(inputLine, MAXSTRING, fp);

        } // end while file input loop
        display();
        fclose(fp);
        

    } else {
        printf("File not found!\n");
    }

    return 0;


  }
