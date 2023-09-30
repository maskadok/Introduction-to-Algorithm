#include <iostream>
using namespace std;

int main(){
    int n, top = 0, a = 999999;
    cin >> n;
    int k[n];
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    for(int i = 0; i < n; i++){
        int number = k[i];
        int ans = -1;
        for(int j = i-1; j >= top; j--){
            if(k[j] <= number){
                ans = k[j];
                break;
            }
        }
        a = min(number, a);
        if(a == k[i]){
            top = i;
        }
        cout << ans << " ";
    }
}