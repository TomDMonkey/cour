#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ITERATIONS 10000

void *thread_function(void *arg) {
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    for (int i = 0; i < ITERATIONS; i++) {
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }

        if (pthread_join(thread, NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    printf("Boucle terminée : %d créations/terminaisons de threads.\n", ITERATIONS);
    return 0;
}
// pour voir le temps :   time 
