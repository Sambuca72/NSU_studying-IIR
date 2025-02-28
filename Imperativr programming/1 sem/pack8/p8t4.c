#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void bson_to_json(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "w");


    // Читаем размер BSON-документа
    int32_t doc_size;
    fread(&doc_size, sizeof(int32_t), 1, input);

    fprintf(output, "{\n");

    // Парсим поля
    int first_field = 1;
    while (1) {
        uint8_t type;
        fread(&type, sizeof(uint8_t), 1, input);

        if (type == 0) // Конец документа
            break;

        if (!first_field)
            fprintf(output, ",\n");
        first_field = 0;

        // Считываем имя поля
        char field_name[256];
        int pos = 0;
        while (1) {
            fread(&field_name[pos], sizeof(char), 1, input);
            if (field_name[pos] == '\0') break;
            pos++;
        }

        fprintf(output, "  \"%s\": ", field_name);

        // Обрабатываем значение в зависимости от типа
        switch (type) {
        case 1: { // double
            double value;
            fread(&value, sizeof(double), 1, input);
            fprintf(output, "%0.15g", value);
            break;
        }
        case 2: { // string
            int32_t length;
            fread(&length, sizeof(int32_t), 1, input);
            char *value = (char *)malloc(length);
            fread(value, sizeof(char), length, input);
            value[length - 1] = '\0'; 
            fprintf(output, "\"%s\"", value);
            free(value);
            break;
        }
        case 8: { // bool
            uint8_t value;
            fread(&value, sizeof(uint8_t), 1, input);
            fprintf(output, value ? "true" : "false");
            break;
        }
        case 10: { // null
            fprintf(output, "null");
            break;
        }
        case 16: { // int32
            int32_t value;
            fread(&value, sizeof(int32_t), 1, input);
            fprintf(output, "%d", value);
            break;
        }
        case 18: { // int64
            int64_t value;
            fread(&value, sizeof(int64_t), 1, input);
            fprintf(output, "%lld", value);
            break;
        }}
        
    }

    fprintf(output, "\n}\n");

    fclose(input);
    fclose(output);
}

int main() {
    bson_to_json("input.txt", "output.txt");
    return 0;
}
