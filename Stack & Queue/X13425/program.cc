#include "CuaIOParInt.hh"

int temps_cua(queue<ParInt> c)
{
  int r = 0;
  while(not c.empty()) {
    r += c.front().segon();
    c.pop();
  }
  return r;
}

void solve(queue<ParInt> c)
{
  queue<ParInt> primera;
  queue<ParInt> segona;
  ParInt a;
  while(not c.empty())
  {
    a = c.front();
  /*  cerr << "Afegint : ";
    a.escriure();
    cerr << endl;
    cerr << "T1: " << temps_cua(primera) << " --- T2: " << temps_cua(segona) << endl;*/
    if(temps_cua(segona) < temps_cua(primera)) {
      segona.push(a);
    /*  cerr << "Aded to segona" << endl << "--------------" << endl;
      escriureCuaParInt(segona);
      cerr << "---------------" << endl;*/
    }
    else {
      primera.push(a);
    /*  cerr << "Aded to primera" << endl << "--------------" << endl;
      escriureCuaParInt(primera);
      cerr << "---------------" << endl;*/
    }
    c.pop();
  }
  escriureCuaParInt(primera);
  cout << endl;
  escriureCuaParInt(segona);
}

int main() {
  queue<ParInt> cua;
  llegirCuaParInt(cua);
  solve(cua);
}
