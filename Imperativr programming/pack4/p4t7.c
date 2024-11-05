#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a[126]={0};
    char f[10*10*10*10*10*10];
    f[0] = '\0';
    while(fgets(f,126,stdin)){
        for (int i =0;i<=strlen(f);i++){
        a[(int)f[i]]++;
    }
    }
    int g;
    for (int i =31;i<=126;i++){

        
        if(a[i]>0){
            
            g=a[i];
            // printf("%d\n",g);
            char st[g];
            memset(st,'#',g);
            st[g]='\0';
            // for (int j =0;j<g;j++){
            //     st[i]='#';
            // }
        printf("%c %s\n",(char)i,st);
        st[0]='\0';}
        
    }

    fclose(stdin);
    fclose(stdout);

}