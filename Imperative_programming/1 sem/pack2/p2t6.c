#include <stdio.h>
#include <stdlib.h>

int integer_pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,num,flag,c,ch;
    ch=0;
    char b;
    scanf("%d\n", &n);
    if (n%8>0){
        c=(n-n%8)/8+1;
    }
    else{
        c=n/8;
    }
    if (n==8){
        c=1;
    }
    int m[c];
    flag = 0;
    num=0;
    int d;

    for (int i =1;i < n+1;i++){
        if (flag == 8){
                flag=0;
                
                num=0;
                ch++;
            }
            scanf("%c",&b);
            int d = atoi(&b);
            num+=(integer_pow(2,flag))*d;
            m[ch]=num;
            flag++;
            }
    for(int j = 0; j < c; j++) {
        printf("%d ", m[j]);
    }
    fclose(stdin);
    fclose(stdout);
}