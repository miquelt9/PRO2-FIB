#include "LlistaIOParInt.hh"

int main() {
  list<ParInt> l;
  LlegirLlistaParInt(l);
  int n, sum = 0, count = 0;
  cin >> n;
  for(list<ParInt>::iterator it = l.begin(); it != l.end(); ++it){
    ParInt a = *it;
    if(a.primer() == n) {
      ++count;
      sum += a.segon();
    }
  }
  cout << n << " " << count << " " << sum << endl;
}
