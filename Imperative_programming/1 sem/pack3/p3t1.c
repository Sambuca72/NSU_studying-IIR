#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    k=0;
    scanf("%d",&n);
    int m[n];
    int ans[n];
    for (int i = 0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for (int j = 0; j<n;j++){
        for (int l = j;l<n;l++){
            if(m[l]<m[j]){
                k++;
            }
        }
        // ans[j]=k;
        // if(j!=(n-1)){
            printf("%d ",k);
        // }
        // else{
        //     printf("%d",k);
        // }
        
        k=0;
    }
    // for (int u = 0; u<n;u++){
    //     printf
    // }
    // printf("\n");
    fclose(stdin);
    fclose(stdout);
}