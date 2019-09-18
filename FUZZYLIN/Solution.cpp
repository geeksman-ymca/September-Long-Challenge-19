#include <bits/stdc++.h>
using namespace std;

int A[100005];
map<int, long long> gcdCnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    map<int, long long> gcdFriends;
    for(int i = 1; i <= N; ++i) {
        map<int, long long> newGcdFriends;
        for(auto x : gcdFriends)
            newGcdFriends[__gcd(A[i], x.first)] += x.second;
        newGcdFriends[A[i]]++;
        for(auto x : newGcdFriends)
            gcdCnt[x.first] += x.second;
        gcdFriends.swap(newGcdFriends);
    }
    //cout << gcdCnt.size() << endl;
    vector<long long> ans(1000006);
    for(auto x : gcdCnt)
        for(long long i = x.first; i <= 1000005; i += x.first)
            ans[i] += x.second;
    cin >> Q;
    for(int i = 1; i <= Q; ++i) {
        int K;
        cin >> K;
        cout << ans[K] << '\n';
    }
    return 0;
}
