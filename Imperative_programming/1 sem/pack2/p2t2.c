#include <stdio.h>
#include <string.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char n[3];
    scanf("%s",&n);
    if (strcmp("Sun",n)==0){
        printf("7");
    }

    if (strcmp("Mon",n)==0){
        printf("1");
    }

    if (strcmp("Tue",n)==0){
        printf("2");
    }

    if (strcmp("Wed",n)==0){
        printf("3");
    }

    if (strcmp("Thu",n)==0){
        printf("4");
    }

    if (strcmp("Fri",n)==0){
        printf("5");
    }

    if (strcmp("Sat",n)==0){
        printf("6");
    }
    fclose(stdin);
    fclose(stdout);
}