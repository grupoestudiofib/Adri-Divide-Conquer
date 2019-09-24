//DONE 
#include <iostream>
#include <vector>
using namespace std;

/*
    fa(i) = i = xi + a -> i - xi = a

    Queremos ver que i - xi se quedan en orden no creciente:

    cj >= 2  cj = cj-1 + cj-2 + ... + cj-k con  c j-k = 0   para 1 <  j < n
    siendo cj el incremento de xj-1 a xj

    1 - x1 >= 2 -x2 >= 3 -x3 >= 4 - x4 ->
    [x2 > x1 => x2 = x1 + c2]
    ->  1 - x1 >= 2 - x1 - c2 >= 3 - x1 - c3 >= 4 - x1 - c4 ->
    ->  1 >= 2 -c2 >= 2 - c2 - c3 >= 4 - c2 - c3 - c4 ->
    ->  1 + c2 >= 2 >= 3 - c3 >= 4 - c3 -c4 ->
    evidente con cj >= 1 que la secuencia queda en orden no creciente


*/

//pre: puede haber mas de 1 que == a
bool rb_search(int a, const vector<int>& v, int f, int l, int& r){
    if(f > l) return false;
    else {
        int m = (f+l)/2;
        if(v[m] > a) return rb_search(a, v, m+1, l, r);
        else if(v[m] < a) return rb_search(a, v, f, m-1, r);
        else{
            int k;
            if(rb_search(a, v, f, m-1, k)) r = k;                               //busca si hhay una apraicion anterior :) (first apearcence)
            else r = m;
            return true;
        }
    }
}

int main(){
    int n, count = 1;
    while(cin>>n){

        vector<int> v (n);
        for(int i = 0; i < n; ++i) {
            int xi;
            cin>>xi;
            v[i] = i+1 - xi;                                                //formula enunciado jutge :)
        }

        cout<<"Sequence #"<<count<<endl;
        int m, a;
        cin>>m;
        for(int i = 0; i < m; ++i) {
            cin>>a; 
            int f = 0, l = v.size()-1, r;
            bool fpf = rb_search(a, v, f, l, r);
            if(fpf) cout<<"fixed point for "<<a<<": "<<r+1<<endl;
            else cout<<"no fixed point for "<<a<<endl;
        }
        cout<<endl;

        ++count;
    }
}