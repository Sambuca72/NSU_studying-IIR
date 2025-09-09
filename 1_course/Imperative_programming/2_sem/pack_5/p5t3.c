#include <stdio.h>
#include <stdlib.h>

#define MAXN 101
#define MAXM 101

typedef struct Point{
    int x,y;
}Point;

int BFS(char labyrinth[MAXM][MAXN] ,int M, int N, Point start, Point finish) {
    int* queue = (int*)malloc(sizeof(int) * M*N*3);
    int* visited = (int*)calloc(M*N, sizeof(int));
    int front = 0, back=0;

    queue[back++]=start.x;
    queue[back++]=start.y;
    queue[back++]=0;

    visited[start.x*N+start.y]=1;

    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};

    while (front < back) {
        int x = queue[front++];
        int y = queue[front++];
        int dist = queue[front++];

        if(x==finish.x&&y==finish.y){
            free(queue);
            free(visited);
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx * N + ny] && labyrinth[nx][ny] != 'X') {
                visited[nx * N + ny] = 1;
                queue[back++] = nx;
                queue[back++] = ny;
                queue[back++] = dist + 1;
            }
        }
        
    }

    free(queue);
    free(visited);
    return -1;
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, N;
    scanf("%d %d", &M, &N);

    getchar();

    char labyrinth[MAXM][MAXN];
    Point start, finish;

    for (int i = 0; i< M;i++){
        for(int j = 0; j<N;j++){
            labyrinth[i][j]=getchar();
            if(labyrinth[i][j]=='S'){
                start.x = i;
                start.y = j;
            }
            if(labyrinth[i][j]=='F'){
                finish.x = i;
                finish.y=j;
            }
        }
        getchar();
    }

    int res = BFS(labyrinth,M,N,start,finish);
    printf("%d",res);

    fclose(stdin);
    fclose(stdout);
    return 0;
}