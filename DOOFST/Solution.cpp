#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define rank size
const ll mod = 1000000007, mx = 200005;

int rank[mx],root[mx];  
vector<int> v[mx];
int h[mx];
int mp[mx];
bool un[mx];

// DSU implementation
int findroot(int x)
{
    while(root[x]!=x)
    {
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}

int check(int x,int y)
{
    x = findroot(x);
    y = findroot(y);
    if(x == y)
    {
        return 1;
    }
    return 0;
}

void unite(int x,int y)
{
    x = findroot(x);
    y = findroot(y);
    if(x == y)
        return ;
    if(rank[x]<rank[y])
    {
        root[x] = y;
        rank[y] += rank[x];
    }
    else
    {
        root[y] = x;
        rank[x] += rank[y];
    }
}

// end DSU

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    for(int i = 0; i < n ; i++)
    {
        rank[i] = 1;
        root[i] = i;
    }
    
    for(int i = 0 ; i < m ; i++ )
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0;i < n ; i++)
    {
        for(int j = 0; j < v[i].size();j++)
        {
            if(check(i,v[i][j]))
            {
                cout<<-1;
                return 0;
            }
            else h[v[i][j]] = 1;
        }
        
        int x = findroot(i);
        if(un[x] == 1)
        {
            goto last;
        }
        un[i] = 1;
        for(int j=0;j<n;j++)
        {
            if(h[j] == 0 && i!=j)
            {
                unite(i,j);
            }
        }
        last:;
        for(int j = 0; j < v[i].size();j++)
        {
            h[v[i][j]] = 0;
        }
    }
    int cnt = 0;

    for(int i = 0; i< n ;i++) // count distict sets
    {
        if(root[i] == i) 
        {
            mp[i] = cnt++;
        }
    }
    int y = cnt;
    y--;
    int x = 0;
    while(y)
    {
        x++;
        y>>=1;
    }
    if(x*n > 1000000)
    {
        cout<<-1;
        return 0;
    }
    cout<<x<<endl;
    for(int i = 0 ;i < x;i++)
    {
        for(int j = 0 ;j  < n; j++)
        {
            int y = mp[findroot(j)];
            if((y>>i)&1)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
