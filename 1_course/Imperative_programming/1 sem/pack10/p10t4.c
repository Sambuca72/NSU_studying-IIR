#include <stdio.h>
#define MAX 500 

void warshall(int n, int relation[MAX][MAX]) {
    
    for (int i = 0; i < n; i++) {
        relation[i][i] = 1;
    }

    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (relation[i][k] && relation[k][j]) {
                    relation[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    int relation[MAX][MAX];

    
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %1d", &relation[i][j]);  
        }
    }

    
    warshall(n, relation);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", relation[i][j]);
        }
        printf("\n");
    }

    return 0;
    fclose(stdin);
    fclose(stdout);

}
