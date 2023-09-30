#include <iostream>
using namespace std;

struct Stack{
    string st;
    int top;
    int size=0;
public:
    void push(char);
    void pop();
    string getStack();
};
void Stack::push(char x){
    st += x;
    size++;
}
string Stack::getStack(){
    return st;
}
void Stack::pop(){
    st = st.substr(0, st.length()-1);
}

int main(){
    string a, b;
    cin >> a >> b;
    Stack c, d;
    for(auto i : a){
        if(i !='#') c.push(i);
        else c.pop();
    }
    for(auto i : b){
        if(i != '#') d.push(i);
        else d.pop();
    }
    string a1, b1;
    if(c.getStack() == d.getStack()) cout << "Yes";
    else cout << "No";
}