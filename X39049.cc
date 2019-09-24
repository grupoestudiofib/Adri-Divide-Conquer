//DONE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permut_product(vector<int>& v, int k){
    if(k == 0) sort(v.begin(), v.end());
    else if(k > 1){
        int len = v.size();
        vector<int> w (len);
        for(int i = 0; i < len; ++i) {
            w[i] = v[v[i]];
        }  

        permut_product(w, k/2);                                         //k/2 prop asociativa :), despues de la crida => w es el prod de todos los tts (menos uno si k impar)

        if(k%2) {                                                       //si es impar => sobrara uno de los emparej, also order (commut) w es e indexu + traspasar info 
            vector<int> aux (len);
            for(int i = 0; i < len; ++i) aux[i] = v[i];                 //necesario para hacer la operacion y guardarlo en v

            for(int i = 0; i < len; ++i) {
                int prev = v[i];
                v[i] = aux[w[i]];             
            }
        }
        else for(int i = 0; i < len; ++i) v[i] = w[i];                  //traspasar info inmaculada si es par
    }   
}

int main(){
    int n;
    while(cin>>n){
        vector<int> v (n);
        for(int i = 0; i < n; ++i) cin>>v[i];
        int k;
        cin>>k;
        permut_product(v, k);
        cout<<v[0];                                                   //n >= 1
        for(int i = 1; i < n; ++i) cout<<' '<<v[i];
        cout<<endl;
    }
}