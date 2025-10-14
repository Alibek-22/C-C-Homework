#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char** get_test_strings() {
    char** strings = malloc(3 * sizeof(char*)); /
    
    strings[0] = malloc(4 * sizeof(char)); 
    strcpy(strings[0], "Cat");
    
    strings[1] = malloc(6 * sizeof(char)); 
    strcpy(strings[1], "Mouse");
    
    strings[2] = NULL; 
    
    return strings;
}

void print_strings(const char** string_array) {
    if (string_array == NULL) return;
    
    for (int i = 0; string_array[i] != NULL; i++) {
        printf("%s\n", string_array[i]);
    }
}

size_t* get_sizes(const char** string_array) {
    if (string_array == NULL) return NULL;
    
    int count = 0;
    while (string_array[count] != NULL) {
        count++;
    }
    
    size_t* sizes = malloc(count * sizeof(size_t));
    
    for (int i = 0; i < count; i++) {
        sizes[i] = strlen(string_array[i]);
    }
    
    return sizes;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return NULL;
    }
    
    int line_count = 0;
    int ch, prev_ch = '\0';
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
        prev_ch = ch;
    }
    if (prev_ch != '\n' && prev_ch != EOF) {
        line_count++;
    }
    
    fseek(file, 0, SEEK_SET);
    int* line_lengths = malloc(line_count * sizeof(int));
    
    int current_line = 0;
    int current_length = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_lengths[current_line++] = current_length;
            current_length = 0;
        } else {
            current_length++;
        }
    }
    if (current_length > 0) {
        line_lengths[current_line] = current_length;
    }
    
    char** lines = malloc((line_count + 1) * sizeof(char*));

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < line_count; i++) {
        lines[i] = malloc((line_lengths[i] + 1) * sizeof(char));
        for (int j = 0; j < line_lengths[i]; j++) {
            lines[i][j] = fgetc(file);
        }
        lines[i][line_lengths[i]] = '\0';
        fgetc(file); 
    }
    lines[line_count] = NULL; 
    
    free(line_lengths);
    fclose(file);
    
    return lines;
}

void destroy_strings(char*** p_string_array) {
    if (p_string_array == NULL || *p_string_array == NULL) return;
    
    char** strings = *p_string_array;
    
    for (int i = 0; strings[i] != NULL; i++) {
        free(strings[i]);
    }
    
    free(strings);
    
    *p_string_array = NULL;
}

void sort_strings(char** words) {
    if (words == NULL) return;
    
   
    int count = 0;
    while (words[count] != NULL) {
        count++;
    }
    
   
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Использование: %s <входной_файл> <выходной_файл>\n", argv[0]);
        printf("Пример: %s invisible_man.txt result.txt\n", argv[0]);
        return 1;
    }
    
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    
    char** lines = load_lines(input_filename);
    if (lines == NULL) {
        printf("Ошибка загрузки файла %s\n", input_filename);
        return 1;
    }
    
    sort_strings(lines);
    
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Ошибка создания файла %s\n", output_filename);
        destroy_strings(&lines);
        return 1;
    }
    
    for (int i = 0; lines[i] != NULL; i++) {
        fprintf(output_file, "%s\n", lines[i]);
    }
    
    fclose(output_file);
    destroy_strings(&lines);
    
    printf("Файл успешно отсортирован и сохранен как %s\n", output_filename);
    
    return 0;
}
