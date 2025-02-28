#include <stdio.h> 
#include <math.h> 
int main(void) 
{ 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int l,r,k,res; 
    l=k=r=res=0;
    scanf("%d %d %d", &l, &r, &k); 
    for (int st = l; st <= r; st++) 
    { 
        for (int dis = 0; dis * (k - 1) <= r; dis++) 
        { 
            if ((st + (k - 1) * dis) <= r && st + k * dis > r) 
            {res++;
            }
            // printf("%d\n", dis); 
        } 
    } 
    printf("%d", res); 
    fclose(stdin); 
    fclose(stdout); 
    return 0; 
}
