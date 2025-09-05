#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    double data;
    struct node_s* next;
}node;




int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int  n,f;
    scanf("%d %d",&n,&f);

    node* nodes[n];
    
    for (int i =0; i<n;i++){
        nodes[i]=(node*)malloc(sizeof(node));
        nodes[i]->next = NULL;
    }

    for(int i =0;i<n;i++){
        double val;
        int nextindex;
        scanf("%lf %d",&val, &nextindex);

        nodes[i]->data=val;
        if(nextindex != -1){
            nodes[i]->next=nodes[nextindex];
        }
    }

    node* current = nodes[f];
    while(current!=NULL){
        printf("%0.3f\n",current-> data);
        current = current->next;
    }

    for (int i = 0;i<n;i++){
        free(nodes[i]);
    }
     


    fclose(stdin);
    fclose(stdout);
}