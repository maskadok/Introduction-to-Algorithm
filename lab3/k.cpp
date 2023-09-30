#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int left = 0, right = 0, sum = 0, minLen = n + 1;
    while(right < n){
        sum += arr[right];
        while(sum >= k){
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
        right++;
    }
    if (minLen == n + 1){cout << "0" << endl;}
    else{cout << minLen << endl;}
    return 0;
}
