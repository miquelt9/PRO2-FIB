#include "Cjt_estudiants.hh"

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  int pos = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
  b = pos < nest and vest[pos].consultar_DNI() == est.consultar_DNI();

  if (not b) {
    for(int i = nest-1; i >= pos; --i) {
      vest[i+1] = vest[i];
    }
    ++nest;
    vest[pos] = est;
    if(vest[pos].te_nota()) {
      if(nest_amb_nota == 0) suma_notes = est.consultar_nota();
      else suma_notes += est.consultar_nota();
      ++nest_amb_nota;
    }
  }
}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
  int pos = cerca_dicot(vest, 0, nest-1, dni);
  b = false;
  if(pos < nest and dni == vest[pos].consultar_DNI()) b = true;
  if(b) {
    if(vest[pos].te_nota()) {
      --nest_amb_nota;
      suma_notes -= vest[pos].consultar_nota();
    }
    for(int i = pos; i < nest - 1; ++i){
      vest[i] = vest[i+1];
    }
    --nest;
  }
}
