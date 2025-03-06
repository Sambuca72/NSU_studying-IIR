#include <stdio.h>
#include <stdlib.h>

int isprime[15000001];

void resheto(int N ){
    for (int i = 0; i <=N;i++){
        isprime[i]=1;
    }
    isprime[0]=0;
    isprime[1]=0;

    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]==1) {
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = 0; 
            }
        }
    }
    
}


int main(void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int q,n;
    scanf("%d %d",&n,&q);
    
    resheto(n);
    for(int i = 0;i<q;i++){
        int p=0;
        scanf("%d",&p);
        
        // printf("%d",fl);
        if(isprime[p]==1){
            printf("%d prime\n",p);
        }
        else{
            printf("%d not\n",p);
        }
    }
    // free(isprime);
    fclose(stdin);
    fclose(stdout);
    return 0;
}