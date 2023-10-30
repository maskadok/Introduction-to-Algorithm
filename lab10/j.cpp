#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n);
    vector<int> parents(n, -1);
    while(m--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        matrix[x].push_back(y);
        parents[y] = x;
    }
    for(int i = 0; i < n; i++) {
        if(parents[i] == -1) cnt++;
        else if(matrix[parents[i]].size() < matrix[i].size()) cnt++;
    }
    cout << cnt;
}