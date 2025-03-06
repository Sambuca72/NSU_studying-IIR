#include <stdio.h>
#include <string.h>
void reverse(char *start, int len){
    for (int i=0; i<len/2;i++){
        char a = start[i];
        start[i]=start[len -1 -i];
        start[len-1-i]=a;
    }
}
int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    char st[100];
    for (int i=0;i<n; i++){
        scanf("%s",&st);
        reverse(st,strlen(st));
        printf("%s\n",st);
    }
    fclose (stdin);
    fclose (stdout);
}