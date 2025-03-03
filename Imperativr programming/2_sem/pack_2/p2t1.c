#include <stdio.h>

int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    scanf("%d",&k);

    int M[k];
    int A[k];
    for(int i = 0; i<k;i++){
        scanf("%d",&M[i]);
    }

    for(int i = 0;i<k;i++){
        scanf("%d", &A[i]);
    }

    int f=0;

    for(int i = 0;i<k;i++){
        for (int j = 0;j < k; j++){
            int x,y;
            if (extended_gcd(M[i],M[j],&x,&y)==1){
                f++;
            }
        }
    }
    if (f==k){
        int md=1;
        for(int i = 0;i<k;i++){
            md*=M[i];
        }
    }

    

    fclose(stdin);
    fclose(stdout);
}