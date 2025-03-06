#include <stdio.h>
int main (void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int m[n];
    int a[10000+1]={0};
    for (int i=0;i<n;i++){
        scanf("%d",&m[i]);
        a[m[i]]++;
    }
    for (int k = 0; k<10001;k++){
        if(a[k]!=0){
            for (int i =0; i<a[k];i++){
                printf("%d ",k);}
            // printf("%d %d\n",a[k],k);
            }
        }
    fclose(stdin);
    fclose(stdout);
    }
