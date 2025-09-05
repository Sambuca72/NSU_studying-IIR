#include <stdio.h>
#include <stdlib.h>

#define ansmod 1000000007



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % ansmod;
        }
    }
    printf("%lld\n", dp[n]);
    free(dp);
    return 0;

    fclose(stdin);
    fclose(stdout);

}