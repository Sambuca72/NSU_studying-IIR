#include <stdio.h>
int main(void){
    int A,B;
    scanf("%d %d", &A, &B);
    printf("%d\n", A*B);
    printf("%d %d", A%B, B%A);
    return 0;
}

