#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a<b) ? (a):(b))
int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a1,a2,b1,b2,c1,c2;
    scanf("%d %d %d %d %d %d",&a1,&a2,&b1,&b2,&c1,&c2);
    
    if (a1*a2>=(b1*b2+c1*c2)){

        if(((MAX(b1, c1) <= a1) && ((b2 + c2) <= a2)) || ((MAX(b1, c2) <= a1) && ((b2 + c1) <= a2)) || ((MAX(b2, c1) <= a1) && ((b1 + c2) <= a2)) || ((MAX(b2, c2) <= a1) && ((b1 + c1) <= a2)) || ((MAX(b1, c1) <= a2) && ((b2 + c2) <= a1)) || ((MAX(b1, c2) <= a2) && ((b2 + c1) <= a1)) || ((MAX(b2, c1) <= a2) && ((b1 + c2) <= a1)) || ((MAX(b2, c2) <= a2) && ((b1 + c1) <= a1))){
            printf("YES");   
        }
        else{
            printf("NO");
        }
        // if((a1-b1!=0 && a1-b2!=0 && a2-b1!=0 && a2-b2!=0)){
        //     printf("1");
        //     if (((a1-b1)>=c1&&(a2-b2)>=c2)||((a1-b2)>=c1&&(a2-b1)>=c2)){
        //         printf("YES");
        //     }
        //     else{
        //         printf("NO");
        //     }
        // }
        // else if((a1-c1!=0 && a1-c2!=0 && a2-c1!=0 && a2-c2!=0)){
        //         printf("2");
        //         if (((a1-c1)>=b1&&(a2-c2)>=b2)||((a1-c2)>=b1&&(a2-c1)>=b2)){
        //             printf("YES");
        //         }
        //         else{
        //             printf("NO");
        //         }
                
        // }
        // else{
        //     printf("3");
        //     if (((a1-b1)>=c1||(a2-b2)>=c1)||((a1-b2)>=c2||(a2-b1)>=c2)||((a1-c1)>=b1||(a2-c2)>=b1)||((a1-c2)>=b2||(a2-c1)>=b2)){
        //         printf("YES");
        //     }
        //     else{
        //         printf("NO");
        //     }
        // }
    }
    else{
        printf("NO");
    }
    // fclose(stdin);
    // fclose(stdout);
}