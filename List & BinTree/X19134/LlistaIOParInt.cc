#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  ParInt a;
  while(a.llegir()) {
    l.insert(l.end(), a);
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  ParInt a;
  for(list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
    a = *it;
    a.escriure();
  }
}
