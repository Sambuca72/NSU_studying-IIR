#include <stdio.h>
int main(void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    int n,k,ans;
    ans=0;
    scanf("%d", &n);
    k=1;
    int m[n];
    for (int i = 0; i<n;i++){
        scanf("%d",&m[i]);
    }
    for (int j = 0; j<n;j++){
        for (int l = (k-1); l<n;l+=k){
            ans+=m[l];
        }
        printf("%d\n", ans);
        ans=0;
        k++;
        // printf("%d", k);
    }
    fclose(stdin);
    fclose(stdout);
}