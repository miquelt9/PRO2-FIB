#include "BinTreeIOParInt.hh"

void find(const BinTree<ParInt>& arbre, const int& n, int& mate, int& deap, int& found) {
  if (found == -1 and not arbre.empty()) {
    ParInt a = arbre.value();
    if (a.primer() == n) {
      mate = a.segon();
      found = deap;
    }
    else {
      ++deap;
      find(arbre.left(), n, mate, deap, found);
      find(arbre.right(), n, mate, deap, found);
      --deap;
    }
  }
}

int main() {
  BinTree<ParInt> arbre;
  read_bintree_parint(arbre);
  int n;
  while (cin >> n) {
    int mate, deap = 0;
    int found = -1;
    find(arbre, n, mate, deap, found);
    if (found != -1) cout << n << " " << mate << " " << found << endl;
    else cout << -1 << endl;
  }
}
