#include <stdio.h>
#include <stdlib.h>

double c[1000+1][1000+1];

void triangle(){
    for (int n =0; n<=1000; n++){
        c[n][0]=1.0;
        c[n][n]=1.0;
        for (int k = 1; k<n;k++){
            c[n][k]=c[n-1][k-1]+c[n-1][k];
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int q;
    scanf("%d",&q);
    triangle();
    for (int i = 0;i<q;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("%0.15g\n", c[n][k]);
    }

    fclose(stdin);
    fclose(stdout);
}