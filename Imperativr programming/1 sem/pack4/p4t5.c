#include <stdio.h>
#include <string.h>
#include<ctype.h>


void cnt(char *st){
    int len,flag,flag1,cuc,clc;
    cuc=clc=0;
    char str[10*10*10*10];
    str[0]='\0';
    flag=0;
    len = strlen(st);
    // printf("%s\n",&str);
    for (int i =0; i<len;i++){
        if (isalpha(st[i])){
            flag=1;
            flag1=1;
            // printf("pen");
            // printf("%s\n",str);
            if(islower(st[i])){
                cuc++;
            }
            if(isupper(st[i])){
                clc++;
            }
            strncat(str,&st[i],1);
            // printf("%s\n",str);
        }
        else{
            if (flag==1){
                
                printf("%d/%d %s\n",clc,cuc+clc,str);
                // printf("penis");
                str[0] = '\0'; 
                cuc=clc=0;
                flag=0;
            }
        }
        
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int uc,lc;
    
    char st[10*10*10*10*10*10];
    // char st1[10*10*10*10*10*10];
    gets(st);
    cnt(st);

    
    fclose(stdin);
    fclose(stdout);
}