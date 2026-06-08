#include <stdio.h>
#include <stdlib.h>

unsigned char *read_pgm(const char *filename, int *width, int *height, int *max_val) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    char format[3];
    fscanf(fp, "%2s", format);
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

    unsigned char *negative = malloc(total * sizeof(unsigned char));
    
    if (negative == NULL) {
        return NULL;
    }

    for (int i = 0; i < total; i++) {
        *(negative + i) = 255 - *(pixels + i);
    }

    return negative;
}
void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "%d\n", max_val);

    int total = width * height;
    for (int i = 0; i < total; i++) {
        fprintf(fp, "%d ", *(pixels + i)); 
    }

    fclose(fp);
}
void print_stats(unsigned char *original, unsigned char *thresholded, int total) {
    long suma = 0;
    int blancos = 0;
    int negros = 0;

    for (int i = 0; i < total; i++) {
       
        suma += *(original + i);
 
        if (*(thresholded + i) == 255) {
            blancos++;
        } else {
            negros++;
        }
    }

    float promedio = (float)suma / total;

    printf("Estadisticas:\n");
    printf("- Promedio de pixeles originales: %.2f\n", promedio);
    printf("- Pixeles blancos (255): %d\n", blancos);
    printf("- Pixeles negros (0): %d\n", negros);
}

int main() {
    int width, height, max_val, umbral;
    
    printf("Ingrese el valor del umbral (0-255): ");
    if (scanf("%d", &umbral) != 1 || umbral < 0 || umbral > 255) {
        return 1;
    }

    unsigned char *pixels = read_pgm("input.pgm", &width, &height, &max_val);
    if (pixels == NULL) return 1;

    int total = width * height;

    unsigned char *original = malloc(total * sizeof(unsigned char));
    if (original != NULL) {
        for (int i = 0; i < total; i++) {
            *(original + i) = *(pixels + i);
        }
    }

    apply_threshold(pixels, total, umbral);
    write_pgm("output_threshold.pgm", pixels, width, height, max_val);

    unsigned char *negative = make_negative(pixels, total);
    if (negative != NULL) {
        write_pgm("output_negative.pgm", negative, width, height, max_val);
    }

    print_stats(original, pixels, total);

    free(pixels);
    free(original);
    free(negative);

    return 0;
}
