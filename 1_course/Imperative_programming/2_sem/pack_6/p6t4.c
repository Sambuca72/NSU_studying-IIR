// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>

// //можно ли быстрее n**2 

// int find_biggest_balls(int32_t *balls, int N, int *previous_balls, int *max_idx){

//     int *dp = (int*)malloc(N * sizeof(int));
//     for (int i = 0; i < N; i++) {
//         dp[i] = 1;
//         previous_balls[i] = -1;
//     }

//     int maxlen = 1;
//     *max_idx = 0;


//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < i; j++){
//             if(balls[j] < balls[i] && dp[j] + 1 > dp[i]){
//                 dp[i] = dp[j] + 1;
//                 previous_balls[i] = j;
//             }

//         }
//         if(dp[i] > maxlen){
//                 maxlen = dp[i];
//                 *max_idx = i;
//         }
//     }    
//     free(dp);
//     return maxlen;
// }

// int main(){
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int N;
//     scanf("%d", &N);

//     int32_t *massiveballs = (int32_t*)malloc(N * sizeof(int32_t));
//     int *balls_index = (int*)malloc(N * sizeof(int));
//     int *prev = (int*)malloc(N * sizeof(int));


//     for(int i = 0; i < N; i++){
//         scanf("%d", &massiveballs[i]);
//     }

//     int max_idx;
//     int len = find_biggest_balls(massiveballs, N, balls_index, &max_idx);

//     printf("%d\n", len);

//     int pos = max_idx;
//     while (pos != -1)
//     {
//         prev[pos] = 1;
//         pos = balls_index[pos];
        
//     }

//     for(int i = 0; i < N; i++){
//         if(prev[i]){
//             printf("A[%d] = %d\n", i + 1, massiveballs[i]);
//         }
//     }


    

//     fclose(stdin);
//     fclose(stdout);
    
// }
#include <stdio.h>
#include <stdlib.h>

/*бинарный поиск nlogn*/

int binarySearch(int* arr, int* tails, int size, int key) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[tails[mid]] < key)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void printLIS(int* arr, int* prev, int last) {
    if (last == -1) return;
    printLIS(arr, prev, prev[last]);
    printf("%d\n", arr[last]);
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int* tails = (int*)malloc(N * sizeof(int));
    int* prev = (int*)malloc(N * sizeof(int));
    int length = 0;

    for (int i = 0; i < N; i++) {
        int pos = binarySearch(arr, tails, length, arr[i]);
        tails[pos] = i;
        prev[i] = (pos > 0) ? tails[pos - 1] : -1;
        if (pos == length) length++;
    }

    printf("%d\n", length);  
    printLIS(arr, prev, tails[length - 1]);
    printf("\n");

    free(arr);
    free(tails);
    free(prev);
    return 0;
    fclose(stdin);
    fclose(stdout);
}
