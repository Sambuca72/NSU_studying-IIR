#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// #include "query.c"
// #include "sum.c"

extern void Init(const int *arr, int n);
extern int Query(int l, int64_t sum, int n);

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N,M;
    scanf("%d %d",&N,&M);

    int *A = (int *)malloc(sizeof(int) * N);
    for(int i = 0;i<N;i++){
        scanf("%d",&A[i]);
    }

    Init(A,N);

    for (int i = 0; i < M; i++) {
        int L;
        int64_t S;
        scanf("%d %ld", &L, &S);
        int R = Query(L, S,N);
        printf("%d\n", R);
    }

    free(A);


    fclose(stdin);
    fclose(stdout);
}