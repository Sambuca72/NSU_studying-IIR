#include <stdio.h>
#include <stdlib.h>
#include "p2t6.h"
// #include <>

// f'(x)=~(f(x+h)-f(x-h))/2h

// double Function(double x) {
//     if (x < 0.0 || x > 1.0)
//     exit (666); //out of range
//     return x * x - x;
//     }

double derivative(double x, double h) {
    if (x == 0.0) {
        return (Function(x + h) - Function(x)) / h;
    } else if (x == 1.0) {

        return (Function(x) - Function(x - h)) / h;
    } else {
        return (Function(x + h) - Function(x - h)) / (2.0 * h);
        }
    }

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int M;
    scanf("%d",&M);
    // printf("%d",M);
    double h = 1e-7;
    // printf("penis\n");
    for(int i = 0; i<M;i++){
        // printf("penis%d0\n",i);
        double x;
        scanf("%lf",&x);
        printf("%lf\n",x);
        double df = derivative(x,h);
        // printf("penis%d2\n",i
        printf("%.15f\n",df);
    }

    fclose(stdin);
    fclose(stdout);
}