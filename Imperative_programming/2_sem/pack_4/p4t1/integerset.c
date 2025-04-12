//
#include "integerset.h"
#include <stdlib.h>

#define HASH_SIZE 300007 

static unsigned int hashfunc(int num) {
    return (unsigned int)num % HASH_SIZE;
}

IntegerSet* CreateSet(const int* arr, int size) {
    if (size < 0) return NULL;

    IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
    if (!set) return NULL;

    set->table = (int*)malloc(HASH_SIZE * sizeof(int));
    if (!set->table) {
        free(set);
        return NULL;
    }

    set->occupied = (char*)malloc(HASH_SIZE * sizeof(char));
    if (!set->occupied) {
        free(set->table);
        free(set);
        return NULL;
    }

    set->size = size;

    for (int i = 0; i < HASH_SIZE; i++) {
        set->occupied[i] = 0; 
    }

    if (size == 0) return set;

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        unsigned int idx = hashfunc(num);
        unsigned int start_idx = idx;

        
        while (set->occupied[idx]) {
            if (set->table[idx] == num) { 
                free(set->occupied);
                free(set->table);
                free(set);
                return NULL;
            }
            idx = (idx + 1) % HASH_SIZE; 
            if (idx == start_idx) { // 
                free(set->occupied);
                free(set->table);
                free(set);
                return NULL;
            }
        }
        set->table[idx] = num;
        set->occupied[idx] = 1; 
    }
    return set;
}

int IsInSet(const IntegerSet* set, int num) {
    if (!set || set->size == 0) return 0;

    unsigned int idx = hashfunc(num);
    unsigned int start_idx = idx;

    while (set->occupied[idx]) {
        if (set->table[idx] == num) return 1;
        idx = (idx + 1) % HASH_SIZE;
        if (idx == start_idx) break; 
    }
    return 0;
}