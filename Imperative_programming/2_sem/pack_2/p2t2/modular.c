#include "modular.h"

int MOD = 0;

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



int pnorm(int a){
    int res = a % MOD;
    if (res < 0) res += MOD;
    return res;
}

int padd(int a, int b){
    return pnorm (a + b);
}
int psub(int a, int b){
    return pnorm (a - b);
}

int pdiv(int a, int b){
    if (b == 0) return 0;
    int inv = mod_inverse(b, MOD);
    return pmul(a, inv);
}

int pmul(int a, int b) {
    long long res = 0;    
    long long x = a;       
    
    while (b > 0) {
        if (b & 1) {      
            res = (res + x) % MOD; 
        }
        x = (x * 2) % MOD;    
        b >>= 1;              
    }
    return (int)res;          
}