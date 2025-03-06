#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int flag,n;
    flag=0;
    scanf("%d ",&n);
    for (int num = 2;num<=n;num++){
        for(int i =2;i*i<=n;i++){
            if(num%i==0 && num!=i){
                flag = 1;
                
            }
            
        }
   
        if (flag ==0){
            printf("%d\n", num);
        }
        flag = 0;
        }
    fclose(stdin);
    fclose(stdout);
}