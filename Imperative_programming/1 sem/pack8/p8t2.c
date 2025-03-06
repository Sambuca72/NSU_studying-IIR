#include <stdio.h>

int switche(int value)
{
    return ((value & 0xFF) << 24) |
            (((value >> 8) & 0xFF) << 16) |
            (((value >> 16) & 0xFF) << 8) |
            ((value >> 24) & 0xFF);
}

int main()
{
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");

    int N, sum = 0;
    fread(&N, sizeof(int), 1, input);

    int is_big_endian = (N & 0xFFFF) == 0;
    if (is_big_endian)
    {
        N = switche(N);
    }

    for (int i = 0; i < N; i++)
    {
        int num;
        fread(&num, sizeof(int), 1, input);
        if (is_big_endian)
        {
            num = switche(num);
        }
        sum += num;
    }

    if (is_big_endian)
    {
        sum = switche(sum);
    }
    fwrite(&sum, sizeof(int), 1, output);

    fclose(input);
    fclose(output);

    return 0;
}