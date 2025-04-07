#include "integerset.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
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
    printf("%p\n",myarr+1);
    IntegerSet *s15 = CreateSet(myarr + 1, 2);
    // printf("pupupu3\n");
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
}