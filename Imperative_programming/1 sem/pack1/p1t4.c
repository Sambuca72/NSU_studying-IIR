#include <stdio.h>
#include <math.h>
int main(void){
    int num,sq,flag;
    flag = 0;
    scanf("%d",&num);
    sq=sqrt(num);
    for(int i =2;i<=sq;i++){
        if(num%i==0){
            printf("NO");
            flag = 1;
            break;
        }
    }
    if (flag==0){
        printf("YES");
    }

}