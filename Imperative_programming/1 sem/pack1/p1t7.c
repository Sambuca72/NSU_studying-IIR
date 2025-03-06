#include <stdio.h>
#include <math.h>
int main(void){
    int N,M,K,P,L;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&N);
    scanf("%d %d %d %d", &M,&P,&K,&L);
    int q,qes,qp;
    q=(M/(L*P+-L+K-1));//  колво квартир
    qp=q*L;//количество квартир на этвже
    int ans1;
    if(N % qp == 0){
        ans1 = (N / qp); //
    }
    else{
        ans1 = (N / qp) + 1; 
    }
    int mn = ans1 * qp; 
    int dn = mn - N; 
    int ans2 = mn % q ;

    if (L > (dn / q))
        ans2 = L - (dn / q); 
    else
        ans2 = L;
    
    printf("%d %d\n",ans1,ans2);
    // printf("%d %d %d", q,qes,qp);//
    fclose(stdin);
    fclose(stdout);
} 