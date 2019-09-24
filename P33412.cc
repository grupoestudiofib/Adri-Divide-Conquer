//DONE 
#include <iostream>
#include <vector>
using namespace std;

bool i_resistant_search(double x, const vector<double>& v, int f, int l){
    if(f > l) return false;
    int m = (f+l)/2;
    if(v[m] > x) {
        if(m != v.size()-1 and v[m+1] == x) return true;                //ir comprobando los contiguos a los v[m] por si hay deceivals :)
        return i_resistant_search(x, v, f, m-1);
    }
    else if(v[m] < x) {
        if(m != 0 and v[m-1] == x) return true;
        return i_resistant_search(x, v, m+1, l);
    }
    return true;
}

bool resistant_search(double x, const vector<double>& v){
    int f = 0, l = v.size()-1;
    return i_resistant_search(x, v, f, l);
}

int main(){
    /*int n;
    while(cin>>n){
        vector<double> v (n);
        for(int i = 0; i < n; ++i) cin>>v[i];
        double x;
        cin>>x;
        bool found = resistant_search(x, v);
        if(found) cout<<"elemento encontradi, WIIIII"<<endl;
        else cout<<"NOOOOOOOOO foundo"<<endl;
    }*/
}