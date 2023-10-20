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

int part(student *a, int low, int high){
    int i = low - 1, pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(checkStudent(a[j], a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(student *a, int low, int high){
    if(low < high){
        int pivot  = part(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
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
    qsort(students, 0, n - 1);
    for(int i = 0; i < n;i++){
        students[i].print();
    }
    return 0;
}