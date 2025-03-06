#include <stdio.h>
#include <string.h>

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //Инициализация массива и переменных
    int n,id,leng,cnt;
    cnt=1;
    scanf("%d",&n);
    int m[10*10*10*10];
    memset(m,0,sizeof(m));
    int ta[10*10*10*10][2];
    memset(ta,0,sizeof(ta));
    for (int i =0;i<n;i++){
        scanf("%d %d",&id,&leng);
        
        ta[id][0]++;
        m[id]++;
        
        ta[id][1]+=leng;
    }

    int k=0;
    for (int i =0; i<10*10*10*10;i++){
        if (m[i]!=0){
            k++;
        }
    }
    int idw,cntw,dw;
    idw=cntw=dw=0;
    for (int i =0; i<10*10*10*10;i++){
        if (ta[i][0]!=0){
            if (i>idw){idw=i;}
            if(ta[i][0]>cntw){cntw=ta[i][0];}
            if(ta[i][1]>dw){dw=ta[i][1];}
        }
    }
    idw = snprintf(NULL, 0, "%d", idw) + 2; // не позволяет переполнить буфер и помогает правильно форматировать строку
    cntw = snprintf(NULL, 0, "%d", cntw) + 2; 
    dw = snprintf(NULL, 0, "%d", dw) + 2;

     printf("+");
    for (int i = 0; i <= idw - 1; i++) printf("-");
    printf("+");
    for (int i = 0; i <= cntw - 1; i++) printf("-");
    printf("+");
    for (int i = 0; i <= dw - 1; i++) printf("-");
    printf("+\n");

    for (int i =0; i<10*10*10*10;i++) {
        if (ta[i][0]!=0){
        printf("| %*d | %*d | %*d |\n", idw - 2, i, cntw - 2, ta[i][0], dw - 2, ta[i][1]);
        //%*d обозначает формат вывода где * обозначает параметр ширины вывода числа например i, если i<idw по ширине то оно дополняется пробелами
        printf("+");
        for (int j = 0; j <= idw - 1; j++) printf("-");
        printf("+");
        for (int j = 0; j <= cntw - 1; j++) printf("-");
        printf("+");
        for (int j = 0; j <= dw - 1; j++) printf("-");
        printf("+\n");
        }
    }

    fclose(stdout);
    fclose(stdin);
}