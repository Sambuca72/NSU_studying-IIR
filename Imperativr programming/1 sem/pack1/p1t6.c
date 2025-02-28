#include <stdio.h>
int main(void){
    int n,max,min,nmax,nmin,el;
    min=10001;
    max=-10001;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&el);
        if (el<min){
            min=el;
            nmin=i+1;
        }
        if (el>max){
            max=el;
            nmax=i+1;
        }
            
    }
    printf("%d %d %d %d", min, nmin, max, nmax);
}