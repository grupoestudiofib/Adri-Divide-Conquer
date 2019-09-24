//DONE
#include <iostream>
#include <vector>
using namespace std;

/*
    ALGORITMO:   
    $*
    Usa el mergesort normal con el añadido $* de contar el numero de inversiones que hay que hacer para ordenarlo. En la funcion fusion()
    se pillan los dos subvectores a fusionar y se van metiendo en el auxiliar. 
    vi = [xi, xi+1, xi+2, xi+3, ..., xm] elems ordenados; vj = [xm+1, xm+2, xm+3, ..., xj] tmb elems ordenados;
     el vector que fue 'cortado' en el caso anterior es v = [xi, xi+1, xi+2, xi+3, ..., xm | xm+1, xm+2, xm+3, ...,  xj]
    se tienen indices auxi y auxj apuntando a los primeros elementos de cada vector que aun no han sido tratados para fusionar 
    ej: en un momento dado... vi[auxi] == xi+c y vj[auxj] == xm+k; si xm+k < xi+c => para que ambos queden ordenados xm+k tiene que swapearse con
    todos los elementos desde xm hasta xi+c => con este movimiento se hacen m+k - (i + c) + (k-1) {los j ya tratados: t} swaps lo que es igual a auxj - auxi swaps
    Este es el unico paso del algoritmo de fusion (y por ende del MergeSort) en el que se swapean elementos (virtualmente)

*/


//Mergesort code

int fusion(vector<int>& v, int i, int m, int j){
    int inv = 0;

	vector<int> w(j-i+1);                                       //Aqui declara un vector auxiliar del tamaño 3-0+1 = 4;
	int auxi = i, auxj = m+1, k = 0;                            //Aqui declara las mismas i's i j's como la misma i, y la j ya dividida.
	while(auxi <= m and auxj <= j){                             // Auxi hace referencia al primer elemento del subvector1 i auxj del subvector m a la ultima posicion del subvector 1, i j a la ultima posicion del subvector2;
		if(v[auxi] <= v[auxj]) w[k++] = v[auxi++];              //compara el contenido de esas posiciones dle vector y mete en el vector auxiliar la mas pequeña.									
		else {
            int t = auxj - (m+1);                               //las j ya tratadas 
            inv += auxj - auxi - t;                             //$*  (ver comentario ALGORITMO)
            w[k++] = v[auxj++];
        }
	}
	while(auxi <= m) w[k++] = v[auxi++];		                //whiles para asegurarse que todo se cumple
	while(auxj <= j) w[k++] = v[auxj++];
	for(k = 0; k <= j-i; ++k) v[i+k] = w[k];                    //mete por orden todos los subvectores en el vector auxiliar y finaliza.
    return inv; 
}

void n_inversions_mergesort(vector<int>& v, int i, int j, int& r){
	if(i < j){                                                  //Si el vector no esta vacio(i = izq j = der)
		int m = (i+j)/2;                                        //coje los extremos del vector y encuentra la posicion media Ej: [5 7 0 3] 0+3/2 = 1 v[1] = 7;
		int inv1 = 0, inv2 = 0;
        n_inversions_mergesort(v,i,m, r);                    //aqui se llama a si misma pero con [5 7] solamente
		n_inversions_mergesort(v,m+1,j, r);                  //aqui se llama a si misma pero con [0 3] solamente
		r += fusion(v,i,m,j);
	}
}

int main(){
    int n;
    while(cin>>n){
        vector<int> v (n);
        for(int i = 0; i < n; ++i) cin>>v[i];
        int r = 0;
        n_inversions_mergesort(v, 0, v.size()-1, r);
        cout<<r<<endl;
    }
}