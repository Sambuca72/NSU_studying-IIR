#include <stdio.h>
#include <string.h>
#include <ctype.h>
int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitCnt){
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    *oDigitCnt = 0;
    for (int i=0;i<strlen(iStr);i++){
         if (isprint(iStr[i])) {
            if (isdigit(iStr[i])) {
                (*oDigitCnt)++;
            } else if (islower(iStr[i])) {
                (*oLowerCnt)++;
            } else if (isupper(iStr[i])) {
                (*oUpperCnt)++;
            }
        }
    }
        
    
    return *iStr, *oLowerCnt, *oUpperCnt, *oDigitCnt;

}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int lc,dc,uc,a;
    lc=dc=uc=0;
    a=1;
    char c;
    char st[100];
    while (fgets(st,100,stdin)){
        if (a>1){
            printf("\n");
        }
         st[strcspn(st, "\n")] = 0;
        // gets(st);
        // lc=dc=uc=0;
        calcLetters(st,&lc,&uc,&dc);//передаём указатели на конкретную переменную
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper)," 
        " %d are digits.",a,strlen(st),lc+uc,lc,uc,dc);
        a++;
    }
    fclose (stdin);
    fclose (stdout);

}
