#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
    int a, b, cost;
};
int n, m, v;
vector<edge> e;
const int INF = 1e9;
bool cycle = false;
void func(){
    int x;
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    for(int i = 0; i < n; i++){
        x = -1;
        for(int j = 0; j < n * n; j++){
            if(d[e[j].a] < INF){
                if(d[e[j].b] > d[e[j].a] + e[j].cost){
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    if (x == -1) cycle = false;
    else{
        int y = x;
        for(int i = 0; i < n; i++){
            y = p[y];
        }
        vector<int> path;
        for(int cur = y; ; cur = p[cur]){
            path.push_back(cur);
            if(cur == y && path.size() > 1) break;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size() << endl;
        for (int i = 0; i < path.size(); i++){
            cout << path[i] + 1 << ' ';
        }
        cout << endl;
        cycle = true;
    }
}

int main(){
    cin >> n;
    vector<int> d(n, INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            edge cur;
            cin >> cur.cost;
            cur.a = i; cur.b = j;
            e.push_back(cur);
        }
    }
    for(int i = 0; i < n; i ++){
        v = i;
        func();
        if(cycle) break;
    }
    if(!cycle) cout << "NO\n";
    return 0;
}