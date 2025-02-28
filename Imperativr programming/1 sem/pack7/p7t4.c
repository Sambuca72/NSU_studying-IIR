#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int search (int *arr,int size, int key){
    int f=0,l=size-1;
    int res = -1;
    while (f<=l){
        int m = f+(l-f)/2;
        if (arr[m]==key){
            res = m;
            f = m+1;
        }
        else if(arr[m]<key){
            f=m+1;
        }
        else{
            l = m-1;
        }
    }
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);

    int m[n];
    for (int i = 0; i<n;i++){
        scanf("%d",&m[i]);
    }    
    int q;
    scanf("%d",&q);
    int r = 0;
    for (int i = 0;i<q;i++){
        int x=0,y=0;
        scanf("%d",&x);
        y = x+r;
        r = search(m,n,y);
        printf("%d\n",r);
    }

    fclose(stdin);
    fclose(stdout);
}