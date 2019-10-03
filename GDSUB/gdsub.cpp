#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main()
{
	int n,k,x,freq[9000];

		vector<ll> hash;
		
		memset(freq,0,sizeof(freq));
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			freq[x]++;
		}
		for(int i=0;i<9000;i++)
		{
			if(freq[i]>0)
			hash.push_back(freq[i]);
		}
		ll s=hash.size();
		vector<ll> pref(s);
		pref[0]=hash[0];
		for(int i=1;i<s;i++)
		pref[i]=(hash[i]%mod+pref[i-1]%mod)%mod;
		
		ll curr_sum=pref[s-1];
		ll ans=curr_sum;
		for(int i=1;i<k;i++)
		{	
			ll new_sum=0;
			pref[0]=(((curr_sum-pref[0]+mod)%mod)*(hash[0]%mod))%mod;
			new_sum=pref[0];
			for(int j=1;j<s;j++)
			{
				pref[j]=(((curr_sum-pref[j]+mod)%mod)*(hash[j]%mod))%mod;
				new_sum=(pref[j]%mod+new_sum%mod)%mod;
				pref[j]=(pref[j-1]%mod+pref[j]%mod)%mod;
			}
			curr_sum=new_sum;
			ans=(curr_sum%mod+ans%mod)%mod;
		}
		cout<<(ans+1)%mod<<"\n";
	
}
