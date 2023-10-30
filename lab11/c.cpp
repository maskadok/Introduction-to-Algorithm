#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(1001);
int dsu_get(int v){
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}
void dsu_unite(int a, int b){
	a = dsu_get (a), b = dsu_get (b);
	if (rand() & 1) swap (a, b);
	if (a != b) p[a] = b;
}

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int , pair<int, int>>> g;
    while(m--){
        string roadType;
        int a, b, c;
        cin >> roadType >> a >> b >> c;
        if(roadType == "big") g.push_back(make_pair(c * x, make_pair(a, b)));
        else if(roadType == "small") g.push_back(make_pair(c * y, make_pair(a, b)));
        else if(roadType == "both"){
            g.push_back(make_pair(c * x, make_pair(a, b)));
            g.push_back(make_pair(c * y, make_pair(a, b)));
        }
    }
    int k = g.size(), cost = 0;
    vector <pair<int,int>> res;
    sort(g.begin(), g.end());
    p.resize(n);
    for(int i = 0; i < n; ++i){
        p[i] = i;
    }
    for(int i = 0; i < k; ++i){
        int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if(dsu_get(a) != dsu_get(b)){
            cost += l;
            res.push_back(g[i].second);
            dsu_unite (a, b);
	    }
    }
    cout << cost;
    return 0;
}