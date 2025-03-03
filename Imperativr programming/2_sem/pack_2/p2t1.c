#include <stdio.h>
#include <stdlib.h>

long long extended_gcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}


long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long gcd = extended_gcd(a, m, &x, &y);
    if (gcd != 1)
        return -1;

    long long inv = x % m;
    if (inv < 0)
        inv += m;
    return inv;
}

long long CRT (int k, long long *a,long long *m){
    long long M=1 ;
    for(int i = 0;i<k;i++){
        M*=m[i];
    }

    long long x =0;
    for(int i =0;i<k;i++){
        long long Mi=M/m[i];
        long long inv = mod_inverse(Mi,m[i]);
        x = (x + ((a[i] * Mi) % M * inv) % M) % M;

    }

    return x;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    scanf("%d",&k);

    long long *a = (long long *)malloc(k * sizeof(long long));
    long long *m = (long long *)malloc(k * sizeof(long long));

    for(int i = 0; i<k;i++){
        scanf("%lld",&m[i]);
    }
    for(int i = 0;i<k;i++){
        scanf("%lld", &a[i]);
    }
    
    printf("%lld",CRT(k,a,m));
    

    fclose(stdin);
    fclose(stdout);
}