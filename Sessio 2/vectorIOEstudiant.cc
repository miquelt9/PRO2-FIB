#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"
#include <vector>

vector<Estudiant> llegir_vector(){
  int n;
  cin >> n;
  vector<Estudiant> v(n);
  for(int i = 0; i < n; ++i) {
    v[i].llegir();
  }
  return v;
}

void escriure_vector(const vector<Estudiant>& v){
  int n = v.size();
  for(int i = 0; i < n; ++i) {
    v[i].escriure();
  }
}
