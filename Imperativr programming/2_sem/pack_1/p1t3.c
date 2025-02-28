;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXL 101




int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char str[MAXL];
    fgets(str,sizeof(str),stdin);
    int inq=0;
    int np=0;
    int parlen=0;
    char par[MAXL];


    for(int i =0;str[i]!='\0';i++){
        char c = str[i];
        if (c=='"'){
            inq=!inq;
            np=1;
        }else if(isspace(c)&&!inq){
            if(np){
                par[parlen]='\0';
                printf("[%s]\n",par);
                parlen=0;
                np=0;
            }
        }
        else{
            par[parlen++]=c;
            np=1;
        }
    }
    if(np){
        par[parlen]='\0';
        printf("[%s]",par);
    }




    fclose(stdin);
    fclose(stdout);
}


// 0(N)