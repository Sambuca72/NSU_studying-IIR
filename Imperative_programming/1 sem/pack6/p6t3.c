#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxreq 100000

char* strings[maxreq];



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);
    
    int cnt=0;
    for (int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
  

        if (t==0){
            int l;
            scanf("%d ",&l);

            strings[cnt]=(char*)malloc((l+1)*sizeof(char));
            scanf("%s",strings[cnt]);
            cnt++;
        }
        else if(t==1){
            int k;
            scanf("%d",&k);

            free(strings[k]);

        }
        else if(t==2){
            int k;
            scanf("%d",&k);
            if (strings[k] != NULL) {  
                printf("%s\n", strings[k]);}
        }
        else if(t==3){
             int k;
            char symbol;
            scanf("%d %c", &k, &symbol);  
            
            int count = 0;
            for (int j = 0; strings[k][j] != '\0'; j++) {
                if (strings[k][j] == symbol) {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }

    fclose(stdin);
    fclose(stdout);
}