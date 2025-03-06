#include <stdio.h>
int main(void){
    int h,m,s,k;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d",&h,&m,&s,&k);
    s=s+k;
    if (s>=60){
        s=s%60;
        m++;
    }
    if (m>=60){
        m=m%60;
        h++;
    }
    if (h>=24){
        h=h%24;
    }
    printf("%d %d %d",h,m,s);
    fclose(stdin);
    fclose(stdout);
}