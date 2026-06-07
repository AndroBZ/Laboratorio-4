#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findLargestLine(int **matrix, int size, int *result) {
    int rachaActual = 0;
    int rachaMaxima = 0;

    for (int i = 0; i < size; i++) {
        int *filaActual = *(matrix + i);
        
        for (int j = 0; j < size; j++) {
            if (*(filaActual + j) == 1) {
                rachaActual++;
                if (rachaActual > rachaMaxima) {
                    rachaMaxima = rachaActual;
                }
            } else {
                rachaActual = 0;
            }
        }
    }
    *result = rachaMaxima;
}

void allocateMatrix(int ***matrix, int size) {

    *matrix = malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = malloc(size * sizeof(int));
    }
}

void fillMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix + i) + j) = rand() % 2;
        }
    }
}

void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}


void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

int main(void) {
    int size, largestLine = 0;
    int **matrix = NULL;

    printf("Ingrese el tamaño de la matriz: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        return 1;
    }

    srand(time(NULL));

    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    
    printf("\nMatriz generada:\n");
    printMatrix(matrix, size);

    findLargestLine(matrix, size, &largestLine);

    printf("\nLa secuencia mas larga de 1s es: %d\n", largestLine);

    freeMatrix(matrix, size);

    return 0;
}
