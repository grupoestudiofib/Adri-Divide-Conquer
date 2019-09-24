//DONE
#include <iostream>
#include <vector>
using namespace std;

/*
ALGORITMO:
    cerca dicot => si lo encuentra comprueba que sea la primera aparicion (fa; aparicion: A) 
    haciendo mas cercas_dicot en el tramo anterior a la A. Si en el tramo anterior a la ultima A encontrada no hay otra A, esta es la fa

*/

int cerca_dicot(double x, const vector<double>& v, int f, int l){
    if(f > l) return -1;
    int m = (f+l)/2;
    if(x < v[m]) return cerca_dicot(x,v,f,m-1);                         //primero se ejecutaran las cridas recursivas hacia la izq
    if(x > v[m]) return cerca_dicot(x,v,m+1,l);
    return m;
}

//pre: v sorted ascending order
//post: enunciado jutge
int first_occurrence(double x, const vector<double>& v){                
    int f = 0, l = v.size() - 1;
    int r = cerca_dicot(x,v,f,l);                               //fa = first apearence; qué pasa si r no es la fa? => que la fa esta antes
    int fa = r;
    while(r > 0){                                               //r == -1 suda, r!=-1 (x encontrada en el vector) => comprueba si hay una aparicion anterior en v de x 
        r = cerca_dicot(x,v,f,r-1);
        if(r != -1) fa = r;                                     //si hay una aparicion de x anterior la fa se actualiza
    }
    return fa;
}

int main(){
}

