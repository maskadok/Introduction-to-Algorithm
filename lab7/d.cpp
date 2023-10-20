#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct student{
    vector<pair< pair<string, string>, double>> v;
    void append(string sname, string name, double gpa){v.push_back(make_pair(make_pair(sname, name), gpa));}
    void print(){cout << v[0].first.first << " " <<  v[0].first.second <<  " "  << fixed << setprecision(3) << v[0].second <<  endl;}
    string getSurname(){return v[0].first.first;}
    string getName(){return v[0].first.second;}
    double getGPA(){return v[0].second;}
};

bool checkStudent(student a,  student &b){
    if(a.getGPA() < b.getGPA()){return true;}
    else if(a.getGPA() > b.getGPA()){return false;}
    else{
        if(a.getSurname() < b.getSurname()){return true;}
        else if(a.getSurname() > b.getSurname()){return false;}
        else{
            if(a.getName() < b.getName()){return true;}
            else if(a.getName() > b.getName()){return false;}
        }
    }
}

void merge(student *a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1, i = l1, i1 = 0, i2 = 0, n2 = r2 - l2 + 1;
    student L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = a[l1 + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = a[l2 + i];
    }
    while(i1 < n1 && i2 < n2){
        if(checkStudent(L[i1], R[i2])){a[i++] = L[i1++];}
        else{a[i++] = R[i2++];}
    }
    while(i1 < n1){a[i++] = L[i1++];}
    while(i2 < n2){a[i++] = R[i2++];}
}

void msort(student *a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}
double cSum;
double gcSum;
void credSum(int cred){
    cSum += cred;
}

void gpaCredSum(string l, int cred){
    double g;
    if(l == "A+") g = 4.00; else if(l == "A") g = 3.75; else if(l == "B+") g = 3.50;
    else if(l == "B") g = 3.00; else if(l == "C+") g = 2.50; else if(l == "C") g = 2.00;
    else if(l == "D+") g = 1.50; else if(l == "D") g = 1.00; else if(l == "F") g = 0;
    gcSum += (g * cred);
}

int main(){
    int n, m;
    cin >> n;
    student students[n];
    for(int i = 0; i < n;i++){
        string sname, name;
        double gpa;
        cin >> sname >> name >> m;
        for(int j = 0; j < m; j++){
            string l; cin >> l;
            int cred; cin >> cred;
            gpaCredSum(l, cred);
            credSum(cred);
        }
        gpa = gcSum / cSum;
        students[i].append(sname, name, gpa);
        gcSum = 0;
        cSum = 0;
    }
    msort(students, 0, n - 1);
    for(int i = 0; i < n;i++){
        students[i].print();
    }
    return 0;
}