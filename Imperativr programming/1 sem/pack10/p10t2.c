#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 1000000
#define MAX_STRING_SIZE 8

typedef struct {
    char **values;   
    int size;        
    int capacity;    
} DynamicArray;

void initArray(DynamicArray *array) {
    array->size = 0;
    array->capacity = 2;
    array->values = (char **)malloc(array->capacity * sizeof(char *));
}

void addToArray(DynamicArray *array, const char *value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;  
        array->values = (char **)realloc(array->values, array->capacity * sizeof(char *));
        
    }
    array->values[array->size] = strdup(value);
    
    array->size++;
}

void freeArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        free(array->values[i]);
    }
    free(array->values);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    
    DynamicArray *arrays = (DynamicArray *)malloc((MAX_KEY + 1) * sizeof(DynamicArray));
    

    
    for (int i = 0; i <= MAX_KEY; i++) {
        initArray(&arrays[i]);
    }

    
    for (int i = 0; i < n; i++) {
        int key;
        char value[MAX_STRING_SIZE];
        scanf("%d %s", &key, value);
        addToArray(&arrays[key], value);
    }

    
    for (int i = 0; i <= MAX_KEY; i++) {
        for (int j = 0; j < arrays[i].size; j++) {
            printf("%d %s\n", i, arrays[i].values[j]);
        }
        freeArray(&arrays[i]); 
    }

    free(arrays); 

    fclose(stdin);
    fclose(stdout);
    return 0;
}
