#include <stdio.h>
#include <string.h>


typedef struct LongNum_s {
    int len;
    int arr[3000];
} LongNum;



void multiply(LongNum *num, int multiplier) {
    int carry = 0;
    
    for (int i = 0; i < num->len; i++) {
    
        int product = num->arr[i] * multiplier + carry;
        num->arr[i] = product % 10; 
        carry = product / 10;       
    }

    while (carry > 0) {
        num->arr[num->len] = carry % 10;
        carry /= 10;
        num->len++;
    }
}

void printLongNum(LongNum *num) {
    for (int i = num->len - 1; i >= 0; i--) {
        printf("%d", num->arr[i]);
    }
    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N); 

    LongNum num;
    num.len=1;
    memset(num.arr, 0, sizeof(num.arr));
    num.arr[0] = 1; 


    for (int i = 2; i <= N; i++) {
        multiply(&num, i);
    }

    printLongNum(&num);

    return 0;
}
