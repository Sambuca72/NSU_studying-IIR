#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int summ(int *A, int N){
    
    int sum=0;
    for(int i = 0; i<(N-1);i++){
        sum+=A[i]*(N-i-1);
    }
    return sum;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);

    int *m = (int *)malloc(n * sizeof(int));


    for (int i =0;i<n;i++){
        scanf("%d",&m[i]);    
    }

    qsort(m, n, sizeof(int), compare);
    int sum=summ(m,n);
    printf("%d",sum);
    free(m);
    fclose(stdin);
    fclose(stdout);
}

