#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int q, k;
    cin >> q >> k;
    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    long long sum = 0;
    for(int i = 0; i < q; ++i){
        string command;
        cin >> command;
        if(command == "insert"){
            long long n;
            cin >> n;
            min_heap.push(n);
            if(min_heap.size() > k){
                sum -= min_heap.top();
                min_heap.pop();
            }
            sum += n;
        }
        else if(command == "print"){cout << sum << endl;}
    }
    return 0;
}