#include <stdio.h>
#include <stdlib.h>

// Lee una imagen PGM (formato P2) desde un archivo.
unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val) {
}

// Aplica un umbral T al arreglo de pixeles in_place.
void apply_threshold(unsigned char *pixels, int total, int threshold) {
}

// Genera el negativo de un arreglo de pixeles en un nuevo arreglo.
unsigned char *make_negative(unsigned char *pixels, int total) {
}

// Escribe un arreglo de pixeles como imagen PGM (formato P2).
void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val) {
}

// Calcula e imprime estadisticas del arreglo original y del arreglo umbralizado.
void print_stats(unsigned char *original, unsigned char *thresholded, int total) {
}

int main(void) {
    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;
    // El estudiante completa.
    return 0;
}
