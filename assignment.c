#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    FILE *pFile = NULL;
    char buffer[100];


    if (argc != 2) {
        sprintf(buffer, "Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc);
        return 0;
    }
    

    return 0;
}
