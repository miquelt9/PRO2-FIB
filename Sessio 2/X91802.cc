#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

/* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */

pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
	pair<double,double> max_min;
	pair<int,int> dni; //servirà per saber el dni del que té millor i pitjor nota
	pair<int,int> pos; //posicio on esta el max_min

	int llargada = v.size();
	max_min.first = max_min.second = pos.first = pos.second = -1;

	int i = 0;
	while(i < llargada and not v[i].te_nota()) ++i;
	
	if(i == llargada) return pos;
	
	dni.first = dni.second = v[i].consultar_DNI();
	max_min.first = max_min.second = v[i].consultar_nota();	
	pos.first = pos.second = i;		


	while(i < llargada) {
		if(v[i].te_nota())
		{
			double nota_aux = v[i].consultar_nota();
			//cerr << nota_aux;
			if(nota_aux > max_min.first) {
				//cerr << " >= " << max_min.first << endl;
				max_min.first = nota_aux;
				dni.first = v[i].consultar_DNI();
				pos.first = i;
				//cerr << "Max is now = " << max_min.first;
			}
			else if(nota_aux < max_min.second /*and v[i].consultar_DNI() < dni.second*/) {
				//cerr << " <= " << max_min.second << endl;
				max_min.second = nota_aux;
				dni.second = v[i].consultar_DNI();
				pos.second = i;
				//cerr << "Min is now = " << max_min.first;
			}
			else if(nota_aux == max_min.first and v[i].consultar_DNI() < dni.first) 
			{
				dni.first = v[i].consultar_DNI();
				pos.first = i;
			}
			else if(nota_aux == max_min.second and v[i].consultar_DNI() < dni.second)
			{
				dni.second = v[i].consultar_DNI();
				pos.second = i;
			}
			//cerr << "------------" << endl;
		}
		++i;
	}
	return pos;
}

/*int main()
{
	int n;
	cin >> n;
	vector<Estudiant> v(n);
	for (int i = 0; i < n; ++i) v[i].llegir();
	pair<int,int> max_min = max_min_vest(v);
	cout << max_min.first << " " << max_min.second << endl;
}*/