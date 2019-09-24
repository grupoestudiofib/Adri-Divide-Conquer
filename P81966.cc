//DONE
#include <iostream>
#include <vector>
using namespace std;
 
//os recomiendo que os lo sepais de memoria porque pinta que es lo que espran de nosotros y en los examenes el tiempo es oro :)
int posicio(double x, const vector<double>& v, int esq, int dre) {
                if (esq > dre) return -1;
                int mid = (esq+dre)/2;
                if (x < v[mid]) return posicio(x, v, esq, mid-1);
                if (x > v[mid]) return posicio(x, v, mid+1, dre);
                return mid;
}
 
int main(){
	
}
