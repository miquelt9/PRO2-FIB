#include "BinTreeIOEst.hh"

void find(const BinTree<Estudiant>& a, const int& dni, int& deapness, int& nota, int& deap) {
  if(not a.empty()) {
    Estudiant est = a.value();
    if(est.consultar_DNI() == dni) {
      if(deapness == -1 or deapness > deap) {
        if(est.te_nota()) {
          nota = est.consultar_nota();
        }
        deapness = deap;
      }
    }
    else {
      ++deap;
      find(a.left(), dni, deapness, nota, deap);
      find(a.right(), dni, deapness, nota, deap);
      --deap;
    }
  }
}

int main() {
  BinTree<Estudiant> arbre;
  read_bintree_est(arbre);
  int dni;
  while(cin >> dni)
  {
    int nota = -1;
    int deap = 0;
    int deapness = -1;
    find(arbre, dni, deapness, nota, deap);
    if(deapness != -1) cout << dni << " " << deapness << " " << nota << endl;
    else cout << dni << " -1" << endl;
  }
}
