#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l){
  Estudiant a;
  a.llegir();
  while(a.consultar_DNI() != 0 and a.consultar_nota() != 0) {
    l.insert(l.end(), a);
    a.llegir();
  }
}

void EscriureLlistaEstudiant(list<Estudiant>& l) {
	Estudiant a;
	for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it) {
		a = *it;
		a.escriure();
	}
}
