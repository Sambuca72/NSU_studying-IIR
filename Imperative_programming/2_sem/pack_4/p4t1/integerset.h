#pragma once

typedef struct IntegerSet 
{
    int *table;
    char* occupied;
    int size;
}IntegerSet;

IntegerSet* CreateSet(const int* arr, int size);

int IsInSet(const IntegerSet* set, int num);
