#include <stdio.h>
#include <math.h>

int main() {
    int width = 600;
    int height = 400;
    
    FILE *file = fopen("japan_flag.ppm", "wb");
    if (!file) {
        perror("Cannot open file");
        return 1;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    
    unsigned char white[3] = {255, 255, 255};
    unsigned char red[3] = {190, 0, 41};
    
    int center_x = width / 2;
    int center_y = height / 2;
    int radius = (height * 3) / 10; 
  
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - center_x;
            int dy = y - center_y;
            
            if (dx * dx + dy * dy <= radius * radius) {
                fwrite(red, 1, 3, file);
            } else {
                fwrite(white, 1, 3, file);
            }
        }
    }
    
    fclose(file);
    printf("Japan flag saved as japan_flag.ppm\n");
    
    return 0;
}
