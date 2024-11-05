#include <stdio.h>
#include<string.h>
#define size 10*10*10*10*10
char* concat(char* pref, const char* suff) {
    char* ptr = pref;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*suff != '\0') {
        *ptr = *suff;
        ptr++;
        suff++;
    }
    *ptr = '\0';
    return ptr;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen ("output.txt","w", stdout);
    int n;
    char st1[size];
    char st2 [size];

    scanf("%d",&n);
    scanf("%s",&st1);
    for (int i =1; i<n;i++){
        scanf("%s",&st2);
        concat(st1,st2);
        
    }
    printf("%s",st1);
    fclose(stdin);
    fclose(stdout);
}