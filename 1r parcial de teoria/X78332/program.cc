#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"
#include <stack>
using namespace std;

void write_stack(stack<int> c)
{
  cerr << "Printing stack:";
  while (not c.empty()) {
    cerr << " " << c.top();
    c.pop();
  }
  cerr << endl;
}


/* Pre: c es buida */
/* Post: c conte el cami preferent d'a; si no es buit, el primer element
   del cami es al cim de c */
void i_cami_preferent(const BinTree<int>& a, stack<int>& c, int& suma)
{
  if (a.empty()) suma = 0;
  else
  {
    stack<int> s_left = c;
    stack<int> s_right = c;
    int suma_e, suma_d;
    i_cami_preferent(a.left(), s_left, suma_e);
    i_cami_preferent(a.right(), s_right, suma_d);
    suma = suma_e + suma_d + 1;
    if (suma_d > suma_e) c = s_right;
    else c = s_left;
    c.push(a.value());
  }
}

void cami_preferent(const BinTree<int>& a, stack<int>& c)
{
  int suma;
  i_cami_preferent(a, c, suma);
}

/*
int main()
{
  BinTree<int> a;
  cerr << "Reading BinTree" << endl;
  read_bintree_int(a, 0); //El 0 serà la nostra marca
  cerr << "BinTree readed" << endl;
  stack<int> c;
  cami_preferent(a, c);
  cerr << endl << "FINISHED!" << endl;
  write_stack(c);
}
*/
