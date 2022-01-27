#include "LlistaIOEstudiant.hh"

void esborra_tots(list<Estudiant> &t, int x) {
	list<Estudiant>::iterator it = t.begin();
	Estudiant a;
	while (it != t.end()) {
		a = *it;
		if (a.consultar_DNI() == x) it = t.erase(it);
		else ++it;
	}
}
