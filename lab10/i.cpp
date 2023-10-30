#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int MAXN = 1e5 + 1;
vector<int> matrix[MAXN], ans;
int color[MAXN];
void dfs(int v){
	if(color[v] == 1){
		cout << "Impossible\n";
		exit(0);
	}
	if(color[v] == 2) return;
	color[v] = 1;
	for(int i = 0; i <  matrix[v].size(); i++){
		int to = matrix[v][i];
		dfs(to);
	}
	color[v] = 2;
	ans.push_back(v);
}

int main(){
    int m;
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        matrix[i].push_back(j);
    }
	for(int i = 1; i <= n; i++){
		if(color[i] == 0) dfs(i);
	}
	cout << "Possible\n";
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
    return 0;
}