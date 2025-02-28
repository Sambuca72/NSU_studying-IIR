#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int prev;
    int status;
    int next;
}Node;

void createlist(Node* mass,int n,int k){
    mass[0].prev=-1;
    mass[0].status=1;
    mass[0].next = 1;

    mass[n-1].next=-1;
    mass[n-1].status=1;
    
    for (int i =1;i<n-1;i++){
        mass[i].prev = i-1;
        mass[i].status=1;
        mass[i].next=i+1;
        // printf("%d %d %d\n",mass[i].prev,mass[i].status, mass[i].next);
    }
}


void schitalochka(Node* mass, int n, int k) {
    int remaining = n;
    int current = 0;  
    int step_count = 0;

    while (remaining > 0) {
        if (mass[current].status==1){
        step_count++;
        }

        if (step_count == k) {
            printf("%d\n", current + 1);  
            
            int prev = mass[current].prev;
            int next = mass[current].next;

            if (prev != -1) {  
                mass[prev].next = next;
            }
            if (next != -1) {  
                mass[next].prev = prev;
            }

            mass[current].status = 0;  // Отметка текущего элемента как удалённого
            remaining--;  
            step_count = 0;  
            
            current = next != -1 ? next : 0;  
        } else {
            current = mass[current].next;  
            if (current == -1) {  
                current = 0;
            }
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
    schitalochka(mass,n,k);

    fclose(stdin);
    fclose(stdout);
}