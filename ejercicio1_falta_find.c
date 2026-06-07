#include <stdio.h>
#include <stdlib.h>

/*
 * Encuentra la secuencia de 1s consecutivos mas larga en la
 * matriz, tratandola como un arreglo lineal (los 1s que
 * continuan en la siguiente fila cuentan como consecutivos).
 * Utiliza unicamente aritmetica de punteros, sin sintaxis [].
 *
 * Params:
 * int **matrix : puntero a la matriz cuadrada.
 * int size     : numero de filas y columnas.
 * int *result  : donde se almacena la longitud encontrada.
 */
void findLargestLine(int **matrix, int size, int *result) {
    // TODO: Implementar
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

/*
 * Imprime la matriz en stdout.
 *
 * Params:
 * int **matrix : puntero a la matriz.
 * int size     : numero de filas y columnas.
 */
void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

/*
 * Libera la memoria asignada a la matriz.
 *
 * Params:
 * int **matrix : puntero a la matriz a liberar.
 * int size     : numero de filas y columnas.
 */
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
