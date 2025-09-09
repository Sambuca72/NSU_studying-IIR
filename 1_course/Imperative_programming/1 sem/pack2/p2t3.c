#include <stdio.h>

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    scanf("%d", &n);
    double otr, zero, pol;
    for (int i =0; i<n; i++){
        scanf("%d", &m);
        if (m<0){
            otr+=1;
        }
        else if ( m ==0 ){
            zero += 1;
        }
        else if (m>0){
            pol+=1;
        }
    }
    printf ("%0.15lf %0.15lf %0.15lf", otr/n,zero/n,pol/n );
    fclose(stdin);
    fclose(stdout);
}