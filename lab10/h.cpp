#include <iostream>
using namespace std;

char a[100][100];
int n, m;
void dfs(int i, int j){
    if(i < 0 || j < 0 || a[i][j] == '0' || i >= n || j >= m ) return;
    a[i][j] = '0';
    dfs(i, j + 1), dfs(i, j - 1), dfs(i + 1, j), dfs(i - 1, j);
}

int main(){
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '1'){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}