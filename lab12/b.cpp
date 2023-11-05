#include <iostream>
#include <vector>
#include <set>
using namespace std; 

int INF = 1e9, n, m;
vector<pair<int,int>> g[200001];
vector<int> d(200001, INF);
int func(int s, int end){
    d.clear();
    for(int i = 0; i < 200001; i++){
        d[i] = INF;
    }
    d[s] = 0;
    set<pair<int,int> > q;
    q.insert(make_pair(d[s],s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int j = 0; j < g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if(d[v] + len < d[to]){
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    return d[end]; 
} 

int main(){ 
    cin >> n >> m;
    int a, b, q, w, e, r;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    cin >> q >> w >> e >> r;
    a = func(q,w) + func(w,e) + func(e,r), b = func(q,e) + func(e,w) + func(w,r);
    if(min(a, b) <= INF) cout << min(a,b);
    else cout << -1;
    return 0;
}