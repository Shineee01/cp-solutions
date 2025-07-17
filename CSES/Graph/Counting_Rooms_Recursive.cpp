#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<bool>> visited(1005, vector<bool>(1005, 0));
 
bool in_bounds(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}
 
void dfs(int x, int y, vector<vector<char>> &grid){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int next_x = dx[i] + x;
        int next_y = dy[i] + y;
        if(in_bounds(next_x, next_y) && !visited[next_x][next_y] && grid[next_x][next_y] != '#'){
            dfs(next_x, next_y, grid);
        }
    }
}
 
int main() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int room = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] != '#'){
                dfs(i, j, grid);
                room++;
            }
        }
    }
    cout << room;
}
