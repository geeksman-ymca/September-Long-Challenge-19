#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b,c;
        cin >> a >> b >> c;
        long long ans = 0;
        for(int i=1;i<=b;i++)
        {
            if(a>i && c>i)
            {
                ans += (a-i-1)*(c-i-1);
                ans %= mod;
            }
            for(int j=2;j<=min((long long)i+1,a);j++)
            {
                ans += max((long long)0, c-((i*i)/(j-1))-1);
                ans %= mod;
            }
            for(int j=2;j<=min((long long)i+1,c);j++)
            {
                ans += max((long long)0, a-((i*i)/(j-1))-1);
                ans %= mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
