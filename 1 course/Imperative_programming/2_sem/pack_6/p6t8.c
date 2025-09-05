#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 205
#define MAXW 65005

int N, W;
int w[MAXN], c[MAXN];
int dp[MAXN][MAXW];       
int take[MAXN][MAXW];     

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &W);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &w[i], &c[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            take[i][j] = 0;
            if (j >= w[i]) {
                int val = dp[i - 1][j - w[i]] + c[i];
                if (val > dp[i][j]) {
                    dp[i][j] = val;
                    take[i][j] = 1;
                }
            }
        }
    }

    int max_cost = 0, max_weight = 0;
    for (int j = 0; j <= W; j++) {
        if (dp[N][j] > max_cost) {
            max_cost = dp[N][j];
            max_weight = j;
        }
    }

    int chosen[MAXN];
    int count = 0;
    int cur_weight = max_weight;
    for (int i = N; i > 0; i--) {
        if (take[i][cur_weight]) {
            chosen[count++] = i;
            cur_weight -= w[i];
        }
    }

    printf("%d %d %d\n", count, max_weight, max_cost);
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", chosen[i]);
    }
    printf("\n");

    fclose(stdin);
    fclose(stdout);
    return 0;
}
