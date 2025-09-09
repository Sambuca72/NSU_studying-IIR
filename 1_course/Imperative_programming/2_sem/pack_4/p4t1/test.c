#include "integerset.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#define HASH_SIZE 3000007 

int main() {
    int myarr[] = {1, 2, 3};
//create set with numbers 1, 2, and 3
    IntegerSet *s123 = CreateSet(myarr , 3);
    printf("pupupu1\n");
    myarr [1] = -5;
    assert(IsInSet(s123 , 3) == 1 && IsInSet(s123 , 2) == 1);
    assert(IsInSet(s123 , 0) == 0 && IsInSet(s123 , 4) == 0);
    printf("pupupu2\n");
    //create set with numbers -5 and 3
    // printf("%p\n",myarr+1);
    IntegerSet *s15 = CreateSet(myarr + 1, 2);
    printf("pupupu3\n");
    assert(IsInSet(s15 , 3) == 1 && IsInSet(s15 , -5) == 1);
    assert(IsInSet(s15 , 1) == 0 && IsInSet(s15 , 2) == 0);
    printf("pupupu4\n");
    //create empty set (note: null pointer is allowed only when size is 0)
    IntegerSet *sEmpty = CreateSet(0, 0);
    printf("pupupu5\n");
    assert(sEmpty != 0);
    printf("pupupu6\n");
    assert(IsInSet(sEmpty , 0) == 0 );
    printf("pupupu7\n");
    assert(IsInSet(sEmpty , -123456789) == 0);
    printf("pupupu8\n");
    IntegerSet *sNull = 0;
    //null pointer must be treated by IsInSet as empty set
    assert(IsInSet(sNull , 0) == 0 && IsInSet(sNull , -123456789) == 0);
    
    myarr [0] = -5;
    //if array has equal elements, then CreateSet must return 0
    IntegerSet *sBad = CreateSet(myarr , 3);
    printf("pupupu9\n");
    assert(sBad == 0);
    printf("pupupu10\n");
    int largearr [] = {1, 5, INT_MAX , INT_MIN , 1000000000 , -123, 555, 0};
    //create set with 8 numbers from largearr
    IntegerSet *sLarge = CreateSet(largearr , 8);
    assert(IsInSet(sLarge , INT_MAX) == 1);
    printf("pupupu11\n");
    // assert (IsInSet(sLarge , INT_MIN) == 1);
    printf("%d\n",IsInSet(sLarge, INT_MIN));
    int test[]={INT_MIN};
    IntegerSet *testt = CreateSet(test,1);
    printf("%d\n",IsInSet(testt,INT_MIN)); 
    printf("pupupu12\n");
    assert(IsInSet(sLarge , 1000000000) == 1 && IsInSet(sLarge , -123) == 1);
    printf("pupupu13\n");
    assert(IsInSet(sLarge , 123) == 0 && IsInSet(sLarge , -5) == 0);
    largearr [1] = 5;
    sLarge = CreateSet(largearr , 8); //same set as previously
    assert(IsInSet(sLarge , 5) == 1);
    largearr [7] = 5;
    sLarge = CreateSet(largearr , 8); //now it has equal elements
    assert(sLarge == 0);
    return 0;
// }

// #include <assert.h>
// #include <limits.h>
// #include "integerset.h"
// #include <stdio.h>



// int main() {
    // Тест 1: Пустое множество
    IntegerSet* empty_set = CreateSet(NULL, 0);
    assert(empty_set != NULL);
    assert(empty_set->size == 0);
    assert(IsInSet(empty_set, 42) == 0);
    assert(IsInSet(empty_set, INT_MAX) == 0);

    // Тест 2: Множество с одним элементом
    int single_arr[] = {42};
    IntegerSet* single_set = CreateSet(single_arr, 1);
    assert(single_set != NULL);
    assert(single_set->size == 1);
    assert(IsInSet(single_set, 42) == 1);
    assert(IsInSet(single_set, 43) == 0);

    // Тест 3: Множество с дубликатами
    int dup_arr[] = {1, 2, 1};
    IntegerSet* dup_set = CreateSet(dup_arr, 3);
    assert(dup_set == NULL); // Дубликаты запрещены

    // Тест 4: Максимальный размер одного множества (10^5)
    int large_arr[100000];
    for (int i = 0; i < 100000; i++) {
        large_arr[i] = i; // Уникальные числа от 0 до 99999
    }
    IntegerSet* large_set = CreateSet(large_arr, 100000);
    assert(large_set != NULL);
    assert(large_set->size == 100000);
    assert(IsInSet(large_set, 0) == 1);
    assert(IsInSet(large_set, 50000) == 1);
    assert(IsInSet(large_set, 99999) == 1);
    assert(IsInSet(large_set, 100000) == 0);

    // Тест 5: Сумма размеров всех множеств (3*10^5)
    int set1_arr[100000];
    int set2_arr[100000];
    int set3_arr[100000];
    for (int i = 0; i < 100000; i++) {
        set1_arr[i] = i;           // 0..99999
        set2_arr[i] = i + 100000;  // 100000..199999
        set3_arr[i] = i + 200000;  // 200000..299999
    }
    IntegerSet* set1 = CreateSet(set1_arr, 100000);
    IntegerSet* set2 = CreateSet(set2_arr, 100000);
    IntegerSet* set3 = CreateSet(set3_arr, 100000);
    assert(set1 != NULL && set2 != NULL && set3 != NULL);
    assert(set1->size == 100000 && set2->size == 100000 && set3->size == 100000);
    assert(IsInSet(set1, 50000) == 1 && IsInSet(set1, 150000) == 0);
    assert(IsInSet(set2, 150000) == 1 && IsInSet(set2, 50000) == 0);
    assert(IsInSet(set3, 250000) == 1 && IsInSet(set3, 150000) == 0);

    // Тест 6: Граничные значения (INT_MAX, INT_MIN)
    int edge_arr[] = {INT_MIN, 0, INT_MAX};
    IntegerSet* edge_set = CreateSet(edge_arr, 3);
    assert(edge_set != NULL);
    assert(edge_set->size == 3);
    assert(IsInSet(edge_set, INT_MIN) == 1);
    assert(IsInSet(edge_set, 0) == 1);
    assert(IsInSet(edge_set, INT_MAX) == 1);
    assert(IsInSet(edge_set, 1) == 0);

    // Тест 7: Отрицательный размер
    IntegerSet* neg_set = CreateSet(NULL, -1);
    assert(neg_set == NULL);

    // Тест 8: Передача NULL в IsInSet
    assert(IsInSet(NULL, 42) == 0);
    assert(IsInSet(NULL, INT_MAX) == 0);

    // Тест 9: Поиск отсутствующих элементов
    int small_arr[] = {1, 3, 5};
    IntegerSet* small_set = CreateSet(small_arr, 3);
    assert(small_set != NULL);
    assert(IsInSet(small_set, 1) == 1);
    assert(IsInSet(small_set, 2) == 0);
    assert(IsInSet(small_set, 4) == 0);
    assert(IsInSet(small_set, 6) == 0);

    // Тест 10: Коллизии в хэш-функции
    int collision_arr[] = {0, HASH_SIZE, 2 * HASH_SIZE};
    IntegerSet* collision_set = CreateSet(collision_arr, 3);
    assert(collision_set != NULL);
    assert(collision_set->size == 3);
    assert(IsInSet(collision_set, 0) == 1);
    assert(IsInSet(collision_set, HASH_SIZE) == 1);
    assert(IsInSet(collision_set, 2 * HASH_SIZE) == 1);
    assert(IsInSet(collision_set, HASH_SIZE + 1) == 0);

    // Тест 11: Множество с одним элементом, равным INT_MIN
    int min_arr[] = {INT_MIN};
    IntegerSet* min_set = CreateSet(min_arr, 1);
    assert(min_set != NULL);
    assert(min_set->size == 1);
    assert(IsInSet(min_set, INT_MIN) == 1);
    assert(IsInSet(min_set, 0) == 0);

    // Тест 12: Множество с одним элементом, равным INT_MAX
    int max_arr[] = {INT_MAX};
    IntegerSet* max_set = CreateSet(max_arr, 1);
    assert(max_set != NULL);
    assert(max_set->size == 1);
    assert(IsInSet(max_set, INT_MAX) == 1);
    assert(IsInSet(max_set, 0) == 0);

    // Тест 13: Множество с числами близкими к HASH_SIZE
    int near_hash_arr[] = {HASH_SIZE - 1, HASH_SIZE, HASH_SIZE + 1};
    IntegerSet* near_hash_set = CreateSet(near_hash_arr, 3);
    assert(near_hash_set != NULL);
    assert(near_hash_set->size == 3);
    assert(IsInSet(near_hash_set, HASH_SIZE - 1) == 1);
    assert(IsInSet(near_hash_set, HASH_SIZE) == 1);
    assert(IsInSet(near_hash_set, HASH_SIZE + 1) == 1);
    assert(IsInSet(near_hash_set, HASH_SIZE + 2) == 0);

    int arrrrr[] ={1};
    IntegerSet* heh = CreateSet(arrrrr,1000000);
    assert(IsInSet(heh, 100000)==0);

    return 0;
}