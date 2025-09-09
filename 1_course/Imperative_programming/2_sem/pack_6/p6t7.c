#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10
#define MAX_K 10
#define MAX_M 100


//все алгоритмы для потока найти

int N, K, M, L;
char effect[MAX_N * MAX_K][MAX_M + 1]; 
int solution[MAX_N]; 
int current_voltage[MAX_M];
int found_solution; 


void backtrack(int panel, int *possible_switches) {
    if (found_solution) return; 

    if (panel == N) {

        for (int t = 0; t < M; t++) {
            if (current_voltage[t] != L) return;
        }
        found_solution = 1;
        return;
    }

    for (int t = 0; t < M; t++) {
        if (current_voltage[t] > L) return; 
        if (current_voltage[t] + (N - panel) < L) return;
    }

    for (int j = 0; j < K; j++) {
        int switch_idx = possible_switches[panel * K + j];
       
        for (int t = 0; t < M; t++) {
            if (effect[panel * K + switch_idx][t] == 'X') {
                current_voltage[t]++;
            }
        }
        solution[panel] = switch_idx + 1; 
        backtrack(panel + 1, possible_switches); 

        for (int t = 0; t < M; t++) {
            if (effect[panel * K + switch_idx][t] == 'X') {
                current_voltage[t]--;
            }
        }
        if (found_solution) return;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    scanf("%d %d %d %d", &N, &K, &M, &L);


    for (int i = 0; i < N * K; i++) {
        scanf("%s", effect[i]);
    }
    

    for (int t = 0; t < M; t++) {
        int count = 0;
        for (int i = 0; i < N * K; i++) {
            if (effect[i][t] == 'X') count++;
        }
        if (count < L) {
            printf("NO\n");
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
    }

    int possible_switches[MAX_N * MAX_K];
    for (int i = 0; i < N; i++) {

        int switch_effect[MAX_K];
        for (int j = 0; j < K; j++) {
            switch_effect[j] = 0;
            for (int t = 0; t < M; t++) {
                if (effect[i * K + j][t] == 'X') switch_effect[j]++;
            }
            possible_switches[i * K + j] = j;
        }
       
        for (int j = 0; j < K - 1; j++) {
            for (int k = j + 1; k < K; k++) {
                if (switch_effect[possible_switches[i * K + j]] < switch_effect[possible_switches[i * K + k]]) {
                    int temp = possible_switches[i * K + j];
                    possible_switches[i * K + j] = possible_switches[i * K + k];
                    possible_switches[i * K + k] = temp;
                }
            }
        }
    }


    for (int t = 0; t < M; t++) {
        current_voltage[t] = 0;
    }
    found_solution = 0;

    
    backtrack(0, possible_switches);

    
    if (found_solution) {
        printf( "YES\n");
        for (int i = 0; i < N; i++) {
            printf("%d\n", solution[i]);
        }
    } else {
        printf("NO\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}