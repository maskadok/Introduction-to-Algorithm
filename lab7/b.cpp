#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1, L[n1], n2 = r2 - l2 + 1, R[n2], i = l1, i1 = 0, i2 = 0;
    for(int i = 0; i < n1; i++){
        L[i] = a[l1 + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = a[l2 + i];
    }
    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){a[i++] = L[i1++];}
        else{a[i++] = R[i2++];}
    }
    while(i1 < n1){a[i++] = L[i1++];}
    while(i2 < n2){a[i++] = R[i2++];}
}

void msort(vector<int> &a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main(){
    int n, m;
    cin >> n;
    vector<int> all;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        all.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        all.push_back(x);
    }
    msort(all, 0, all.size() - 1);
    for(int i = 0; i < all.size(); i++){
        cout << all[i] << " ";
    }
}