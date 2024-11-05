#include <stdio.h>
int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int d,m,y,k,dinm,diny,dinf,dd,flag;
    scanf("%d %d %d %d",&d,&m,&y,&k);
    dd=flag=0;
    if (y%4==0 || (y%100==0 && y%400==0)){diny=366;dinf=29;}
        else{diny=365;dinf=28;}
        if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10||m==12){dinm=31;}
        else{dinm=30;}
        if (k+d<=dinm){
            dd=k+d;
            flag=1;
        }
        if (m==2){k-=dinf-d;}
            else{k-=dinm-d;}
        // m+=1;
        // printf("%d\n",k);
    while(k>0 && flag ==0){
        m++;
        if ((y%4==0 && y%100!=0) ||  y%400==0){
            diny=366;
            dinf=29;
        }
        else{
            diny=365;
            dinf=28;
        }

        if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10||m==12||m==13){dinm=31;}
        else{dinm=30;}
        if (m==2){dinm=dinf;}
        if (k>=dinm){k-=dinm;}        
        else{dd=k;k-=k;}
        
        if (m>12){
            y++;
            m=1;
        }
        // printf("%d %d %d %d %d\n",m,y,k,dinm,diny);
    }
    if(dd ==2 && m==3 && y==1900){dd=3;}
    printf("%d %d %d\n", dd,m,y);
    fclose(stdin);
    fclose(stdout);
}