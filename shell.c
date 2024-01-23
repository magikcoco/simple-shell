#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; //buffer for user input
    while (1) {
        printf("shell> "); //input prompt
        fgets(input, 100, stdin); //read the input
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "exit") == 0){
            break; //exit loop, end the program
        }

        if(strcmp(input, "Ping") == 0){
            printf("Pong\n"); //haha!
        }
    }
    return 0;
}