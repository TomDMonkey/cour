#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    const int iterations = 10000; // Nombre de boucles
    pid_t pid;

    for (int i = 0; i < iterations; i++) {
        pid = fork(); // Création de la tâche fille
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            _exit(EXIT_SUCCESS);
        } else {
            if (wait(NULL) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("Boucle terminée : %d créations/terminaisons de tâches.\n", iterations);
    return 0;
}


// pour voir le temps :   time ./task_manager 
