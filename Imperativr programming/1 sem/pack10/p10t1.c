#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int binary_search(int *arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; 
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int N, M;
    
    scanf("%d", &N);
    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    
    scanf("%d", &M);
    int *B = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }

    
    qsort(B, M, sizeof(int), compare);

    
    int *result = (int*)malloc(N * sizeof(int));
    int result_count = 0;

    
    for (int i = 0; i < N; i++) {
        if (i > 0 && A[i] == A[i - 1])
            continue;

        if (binary_search(B, M, A[i])==0) {
            result[result_count] = A[i];
            result_count++;
        }
    }

    qsort(result, result_count, sizeof(int), compare);

    printf("%d\n", result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d ", result[i]);
    }
    

    
    free(A);
    free(B);
    free(result);


    fclose(stdin);
    fclose(stdout);
    return 0;
}
