//Enter your name here
//Enter your email here
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

pthread_mutex_t chopstick[5];//lock variable

// Thread to be executed
void *philosopher(void *x) {
    //Treat variable x as a pointer to an int and then extract the value into n
    int *a = (int *) x;
    int n = *a;
    //Treat variable x as a pointer to an int and then extract the value into n
    int left_chopstick = n;
    int right_chopstick = (n + 1) % 5;

    printf("Philosopher %d is thinking\n", n);

    // Wait for both chopsticks to be available before picking them up
    pthread_mutex_lock(&chopstick[left_chopstick]);
    pthread_mutex_lock(&chopstick[right_chopstick]);

    printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d]\n", n, left_chopstick, right_chopstick);
    sleep(2);

    // Release both chopsticks
    pthread_mutex_unlock(&chopstick[right_chopstick]);
    pthread_mutex_unlock(&chopstick[left_chopstick]);
    printf("Philosopher %d finished eating.\n", n);

}


/*------------ Main Program---------*/
int main()
{
    int i,val[5];
    pthread_t threads[5];
    //initializing the mutex (for chopsticks)
    for(i=0;i<5;i++){
        pthread_mutex_init(&chopstick[i],NULL);
    }   

    //create and run the thread
    for(i=0;i<5;i++){
        val[i]=i;
        pthread_create(&threads[i],NULL,(void *)philosopher,&val[i]);
    }
    
    //wait until all the threads are done
    for(i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
    
    // Destroying the mutex
    for(i=0;i<5;i++){
        pthread_mutex_destroy(&chopstick[i]);
    }
    
    return 0;
}