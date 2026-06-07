#include <stdio.h>
#include <stdlib.h>


void findLargestLine(int **matrix, int size, int *result) {
    int rachaActual = 0;
    int rachaMaxima = 0;
    int totalElementos = size * size;
    int *punteroLineal = *matrix;

    for (int k = 0; k < totalElementos; k++) {
        
        if (*(punteroLineal + k) == 1) {
            rachaActual++;
            
            if (rachaActual > rachaMaxima) {
                rachaMaxima = rachaActual;
            }
        } else {
            rachaActual = 0;
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

    /* El estudiante completa: leer size, llamar allocateMatrix,
     * fillMatrix, printMatrix, findLargestLine y freeMatrix. */

    printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);
    return 0;
}
