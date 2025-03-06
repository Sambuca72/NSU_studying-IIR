#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str;
    int flag1,ans;
    flag1=ans=0;
    while(str!='\n'){
        scanf("%c",&str);
        // printf("%d", flag1);
        if (str=='.')
        {
            if (flag1==1){
                ans++;
                flag1=0;
            }
        }
        else if (str=='\n'){
            flag1=0;
        }
        else {
            flag1 =1;
        }
    }
    if (flag1==1){
        ans++;
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}