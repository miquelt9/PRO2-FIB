#include <iostream>
#include <list>
using namespace std;

/* Pre: l no es buida, sol es buida */
/* Post: sel es el resultat de treure d'l els elements febles en mitjana */
void seleccio(const list<double>& l, list<double>& sel)
{
    list<double>::const_iterator it = l.begin();
    sel.push_back(*it);
    double suma_pre = *it;
    int numeros_passats = 1;
    ++it;

    while (it != l.end()) {
      //cerr << endl << "Suma pre = " << suma_pre << "   nº passats = " << numeros_passats << endl;
      //cerr << "Comparing " << *it << " < " << suma_pre/numeros_passats << endl;
      if (*it >= suma_pre/numeros_passats)
      {
        //cerr << "Numero not feble found!! " << *it << endl;
        sel.push_back(*it);
      }
      suma_pre += *it;
      ++numeros_passats;
      ++it;
    }
}

/*
int main()
{
  list<double> l,sel;
  int n;
  double m;
  cin >> n;
  cerr << "Numero elements de la llista: " << n << endl;
  for (int i = 0; i < n; ++i) {
    cin >> m;
    l.push_back(m);
  }
  for (list<double>::const_iterator it = l.begin(); it != l.end(); ++it){
    cerr << " " << *it;
  }
  cerr << endl;
  seleccio(l, sel);
  cerr << "Llista de nº febles: ";
  for (list<double>::const_iterator it = sel.begin(); it != sel.end(); ++it){
    cerr << " " << *it;
  }
  cerr << endl;
}
*/
