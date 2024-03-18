#include<bits/stdc++.h>          // --> Bismillahir_ Rahmanir_ Rahim <--
#define ll int 
using namespace std;

#define lc  (n << 1)
#define rc  (n << 1) + 1
#define mid ((s + e) >> 1)

const ll N = 3e4+7;
ll arr[N],lazy[4 * N]; // as we know,there can be atmost (4n-1) Node

vector<ll> t[4*N];

// map<ll,ll>dp;
vector<ll> combine(vector<ll> &a, vector<ll> &b) { // ki lagbe(Answer) ?
    vector<ll> v;
    ll ai = 0, bi = 0;
    while(ai<a.size() && bi<b.size()) {
        if(a[ai]<=b[bi]) {
            v.push_back(a[ai]);
            ++ai;
        }
        else {
            v.push_back(b[bi]);
            ++bi;
        }
    }
    while(ai<a.size()) {
        v.push_back(a[ai]);
        ++ai;
    }
    while(bi<b.size()) {
        v.push_back(b[bi]);
        ++bi;
    }

    return v;
}
void build(ll n, ll s, ll e) {
    // dp[n] = -1;
    if (s == e) {
        t[n].push_back(arr[s]); // here
        return;
    }
    build(lc, s, mid);
    build(rc, mid + 1, e);
    t[n] = combine(t[lc] , t[rc]); // :)
}

ll query(ll n, ll s, ll e, ll l, ll r,ll x) {
    if (e < l || r < s) return 0; // here 
    if (l <= s && e <= r) {
        // if(dp[n]!=-1) return dp[n];
        ll z = upper_bound(t[n].begin(),t[n].end(),x)-t[n].begin();
        return (e-s+1)-z;
    }
    return ( query(lc, s, mid, l, r,x) + query(rc, mid + 1, e, l, r,x) ); // :)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    for(ll i=1 ; i<=n ; i++) cin >> arr[i];

    build(1,1,n);
    
    ll q; cin >> q;
    while(q--) {
        ll L,R,x; cin >> L >> R >> x;
        cout << query(1,1,n,L,R,x) << "\n";
    }

    return 0;
}
