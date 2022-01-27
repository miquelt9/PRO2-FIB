#include <list>
#include <iostream>
using namespace std;
/*
//funcio per escriure llista:
void escriure(const list<int>& uno) {
  for(list<int>::const_iterator it = uno.begin(); it != uno.end(); ++it) cerr << *it << " ";
  cerr << endl;
}*/

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos ) {
  list<int>::const_iterator it1 = uno.begin();
  list<int>::const_iterator it2 = dos.begin();
  while(it1 != uno.end() and it2 != dos.end())
  {
    //cerr << "cheking... " << *it1 <<  " - " << *it2 << endl;
    if(*it2 < *it1) ++it2;
    else if(*it2 > *it1) it1 = uno.erase(it1);
    else ++it1;
    //escriure(uno);
    //escriure(dos);
  }
  while(it1 != uno.end()) it1 = uno.erase(it1);
}

//Main per fer proves:
/*int main() {
  int n, m;
  cout << "Introdueix el nº d'elements de la llista 1: ";
  list<int> uno;
  cin >> n;
  cout << endl << "Introdueix els numeros: " ;
  for(int i = 0; i < n; ++i) {
    cin >> m;
    uno.push_back(m);
  }
  cout << "Introdueix el nº d'elements de la llista 1: ";
  list<int> dos;
  cin >> n;
  cout << endl << "Introdueix els numeros: ";
  for(int i = 0; i < n; ++i) {
    cin >> m;
    dos.push_back(m);
  }
  inter(uno, dos);
  cout << endl << "La llista resultant és : ";
  for(list<int>::const_iterator it = uno.begin(); it != uno.end(); ++it) cout << *it << " ";
  cout << endl;
}*/
