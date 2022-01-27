#include "LlistaIOEstudiant.hh"

int main() {
	list<Estudiant> l;
	LlegirLlistaEstudiant(l);
	int n, count = 0;
	cin >> n;
	for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it) {
		Estudiant a = *it;
		if(a.consultar_DNI() == n) ++count;
	}
	cout << n << " " << count << endl;
}