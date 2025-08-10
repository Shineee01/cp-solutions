#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n' 
#define debug(x) cerr << #x << " --> " << x << endl;
#define shine ios_base::sync_with_stdio(false), cin.tie(nullptr);
const ll mod = 1e9 + 7;
const ll inf = 1e18;
ll r, c, y;
char dir[4] = {'U', 'S', 'B', 'T'};
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};
vector<vector<ll>> visited;
vector<vector<ll>> memo;
void dfs(vector<vector<char>> &grid, ll now_x, ll now_y){
    ll cnt = 0;
    stack<pair<ll,ll>> st;
    st.push({now_x, now_y});
    visited[now_x][now_y] = 1;
    while(!st.empty()){
        auto [cur_x, cur_y] = st.top();
        st.pop();
        cnt++;
        memo[cur_x][cur_y] = cnt;
        for(ll i = 0; i < 4; i++){
            if(grid[cur_x][cur_y] == dir[i]){
                ll next_x = cur_x + dx[i];
                ll next_y = cur_y + dy[i];
                if(next_x < 1 || next_y < 1 || next_x > r || next_y > c){
                    cout << 1 << " " << cnt << endl;
                    return;
                }
                if(visited[next_x][next_y]){
                    cout << 1 << " " << memo[next_x][next_y] - 1 << " " << 0 << " " << cnt - memo[next_x][next_y] + 1 << endl;
                    return;
                }
                visited[next_x][next_y] = 1;
                st.push({next_x, next_y});
            }
        }
    }
}


int main(){
    shine
    while(cin >> r >> c >> y && r != 0 && c != 0 && y != 0){
        visited.assign(r+1, vector<ll>(c+1, 0));
        memo.assign(r+1, vector<ll>(c+1, 0));
        vector<vector<char>> grid(r + 1, vector<char> (c + 1));
        for(ll i = 1; i <= r; i++){
            for(ll j = 1; j <= c; j++){
                cin >> grid[i][j];
            }
        }
        dfs(grid, 1, y);
    }
}
