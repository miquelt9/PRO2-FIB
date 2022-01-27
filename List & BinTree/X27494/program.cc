#include <iostream>
#include <list>
#include <limits>
#include <algorithm>
using namespace std;

struct Stats {
  int max, min, n_elements;
  double suma;
};

void print_stats(const Stats& s) {
  cout << s.min << " " << s.max << " " << s.suma/s.n_elements << endl;
}

void recalcular(Stats& s, list<int> l) {
  s.max = numeric_limits<int>::min();
  s.min = numeric_limits<int>::max();
  for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
    if (*it > s.max) s.max = *it;
    if (*it < s.min) s.min = *it;
  }
}

int main() {
  int op, valor;
  Stats s;
  list<int> l;
  list<int>::iterator it;
  s.max = numeric_limits<int>::min();
  s.min = numeric_limits<int>::max();
  s.suma = s.n_elements = 0;
  cin >> op >> valor;
  while(op != 0 or valor != 0) {
    if (op == -1) //afegir valor a la llista
    {
      l.push_back(valor);
      if (valor > s.max) s.max = valor;
      if (valor < s.min) s.min = valor;
      ++s.n_elements;
      s.suma += valor;
    }
    else if (op == -2) //esborrar valor de la llista
    {
      it = find(l.begin(), l.end(), valor);
      if (it != l.end())
      {
        it = l.erase(it);
        if (valor == s.max or valor == s.min) recalcular(s, l);
        --s.n_elements;
        s.suma -= valor;
      }
    }
    //print
    if (s.n_elements != 0) print_stats(s);
    else cout << "0" << endl;
    cin >> op >> valor;
  }
}
