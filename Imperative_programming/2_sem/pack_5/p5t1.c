#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

char labyrinth[MAX_N][MAX_N]; 
int visited[MAX_N][MAX_N]; 
int N;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


typedef struct {
    int x, y;
} Point;

Point stack[MAX_N * MAX_N];
int top = -1;

void push(int x, int y) {
    stack[++top] = (Point){x, y};
}

Point pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}


int isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && labyrinth[x][y] == ' ' && !visited[x][y];
}

void dfs(int start_x, int start_y) {
    push(start_x, start_y);
    visited[start_x][start_y] = 1;

    while (!isEmpty()) {
        Point p = pop();
        int x = p.x, y = p.y;

        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                visited[nx][ny] = 1;
                push(nx, ny);
            }
        }
    }
}

int main() {
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            labyrinth[i][j] = getchar();
        }
        getchar(); 
    }

    
    int start_x = 0, start_y = -1;
    for (int j = 0; j < N; j++) {
        if (labyrinth[0][j] == ' ') {
            start_y = j;
            break;
        }
    }

    if (start_y != -1) {
        dfs(start_x, start_y);
    }

    
    int unreachable_areas = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (labyrinth[i][j] == ' ' && !visited[i][j]) {
                dfs(i, j);
                unreachable_areas++;
            }
        }
    }

    
    printf("%d\n", unreachable_areas);
    fclose(stdin);
    fclose(stdout);

    return 0;
}