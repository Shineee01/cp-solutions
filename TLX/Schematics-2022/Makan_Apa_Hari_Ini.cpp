#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(x) cerr << #x << " --> " << x << endl;
#define shine ios_base::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);

vector<ll> visited(10000, 0);
vector<vector<pair<ll,ll>>> adj;
ll max_price, node, edge, cur_price = 1e9;

int main() {
    shine
    cin >> node;
    adj.resize(node + 1);
    vector<pair<string,ll>> price(node + 1);
    for(ll i = 1; i <= node; i++){
        string s;
        ll p;
        cin >> s >> p;
        price[i] = {s,p};
    }
    cin >> edge;
    for(ll i = 0; i < edge; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> max_price;
    vector<ll> dist(node + 1, 1e18);
    queue<ll> q;
    q.push(0);
    dist[0] = 0;
    string ans = "";
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]){
            if(dist[cur] + weight <= max_price && dist[cur] + weight < dist[next]){
                dist[next] = dist[cur] + weight;
                q.push(next);
                if(cur_price > price[next].second){
                    cur_price = price[next].second;
                    ans = price[next].first;
                }
            }
        }
    }
    cout << "hari ini makan di " << ans;;
}