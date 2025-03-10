typedef struct Factors {
    int k; 
    int primes [32];
    int powers [32];
    } Factors;

void Factorize(int X, Factors *res){
    res -> k = 0;
    
    if (X == 1) 
        return;
    
    int x = X;
    int prime = 2;

    while (x>1&&prime*prime >= x){
        int power = 0;
        while(x % prime == 0){
            power++;
            x /= prime;
        }
        
        if (power > 0){
            res -> primes[res -> k] = prime;
            res -> powers[res -> k] = power;
            res -> k++;
        }

        prime++;
        if (prime == 4) prime = 5; 
        else if (prime > 3) prime += 2;
    }

    if (x > 1) {
        res->primes[res->k] = x;
        res->powers[res->k] = 1;
        res->k++;
    }
}