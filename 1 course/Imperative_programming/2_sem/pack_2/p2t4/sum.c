#include <stdint.h>
static int64_t *prefsum;
static int n_global;


void Init(const int *arr, int n){
    n_global = n;
    prefsum = (int64_t *)malloc(sizeof(int64_t)*(n)+1);
    prefsum[0]=0;
    for(int i = 0;i<n;i++){
        prefsum[i+1]=prefsum[i]+arr[i];
    }
}

int64_t Sum(int l, int r){
    if (l==r) return 0;
    return prefsum[r] - prefsum[l];
}