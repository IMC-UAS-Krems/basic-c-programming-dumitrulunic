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
    char filename[11] = "matrix.txt";

    // WRITE YOUR CODE HERE
    //char buffer[100];


    if (argc != 3 ) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 0;
    }

    for (int i=1; i< argc; i++){
        if (argv[i]< 0){
            printf("Incorrect usage. The parameters you provided are not positive integers\n");
            return 1;
        }
    }

    int num_of_rows = atoi(argv[1]);
    int num_of_columns = atoi(argv[2]);

    // allocate pointers to matrix

    int **matrix = (int **)malloc(num_of_rows * sizeof(int *));
    for (int i = 0; i< num_of_rows; i++) {
        matrix[i] = (int *)malloc(num_of_columns * sizeof(int));
    }

    // populate matrix
    for (int i = 0; i< num_of_rows; i++) {
        for (int k = 0; k< num_of_columns; k++) {
            int random_number = minrand + rand() % (maxrand - minrand + 1);
            matrix[i][k] = random_number;
        }
    }

    // open file
    FILE *pFile = fopen(filename, "w");
    if (pFile == NULL) {
        printf("File can not be opened\n");
        return 1;
    }

    // write matrix to a file 
    for (int i = 0; i< num_of_rows; i++) {
        for (int k = 0; k< num_of_columns; k++) {
            fprintf(pFile, "%d", matrix[i][k]);
            if (k< num_of_columns - 1) {
                fprintf(pFile, " ");
            }
        }
        fprintf(pFile, "\n");
    }

    fclose(pFile);
    

    return 0;
}