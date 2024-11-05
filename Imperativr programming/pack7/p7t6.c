#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int status;
    int next;
}Node;

void createlist(Node* mass,int n,int k){
    mass[n].next=-1;
    mass[n].status=1;
    for (int i =0;i<n-1;i++){
        mass[i].status=1;
        mass[i].next=i+1;
    }
}

void schitalochka(Node* mass,int n, int k){
    int i=1
    while (n--){
        if(i%3==0){
            printf("%d",i);
            mass[i-1].status=0;
            mass[i-1].next=
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    scanf("%d %d",&n,&k);
    Node mass[n];
    createlist(mass,n,k);

    fclose(stdin);
    fclose(stdout);
}