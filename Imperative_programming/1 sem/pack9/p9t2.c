#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int partition(int *a, int n, int pivot)
{
    int cl = 0, cp = 0, cg = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            cl++;
        }
        else if (a[i] == pivot)
        {
            cp++;
        }
        else
        {
            cg++;
        }
    }

    
    int u = cp / 2;
    int v = cp - u;
    int k = cl + u;

    
    int *less = malloc(cl * sizeof(int));
    int *equal = malloc(cp * sizeof(int));
    int *greater = malloc(cg * sizeof(int));


    for (int idxl = 0, idxp = 0, idxg = 0, i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            less[idxl++] = a[i];
        }
        else if (a[i] == pivot)
        {
            equal[idxp++] = a[i];
        }
        else
        {
            greater[idxg++] = a[i];
        }
    }

    int idx = 0;

    
    for (int i = 0; i < cl; i++)
    {
        a[idx++] = less[i];
    }

    for (int i = 0; i < u + v; i++)
    {
        a[idx++] = equal[i];
    }

    for (int i = 0; i < cg; i++)
    {
        a[idx++] = greater[i];
    }

    free(less);
    free(equal);
    free(greater);

    return k;
}

int main()
{
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");

    int32_t N, P;

    fread(&N, sizeof(int32_t), 1, input);
    fread(&P, sizeof(int32_t), 1, input);

    int32_t *a = malloc(N * sizeof(int32_t));

    fread(a, sizeof(int32_t), N, input);

    int k = partition((int *)a, N, P);

    fwrite(&k, sizeof(int32_t), 1, output);
    fwrite(a, sizeof(int32_t), N, output);

    fclose(input);
    fclose(output);
    free(a);

    return 0;
}