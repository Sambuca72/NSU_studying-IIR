#include <stdio.h>
#include <stdlib.h>
// #include "func.c"


// f'(x)=~(f(x+h)-f(x-h))/2h

extern double Function(double x);

double derivative(double x, double h) {
    if (x == 1.0||(x+h)>=1.0) {
        return (Function(x) - Function(x - h)) / h;
    } else {
        return (Function(x + h) - Function(x)) / (h);
        }

    
    }

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int M;
    scanf("%d",&M);
    
    double h = 1e-7;
    for(int i = 0; i<M;i++){
        double x;
        scanf("%lf",&x);
        double df = derivative(x,h);
        printf("%.15f\n",df);
    }

    fclose(stdin);
    fclose(stdout);
}