#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(x) cerr << #x << " --> " << x << endl;
#define shine ios_base::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);

vector<ll> visited(500, 0);
ll cnt, ans = 0;
void dfs(ll cur, vector<vector<ll>> &adj){
    visited[cur] = 1;
    cnt++;
    for(auto &next : adj[cur]){
        if(!visited[next]){
            dfs(next, adj);
        }
    }
}

int main() {
    shine
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1, vector<ll>()); // 1-indexed
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll one_nodes = 0;
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i, adj);
            if(cnt > 1){
                ans++;
            }else{
                one_nodes++;
            }
        }
    }
    if(one_nodes > 1){
        ans++;
    }
    cout << ans;
}