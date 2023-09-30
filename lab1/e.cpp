#include <bits/stdc++.h>
using namespace std;

int main(){
    queue <int> Boris;
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        Boris.push(a);
    }
    queue <int> Nursik;
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        Nursik.push(a);
    }
    bool flag = true;
    int i = 0, B = 0, N = 0;
    while(flag){
        if(Nursik.empty() == true or Boris.empty() == true){
            break;
        }
        if(i == 1000000){
            cout<<"blin nichya";
            return 0;
        }
        if(Boris.front() == 0 and Nursik.front() == 9){
            B++;
            Boris.push(Boris.front());
            Boris.pop();
            Boris.push(Nursik.front());
            Nursik.pop();
        }
        else if(Boris.front() == 9 and Nursik.front() == 0){
            N++;
            Nursik.push(Boris.front());
            Boris.pop();
            Nursik.push(Nursik.front());
            Nursik.pop();
        }
        else if(Boris.front() > Nursik.front()){
            B++;
            Boris.push(Boris.front());
            Boris.pop();
            Boris.push(Nursik.front());
            Nursik.pop();
        }
        else if(Boris.front() < Nursik.front()) {
            N++;
            Nursik.push(Boris.front());
            Boris.pop();
            Nursik.push(Nursik.front());
            Nursik.pop();
        }
        i++;
    }
    if(N > B) cout << "Nursik " << N + B;
    else cout << "Boris "<< B + N;
}