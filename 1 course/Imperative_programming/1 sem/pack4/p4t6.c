#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int readTime(char *iStr, int *flag, int *oHours, int *oMinute, int *oSeconds ){
    int fl=0;
    int a=1;
    char cnt[15];
    cnt[0]='\0';

    for(int i =0;i<=strlen(iStr);i++){
        if (iStr[i]=='|'){
            *flag=0;
            *oHours=(-1);
            *oMinute=(-1);
            *oSeconds=(-1);
            break;
        }
        else{*flag=1;}
        
        if (isdigit(iStr[i])){
            fl=1;
            // printf("%d\n",a);
            // printf("stri %c\n",iStr[i]);
            char temp[2] = {iStr[i], '\0'};
            // printf("temp %s\n",temp);
            strncat(cnt, temp, 1);
            // printf("cnt %s\n",cnt);
            
        }
        else
        {
            if (fl==1){
                // printf("pep");
                if(a==1){
                    *oHours=atoi(cnt);
                    // printf("Hours %d\n",*oHours);
                    cnt[0] = '\0';
                    a++;
                    fl=0;
                }
                else if(a==2){
                    // printf("daf%d\n",atoi(cnt));
                    *oMinute=atoi(cnt);
                    // printf("%d\n",*oMinute);
                    a++;
                    cnt[0] = '\0';
                    fl=0;
                }
                else if(a==3){
                    *oSeconds=atoi(cnt);
                    a++;
                    cnt[0] = '\0';
                    fl=0;
                }
            }
        }

    }
    if (*oHours>=24||*oMinute>=60||*oSeconds>=60){
            *flag=0;
            *oHours=(-1);
            *oMinute=(-1);
            *oSeconds=(-1);
    }
    else if (*flag!=0)
    {*flag=1;}
    
    
    return *iStr,*flag, *oHours, *oMinute, *oSeconds;
}

int main(){
    freopen ("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int h,m,c,flag;
    flag=0;
    h=m=c=0;
    char st[15];
    gets(st);
    readTime(st,&flag,&h,&m,&c);
    
    printf("%d %d %d %d\n",flag,h,m,c);
    printf("%d %d %d\n",flag,h,m);
    printf("%d %d\n",flag,h);

    
    fclose(stdin);
    fclose(stdout);
}