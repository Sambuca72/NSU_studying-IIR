#include <stdio.h>
#include <stdint.h>

int main() {
    
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");   

    int32_t A, B;
    
    fread(&A, sizeof(int32_t), 1, input);
    fread(&B, sizeof(int32_t), 1, input);
    
    int64_t sum = (int64_t)A + (int64_t)B;
    // int32_t result = (int32_t)(sum / 2);  
    sum /=2;
    int32_t res = (int32_t)(sum);

    fwrite(&res,sizeof(int32_t),1,output);

    fclose(input);
    fclose(output);

    return 0;
}
