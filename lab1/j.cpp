#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

int main (){
    char s;
    int x;
    bool b = true;
    deque<int> d;
    while(b){
        cin >> s;
        if(s == '+'){
            cin >> x;
            d.push_front(x);
        }
        if(s == '-'){
            cin >> x;
            d.push_back(x);
        }
        if(s == '*'){
            if(d.empty())  cout << "error" <<endl;
            else{
            cout << d.front() + d.back() << endl;
            if (!d.empty()) d.pop_front();
            if (!d.empty()) d.pop_back();
            }
        }
        if(s == '!') b = false;
    }
}