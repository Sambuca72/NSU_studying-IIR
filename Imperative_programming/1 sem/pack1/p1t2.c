#include <stdio.h>
int main(void){
    int x,y,z,c;
    scanf("%d %d %d", &x,&y,&z);
    if (x>0 && y>0 && z>0){
        c=(2*x*y)+(2*x*z)+(2*y*z);
        printf("%d",c);
    }
    else{
        int o,l,k,s;
        o=-10000;
        s=0;
        int m[3];
        if(x<=0){
            m[s++]=-1;}
        if(y<=0){
            m[s++]=-2;}
        if(z<=0){
            m[s++]=-3;}
        k=sizeof(m)/sizeof(m[0]);
        for (int i=0;i<k;i++){
            if (m[i]>o && m[i]<0){
                l=m[i];
                o=m[i];
            }
        }
        printf("%d",l);}

}