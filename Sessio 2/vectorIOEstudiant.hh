#ifndef VECTOR_IO_ESTUDIANT
#define VECTOR_IO_ESTUDIANT

#include <iostream>
#include <vector>
#include "Estudiant.hh"

vector<Estudiant> llegir_vector();
/* Pre: Hi ha preparat al canal d'entrada un enter n seguit
        de n estudiants <DNI nota>
   Pos: Retorna un vector amb els estudiants
*/

void escriure_vector(const vector<Estudiant>& v);
/* Pre: Es dona un vector d'estudiants
   Pos: Escriu el <DNI nota> de cada estudiant del vector
*/

#endif
