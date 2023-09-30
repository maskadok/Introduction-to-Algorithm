#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a = 0;
    if(x == 0 || x == 1){
        cout << "NO";
        return 0;
    }
    for(int i = 2; i < x; i++){
        if(x % i == 0) a++;
    }
    if(a == 1 || a==0) cout << "YES";
    else cout << "NO";
}