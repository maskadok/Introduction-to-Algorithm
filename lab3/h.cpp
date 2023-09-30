#include <iostream>
using namespace std;

int bs(int a[], int t, int n){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = l + (r - l)/2;
        if(a[m] < t){l = m + 1;}
        else{r = m - 1;}
    }
    return l;
}

int main(){
    int n, m, sum = 0;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        a[i] = sum;
    }
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        cout << bs(a,t,n) + 1 << endl;
    }
    return 0;
}