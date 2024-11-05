#include <stdio.h>
int main(void)
{
    long long n,res;
    n=res=0;
    scanf("%lld", &n);
    for (int i = 1; i*i*i <= n; i++)
    {
        for (int j = i; i*j*j <= n; j++)
        {
            res += (n/(i*j)-j+1);
        }
    }
    printf("%lld", res);
    return 0;
}