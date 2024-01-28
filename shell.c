#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void processInput(char* input){
    //convert everything to lowercase
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if(strcmp(input, "exit") == 0){
        exit(0); //exit loop, end the program
    } else if(strcmp(input, "ping") == 0){
        printf("pong\n"); //haha!
    }
}

int main() {
    while (1) { // Infinite loop for the shell
        printf("shell> ");

        size_t size = 100;
        char *input = malloc(size * sizeof(char));
        if (input == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        int ch;
        size_t len = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            input[len++] = ch;

            // Reallocate when buffer is close to being full
            if (len == size) {
                size *= 2; // Double the size
                char *temp = realloc(input, size * sizeof(char));
                if (temp == NULL) {
                    free(input);
                    perror("Failed to reallocate memory");
                    exit(EXIT_FAILURE);
                }
                input = temp;
            }
        }
        input[len] = '\0'; // Null-terminate the input string

        processInput(input);

        free(input); // Free the allocated memory after processing
    }
    return 0;
}