#pragma once

typedef struct NAME {
    int n; 
    TYPE *arr;
    int capacity; 
}NAME; 

void NAME##_int(NAME *vec);
void NAME##_destroy(NAME *vec);
int NAME ##_push(NAME *vec, TYPE value);
TYPE NAME##_pop(NAME *vec);
void NAME##_reserve(NAME *vec, int capacity);
void NAME##_resize(NAME *vec, int newCnt, TYPE fill);
void NAME##_insert(NAME *vec, int where, int num);
void NAME##_erase(NAME *vec, int where, int num);
