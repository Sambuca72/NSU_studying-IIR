typedef struct Factors {
    int k;
    int primes[32];
    int powers[32];
} Factors;

void Factorize(int X, Factors *res) {
    res->k = 0;
    if (X == 1) {
        return;
    }
    int x = X;
    int prime = 2;
    
    
    while (x > 1) {
        int power = 0;
        while (x % prime == 0) {
            power++;
            x /= prime;
        }
        if (power > 0) {
            res->primes[res->k] = prime;
            res->powers[res->k] = power;
            res->k++;
        }
        
        if (prime == 2) prime = 3;
        else prime += 2;
        
        if (prime * prime > X && x > 1) {
            res->primes[res->k] = x;
            res->powers[res->k] = 1;
            res->k++;
            break;
        }
    }
}