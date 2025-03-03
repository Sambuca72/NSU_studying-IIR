#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll mod_mult(ll a, ll b, ll mod){
    ll res = 0;
    a %= mod;
    while (b>0){
        if(b&1){
            res = (res+a)%mod;
        }
        a=(a*2)%mod;
        b >>= 1;
    }
    return res;
}

ll extended_gcd(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}


ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll gcd = extended_gcd(a, m, &x, &y);
    if (gcd != 1)
        return -1;

    ll inv = x % m;
    if (inv < 0)
        inv += m;
    return inv;
}

ll CRT (int k, ll *a,ll *m){
    ll M=1 ;
    for(int i = 0;i<k;i++){
        M*=m[i];
    }

    ll x =0;
    for(int i =0;i<k;i++){
        ll Mi=M/m[i];
        ll inv = mod_inverse(Mi,m[i]);
        x+=mod_mult(a[i]*inv,Mi,M);

    }

    return x%M;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    scanf("%d",&k);

    ll *a = (ll *)malloc(k * sizeof(ll));
    ll *m = (ll *)malloc(k * sizeof(ll));

    for(int i = 0; i<k;i++){
        scanf("%lld",&m[i]);
    }
    for(int i = 0;i<k;i++){
        scanf("%lld", &a[i]);
    }
    
    printf("%lld",CRT(k,a,m));
    

    fclose(stdin);
    fclose(stdout);
}
//penis