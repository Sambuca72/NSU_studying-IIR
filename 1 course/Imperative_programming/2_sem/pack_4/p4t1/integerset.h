 #pragma once

typedef struct IntegerSet IntegerSet;

IntegerSet* CreateSet(const int* arr, int size);

int IsInSet(const IntegerSet* set, int n);