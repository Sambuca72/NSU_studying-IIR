#include <stdio.h>
#include <stdint.h>
#include <string.h>

void process_test(int P, int Q, uint64_t M) {
    double X = (double) P / Q;
    
    uint64_t X_bits;
    memcpy(&X_bits, &X, sizeof(double));

    
    X_bits ^= M;

    
    double result;
    memcpy(&result, &X_bits, sizeof(double));

    
    printf("%.15g\n", result);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int P, Q;
        uint64_t M;
        scanf("%d/%d xor %llx", &P, &Q, &M);  
        process_test(P, Q, M);
    }

    fclose(stdin);
    fclose(stdout);
}