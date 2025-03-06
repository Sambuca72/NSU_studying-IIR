#include <stdio.h>

#define MOD 1000000007
#define MAX_N 1000000

long long fact[MAX_N + 1];      
long long invFact[MAX_N + 1];   


long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}


void preprocess() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    

    invFact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD);
    

    for (int i = MAX_N - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}


long long binomial(int N, int K) {
    if (K < 0 || K > N) return 0;
    return (fact[N] * invFact[K] % MOD) * invFact[N - K] % MOD;
}

int main() {
    preprocess(); 
    
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);

    int T, N, K;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &K);
        printf("%lld\n", binomial(N, K));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


// O(NlogM+T)


//можно использовать цепные дроби и алгоритм евклида