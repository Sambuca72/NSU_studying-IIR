#include <stdio.h>
int main(void){
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int l,r,sum,maxsum,minl,minr;
    maxsum=-100000;
    sum=0;
    minl=minr=1000000;
    int m[n];
    for (int i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for (int i =0; i<n;i++){
        for (int j =i; j<n; j++){
            sum+=m[j];
            if (sum>maxsum){
                maxsum=sum;
                l=i;
                r=j;
            }
        }
        sum=0;
    }
    printf("%d %d %d\n",l,r,maxsum);
    fclose(stdin);
    fclose(stdout);
}