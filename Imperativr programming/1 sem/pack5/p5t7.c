#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxlen 1000

typedef struct LongNum_s{
    int len;
    int *arr;
}LongNum;

LongNum multiply(LongNum a, LongNum b){
    LongNum c={.len=0};
    c.arr = calloc(Maxlen * Maxlen + 1, sizeof(int));

    for(int i = 0;i<a.len;i++){
        for(int j = 0;j<b.len;j++){
            c.arr[i+j]=a.arr[i]*b.arr[j];
            c.arr[i+j+1]+=c.arr[i+j]/10;
            c.arr[i+j]%=10;
        }
    }
    c.len = a.len + b.len;
    while (c.len > 1 && c.arr[c.len - 1] == 0)
    {
        c.len--;
    }

    return c;
}

LongNum conv(char *str){
    LongNum num;
    num.len=strlen(str);
    num.arr=malloc((sizeof(int))*Maxlen+1);
    for(int i =0;i<num.len;i++){
        num.arr[i]=str[num.len-i-1]-'0';
    }
    return num;
}

void print(LongNum num){
    for (int i = num.len - 1; i >= 0; i--)
    {
        printf("%d", num.arr[i]);
    }
    printf("\n");
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char stra[Maxlen+1],strb[Maxlen+1];

    LongNum a,b,c;

    scanf("%s",stra);
    scanf("%s",strb);

    a=conv(stra);
    b=conv(strb);
    c=multiply(a,b);

    print(c);

    free(a.arr);
    free(b.arr);
    free(c.arr);

    fclose(stdin);
    fclose(stdout);

    return 0;
}

