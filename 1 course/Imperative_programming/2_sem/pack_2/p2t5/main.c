#include <stdio.h>
// #include "factorize.c"

// extern void Factorize(int X, Factors *res);

typedef struct Factors {
    int k; //сколько различных простых в разложении
    int primes [32]; //различные простые в порядке возрастания
    int powers [32]; //в какие степени надо эти простые возводить
    } Factors;

extern void Factorize(int X, Factors *res);

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int M;
    scanf("%d",&M);
    for (int i = 0; i < M; i++){
        int X;
        scanf("%d", &X);

        Factors factors;
        Factorize (X, &factors);

        printf("%d = ",X);

        if (factors.k == 0) {
            printf("1");
        } else {
            for (int j = 0; j < factors.k; j++) {
                printf("%d^%d", factors.primes[j], factors.powers[j]);
                if (j < factors.k - 1) {
                    printf(" * ");
                }
            }
        }
        printf("\n");


    }

    fclose(stdin);
    fclose(stdout);
}