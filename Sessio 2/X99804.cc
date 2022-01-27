#include <vector>
#include "Estudiant.hh"
#include <algorithm>
#include <iostream>
using namespace std;

bool ord(const Estudiant& a, const Estudiant& b) {
	if(a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
	return a.consultar_DNI() < b.consultar_DNI();
}

int main() {
	double m, n, s; //m = nº estudiants; n = nº assignatures; s = nº assig seleccionades
	cin >> m >> n >> s;

	vector<int> assig_selec(s);
	for(int i = 0; i < s; ++i) cin >> assig_selec[i];

	vector<double> notes(n);
	vector<Estudiant> estudiants(m);

	int dni;

	for(int i = 0; i < m; ++i) {
		cin >> dni;
		estudiants[i] = Estudiant(dni);

		for(int j = 0; j < n; ++j) cin >> notes[j];

		double suma = 0;
		for(int j = 0; j < s; ++j) suma += notes[assig_selec[j]-1];

		estudiants[i].afegir_nota(suma/s);

	}

	sort(estudiants.begin(), estudiants.end(), ord);
	for(int i = 0; i < m; ++i) estudiants[i].escriure();
}
