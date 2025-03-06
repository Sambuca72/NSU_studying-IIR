#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LongNum_s{
    int len;
    int arr[500];
}LongNum;


void stolbik(LongNum *num1, LongNum *num2){
    int carry=0;
    for (int i =0;i<500;i++){
        if(carry!=0){
        num1->arr[i]+=num2->arr[i]+carry;
        carry=0;
        }
        else{num1->arr[i]+=num2->arr[i];}
      
        if(num1->arr[i]>10){
            carry=num1->arr[i]/10;
            num1->arr[i]=num1->arr[i]%10;
        }else if(num1->arr[i]==10){
            carry=1;
            num1->arr[i]=0;
        }
        //   printf("%d %d \n",num1->arr[i],carry);
    }
}

void printLongNum(LongNum *num) {
    int started = 0; 

    
    for (int i = num->len - 1; i >= 0; i--) {
        if (num->arr[i] != 0) {
            started = 1; 
            
        }

        if (started) {
            printf("%d", num->arr[i]);
        }
    }

    
    if (!started) {
        printf("0");
    }

    printf("\n");
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    
    int help=1; 
    scanf("%d",&n);
    int c;
    if(n%5>1){
        c=(n/5)+1;
    }else{
        c=n/5;
    }
    if (n==1){
        printf("1");
    }
    else if(n==0){
        printf("0");
    }
    else{
    // printf("%d\n",c);
    LongNum num;
    LongNum num1;
    LongNum num2;
    memset(num.arr,0,sizeof(num.arr));
    memset(num1.arr,0,sizeof(num1.arr));
    memset(num2.arr,0,sizeof(num2.arr));
    num.arr[0]=1;
    num1.arr[0]=0;
    num.len=500;
    num1.len=500;

    int size=sizeof(num.arr);
    
    for (int i =1;i<n;i++){
        memcpy(num2.arr,num.arr,size);
        // printf("%d\n",num2.arr[0]);
        stolbik(&num,&num1);
    
        memcpy(num1.arr,num2.arr,size);
    }

    // for (int i =c-1;i>=0;i--){
    //     printf("%d",num.arr[i]);
    // }
    printLongNum(&num);
    }
    fclose(stdin);
    fclose(stdout);
}