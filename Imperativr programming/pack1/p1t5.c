#include <stdio.h>
int main(void){
    int A,B;
    scanf("%d %d", &A,&B);
    printf("%d\t", A/B);
    printf("%d\t",(A%B)+(A/B));
    printf("%d\t",A/B);
    printf("%d\n",A%B);
}