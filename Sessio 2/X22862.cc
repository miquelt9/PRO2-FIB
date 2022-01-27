#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;


double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
}

void nou_estudiant(Cjt_estudiants& a) {
	int dni;
	double nota;
	cin >> dni >> nota;
	Estudiant est(dni);
	if(nota >= 0 and nota <= 10) est.afegir_nota(nota);
	if(a.existeix_estudiant(dni)) cout << "el estudiante " << dni << " ya estaba" << endl << endl;
	else if(a.mida() == 5) cout << "el conjunto esta lleno" << endl << endl;
	else a.afegir_estudiant(est);
}

void consultar_nota_dni(const Cjt_estudiants& a) {
	int dni;
	cin >> dni;
	if (a.existeix_estudiant(dni)) {
		Estudiant est;
		est = a.consultar_estudiant(dni);
		if(est.te_nota()) cout << "el estudiante " << dni << " tiene nota " << est.consultar_nota() << endl << endl;
		else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
	}
	else cout << "el estudiante " << dni << " no esta" << endl << endl;
}

void modificar_nota_est(Cjt_estudiants& a) {
	int dni;
	double nota;
	cin >> dni >> nota;
	if (a.existeix_estudiant(dni)) {
		Estudiant est = a.consultar_estudiant(dni);
		if(est.te_nota()) est.modificar_nota(nota);
		else  est.afegir_nota(nota);
		a.modificar_estudiant(est);
	}
	else cout << "el estudiante " << dni << " no esta" << endl << endl;
}

void arrodonir_cjt(Cjt_estudiants& a) {
	int mida = a.mida();
	for(int i = 1; i <= mida; ++i) {
		Estudiant est = a.consultar_iessim(i);
		if(est.te_nota()) est.modificar_nota(redondear(est.consultar_nota()));
		a.modificar_iessim(i, est);
	}
}

int main(){
	int operacio;
	Cjt_estudiants estudiants;
	estudiants.llegir();
	cin >> operacio;
	while(operacio != -6) {
		if (operacio == -1) nou_estudiant(estudiants);
		else if (operacio == -2) consultar_nota_dni(estudiants);
		else if (operacio == -3) modificar_nota_est(estudiants);
		else if (operacio == -4) arrodonir_cjt(estudiants);
		else if (operacio == -5)  {
			estudiants.escriure();
			cout << endl;
		}
		cin >> operacio;
	}
}