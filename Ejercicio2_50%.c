#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    char format[3];
    fscanf(fp, "%2s", format); // Lee "P2"
    fscanf(fp, "%d %d", width, height);
    fscanf(fp, "%d", max_val);

    int total = (*width) * (*height);
    unsigned char *pixels = malloc(total * sizeof(unsigned char));

    if (!pixels) {
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < total; i++) {
        int temp;
        fscanf(fp, "%d", &temp);
        *(pixels + i) = (unsigned char)temp;
    }

    fclose(fp);
    return pixels;
}

void apply_threshold(unsigned char *pixels, int total, int threshold) {
    for (int i = 0; i < total; i++) {
        if (*(pixels + i) >= threshold) {
            *(pixels + i) = 255; 
        } else {
            *(pixels + i) = 0;   
        }
    }
}
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
