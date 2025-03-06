#include <stdio.h>
#include <math.h>
#define EPSILON 1e-12


double fsin(double x) {
    double term = x;        
    double result = term;   
    int n = 1;              

    while (fabs(term) > EPSILON) {
        term *= -x * x / ((2 * n) * (2 * n + 1));  
        result += term;     
        n++;
    }

    return result;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        double value;
        scanf("%lf",&value);
        
        printf("%.15lf\n",fsin(value));
    }

    fclose(stdin);
    fclose(stdout);
}