#include <stdio.h>

int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);

    while(T--){
        int A,B,x,y;
        scanf("%d %d",&A, &B);

        printf("%d\n",extended_gcd(A,B,&x,&y));

    }

    fclose(stdin);
    fclose(stdout);
}