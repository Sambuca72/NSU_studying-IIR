#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,count,k;
    k=0;
    scanf("%d", &n);
    int m[n];
    int a[10000+1]={0};
    for (int i=0;i<n;i++){
        scanf("%d",&m[i]);
        a[m[i]]++;
    }
    
    
    for (int j =0; j<10001;j++){
        if(a[j]!=0){
        printf("%d: %d\n",j,a[j]);}
    }
    fclose(stdin);
    fclose(stdout);
}