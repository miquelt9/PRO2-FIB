#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
  ParInt a;
  while(a.llegir()) c.push(a);
}

void escriureCuaParInt(queue<ParInt> c)
{
  ParInt a;
  while(not c.empty()) {
    a = c.front();
    a.escriure();
    c.pop();
  }
}
