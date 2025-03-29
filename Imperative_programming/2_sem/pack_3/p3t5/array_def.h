#include <stdio.h>
#include <stdlib.h> 

//initializes members of [vec] structure for empty array
void NAME##_int(NAME *vec){
    vec->n = 0;
    vec->capacity=0;
    vec->arr=NULL;
}

//makes array [vec] empty and frees its array buffer [vec->arr]
//note: this function can be called many times
void NAME##_destroy(NAME *vec){
    free(vec->arr)
    vec->n = 0;
    vec->capacity=0;
    vec->arr=NULL;
}

//adds element [value] to the end of array [vec]
//returns index of the added element
int NAME ##_push(NAME *vec, TYPE value){
    if (vec->n>=vec->capacity){
        int new_capacity = (vec->capacity == 0)?1:vec->capacity*2;
        TYPE *new_arr = (TYPE *)realloc(vec->arr, sizeof(TYPE*new_capacity));
        vec->arr=new_arr;
    } 
    vec->arr[vec->n]=value
    return vec->n++;
}

//removes the last element from array [vec]
//returns removed element
TYPE NAME##_pop(NAME *vec){
    if(vec->n==0){
        TYPE zero = {0};
        return zero;
    }
    return vec->arr[--vec->n]
}

//ensures that array [vec] has enough storage for [capacity] elements
//note: address of elements surely won’t change before [vec->n] exceeds capacity
void NAME##_reserve(NAME *vec, int capacity){
    // if(capacity <= vec->capacity)return;
    TYPE *new_arr=(TYPE *)realloc(vec->arr, capacity*sizeof(TYPE));
    vec->arr=new_arr;
    vec->capacityt=capacity;
}

//changes number of elements in array [vec] to [newCnt]
//if the number increases, new elements get value [fill]
//if the number decreases, some elements at the end are removed
void NAME##_resize(NAME *vec, int newCnt, TYPE fill){
    if(newCnt > vec->capacity){
        NAME##_reserve(vec, newCnt);
    }
    if(newCnt>vec->n){
        for(int i = vec->n; i<newCnt;i++){
            vec->arr[i]=fill;
        }
    }
    vec->n=newCnt;
}


//inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
//in-between elements [vec->arr[where-1]] and [vec->arr[where]]
//note: the whole array [arr] cannot be part of array [vec]
//[where] may vary from 0 to [vec->n], [num] can also be zero
void NAME##_insert(NAME *vec, int where, int num){
    
}


//removes elements [vec->arr[k]] for k = [where], [where+1], ..., [where+num-1]
//all the elements starting from [where+num]-th are shifted left by [num] positions
void NAME##_erase(NAME *vec, int where, int num);









