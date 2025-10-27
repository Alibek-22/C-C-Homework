#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - x0;
            int dy = y - y0;
            if (dx * dx + dy * dy <= r * r) {
                data[y * width + x] = c;
            }
        }
    }
}

Color random_color() {
    Color c;
    c.r = rand() % 256;
    c.g = rand() % 256;
    c.b = rand() % 256;
    return c;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <n> <min_radius> <max_radius>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    
    if (n <= 0 || a <= 0 || b <= 0 || a > b) {
        fprintf(stderr, "Invalid parameters\n");
        return 1;
    }

    srand(time(NULL));

    int width = 800;
    int height = 600;
    
    Color *canvas = (Color*)malloc(width * height * sizeof(Color));
    for (int i = 0; i < width * height; i++) {
        canvas[i].r = 0;
        canvas[i].g = 0;
        canvas[i].b = 0;
    }

    for (int i = 0; i < n; i++) {
        int x0 = rand() % width;
        int y0 = rand() % height;
        int r = a + rand() % (b - a + 1);
        Color c = random_color();
        
        draw_circle(canvas, width, height, x0, y0, r, c);
    }

    FILE *file = fopen("circles.ppm", "wb");
    if (!file) {
        perror("Cannot open file");
        free(canvas);
        return 1;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(canvas, sizeof(Color), width * height, file);
    fclose(file);
    
    printf("Saved %d random circles to circles.ppm\n", n);
    
    free(canvas);
    return 0;
}
