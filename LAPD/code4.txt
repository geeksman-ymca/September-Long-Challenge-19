#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll min(ll a, ll b) {
    if (a>b) return b;
    else return a;
}

ll max(ll a, ll b) {
    if (a>b) return a;
    else return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    ll mod = pow(10,9)+7;
    
    for(int i=0; i<t; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        int bmax = ceil(sqrt((a-1)*(c-1))-1);
        ll ans = 0;
        for(int i=1; i<=min(b,bmax); i++){
            if (a>i && c>i) {
                ans = (ans+((a-i)*(c-i)-1)%mod)%mod;
            }
            if (c>i){
                for(int j=min(a,i); j>1; j--) {
                    ll min_c = floor(pow(i,2)/(j-1)+1);
                    if (min_c>=c) break;
                    ans = (ans+(c-min_c))%mod;
                }
            }
            if (a>i){
                for(int j=min(c,i); j>1; j--) {
                    ll min_a = floor(pow(i,2)/(j-1)+1);
                    if (min_a>=a) break;
                    ans = (ans+(a-min_a))%mod;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
