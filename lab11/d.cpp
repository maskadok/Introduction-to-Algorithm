#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
const int INF = 1e9;
int main(){
    int n;
    cin >> n;
    int g[n][n];
    vector<bool> visited(n);
    vector<int> p(n,-1), min_e(n, INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    min_e[0] = 0;
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if (!visited[j] && (v == -1 || min_e[j] < min_e[v])) v = j;
        }
        visited[v] = true;
        if(p[v] != -1) ans += g[v][p[v]];
        for(int j = 0; j < n; j++){
            if(g[v][j] < min_e[j]){ 
                min_e[j] = g[v][j];
                p[j] = v;
            }
        }
    }
    cout << ans;
    return 0;
}