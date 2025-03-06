#include <stdio.h>
int main(void){
int n,res;
    scanf("%d", &n);
    int m[n];
    for (int i=0; i<n; i++){
        scanf("%d",&m[i]);
        if (m[i]%2==0){
            res=res+m[i];
        }}
    printf("%d",res);
}