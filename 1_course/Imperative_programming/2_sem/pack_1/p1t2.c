#include <stdio.h>
#include <stdlib.h>

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


int mod_inverse(int a, int m) {
    int x, y;
    int gcd = extended_gcd(a, m, &x, &y);
    if (gcd != 1)
        return -1;

    int inv = x % m;
    if (inv < 0)
        inv += m;
    return inv;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T,M;
    scanf("%d %d",&T,&M);

    while (T--){
        int a,inv;
        scanf("%d",&a);
        
        inv = mod_inverse(a,M);
        printf("%d\n",inv);
    }

    fclose(stdin);
    fclose(stdout);
}


//log(min(a,b))