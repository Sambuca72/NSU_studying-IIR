#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PUPILS 101

int graph[MAX_PUPILS][MAX_PUPILS];
int used[MAX_PUPILS];
int match[MAX_PUPILS];
int A, B, M;

int dfs(int u) {
    for (int v = 1; v <= B; v++) {
        if (graph[u][v] && !used[v]) {
            used[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int max_matching(int *result) {
    memset(match, -1, sizeof(match));
    int res = 0;
    for (int u = 1; u <= A; u++) {
        memset(used, 0, sizeof(used));
        if (dfs(u)) {
            res++;
            result[u] = 1;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &A, &B, &M);

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }

    int *result = (int *)malloc((A + 1) * sizeof(int));
    memset(result, 0, (A + 1) * sizeof(int));

    int res = max_matching(result);

    printf("%d\n", res);
    for (int v = 1; v <= B; v++) {
        if (match[v] != -1) {
            printf("%d %d\n", match[v], v);
        }
    }

    free(result);
    fclose(stdin);
    fclose(stdout);
}
