// name: <your name here>
// email: <your email here>
// Compile with:
//
// gcc -lpthread hw12.c -o hw12
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 100

// shared variable
int counter = 0;
pthread_mutex_t lock;

// thread to be executed - unspecified variable arguments
void* thread1 (void* vargp) {
  // add 1 to counter
    pthread_mutex_lock(&lock);
    counter = counter +1;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread2 (void* vargp) {
  // add 5 to counter
  // *** YOUR CODE GOES HERE ***
    pthread_mutex_lock(&lock);
    counter = counter +5;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread3 (void* vargp) {
  // subtract 2 from counter
  // *** YOUR CODE GOES HERE ***
    pthread_mutex_lock(&lock);
    counter = counter -2;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread4 (void* vargp) {
  // subtract 10 from counter
  // *** YOUR CODE GOES HERE ***
    pthread_mutex_lock(&lock);
    counter = counter -10;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS*4];
  int i;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

  printf("Counter starts at %d\n", counter);

  for (i=0; i < NTHREADS; ++i){
    pthread_create(&(tid[i]), NULL, thread1, NULL);
    // *** YOUR CODE GOES HERE ***
      pthread_create(&(tid[i]), NULL, thread2, NULL);
      pthread_create(&(tid[i]), NULL, thread3, NULL);
      pthread_create(&(tid[i]), NULL, thread4, NULL);

  }

  for (i=0; i < NTHREADS*4; ++i){
    pthread_join(tid[i], NULL);
  }

  pthread_mutex_destroy(&lock);
  printf("Counter ends at %d\n", counter);

  return 0;
}
