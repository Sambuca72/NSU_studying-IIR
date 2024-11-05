#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int search(int *array, int n, int target)
{
    int l = 0, r = n - 1;
    if (target <= array[l])
    {
        return l;
    }
    if (target >= array[r])
    {
        return r;
    }
    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (array[m] == target)
        {
            return m;
        }
        else if (array[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (l > 0 && abs(array[l] - target) >= abs(array[l - 1] - target))
    {
        return l - 1;
    }
    else
    {
        return l;
    }
}
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0, q = 0;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int y = 0;
        scanf("%d", &y);
        int index = search(array, n, y);
        int distance = abs(array[index] - y);
        printf("%d %d\n", index, distance);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

