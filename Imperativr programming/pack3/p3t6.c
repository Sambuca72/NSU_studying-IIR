#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,flag,an;
    flag=an=0;
    scanf("%d",&n);
    int a[n];
    int ans[100000+1]={0};

    for (int i =0; i<n;i++){
        scanf("%d", &a[i]);    
    }
    scanf("%d",&m);
    int b[m];

    for (int j =0; j<m;j++){
        scanf("%d", &b[j]);    
    }

    for (int i =0; i<n;i++){
        for (int j =0;j<m;j++){
            
            if(a[i]==b[j]){
                flag=1;
            }
            // printf("%d %d %d\n", a[i], b[j], flag);
        }
        if(flag==0){
                ans[a[i]]++;
                if (ans[a[i]]<=1){an++;}
                // printf("pip");
            }
        flag=0;
    }
    printf("%d\n",an);
    for (int k = 0; k<100001;k++){
        if(ans[k]!=0){
            printf("%d ",k);
        }
    }
    fclose(stdin);
    fclose(stdout);
}