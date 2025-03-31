#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define xt = (x[0]+x[1]*((l+r)/2-l)+x[2]*(t-l)**2+x[3](t-l)**3)
// #define yt = (y[0]+y[1]*(t-l)+y[2]*(t-l)**2+y[3](t-l)**3)
// #define zt = (z[0]+z[1]*(t-l)+z[2]*(t-l)**2+z[3](t-l)**3)

double pt(double *p, double u){
    double res = p[0] + p[1]*u +p[2]*pow(u,2.0) + p[3]*pow(u,3.0);
    return res;
}

double dpt(double *p, double u) {
    return p[1] + 2.0 * p[2] * u + 3.0 * p[3] * pow(u, 2.0);
}

double f(double *x, double *y, double *z, double u) {
    double dx = dpt(x, u);
    double dy = dpt(y, u);
    double dz = dpt(z, u);
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double gomersimpson(double *x, double *y, double *z, double l, double r) {
    int n = 100; 
    double h = (r - l) / n;
    double integral = f(x, y, z, 0.0) + f(x, y, z, r - l); 

    for (int i = 1; i < n; i++) {
        double u = i * h;
        integral += (i % 2 == 0) ? 2.0 * f(x, y, z, u) : 4.0 * f(x, y, z, u);
    }

    integral *= h / 3.0;
    return integral;
}

double span_schitat(){}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    scanf("%d",&N);
    double result = 0.0;


    for(int i = 0; i<N;i++){
        double l,r;
        scanf("%lf %lf", &l, &r);

        double *x = (double *)malloc(4* sizeof(double));
        double *y = (double *)malloc(4* sizeof(double));
        double *z = (double *)malloc(4* sizeof(double));
        
        scanf("%lf %lf %lf %lf", &x[0], &x[1], &x[2], &x[3]);
        scanf("%lf %lf %lf %lf", &y[0], &y[1], &y[2], &y[3]);
        scanf("%lf %lf %lf %lf", &z[0], &z[1], &z[2], &z[3]);

        result += gomersimpson(x, y, z, l, r);

        free(x);
        free(y);
        free(z);

    }

    printf("%.20lf", result);

    fclose(stdin);
    fclose(stdout);
}