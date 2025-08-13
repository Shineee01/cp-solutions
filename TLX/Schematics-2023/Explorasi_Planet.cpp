#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define shine ios_base::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);

ll mxn = 1e5 + 5;
ll mod = 1e9 + 7;
ll cur_ans;
vector<ll> fact(2*mxn, 0);
vector<ll> visited(mxn, 0);
vector<vector<ll>> adj(mxn, vector<ll>());
vector<ll> route(mxn, 0);
ll binexp(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll n, ll p){
    return binexp(n, p - 2, p);
}

void precompute(){
    fact[0] = 1;
    for(ll i = 1; i < 2*mxn; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll nck(ll n, ll k){
    if(k < 0 || k > n) return 0;
    return fact[n] * inv(fact[k], mod) % mod * inv(fact[n - k], mod) % mod;
}

void dfs(ll now){
    visited[now] = 1;
    cur_ans += route[now];
    cur_ans %= mod;
    for(auto &next : adj[now]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main() {
    shine
    precompute();
    ll v, e;
    cin >> v >> e;
    for(ll i = 0; i < v; i++){
        ll p, l;
        cin >> p >> l;
        route[i] = nck(p + l, l);
        route[i] %= mod;
    }
    for(ll i = 0; i < e; i++){
        ll from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<ll> ans;
    for(ll i = 0; i < v; i++){
        cur_ans = 0;
        if(!visited[i]){
            dfs(i);
            ans.push_back(cur_ans);
        }
        
    }
    for(auto &i : ans){
        cout << i << endl;
    }
}

/*
faktorialnya bisa ampe 20000 karena n + k

intinya kita nyari banyak robot tiap pulau terus dfs masing" kepulauan

*/
