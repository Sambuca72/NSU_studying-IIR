#include <stdio.h>
void printTime(int h, int m, int s){
    printf("%0.2d:%0.2d:%0.2d\n",h,m,s);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,h,m,s;
    scanf("%d",&n);
    for (int i =0; i<n;i++){
        scanf("%d %d %d",&h,&m,&s);
        printTime(h,m,s);
    }
    fclose(stdin);
    fclose(stdout);
}