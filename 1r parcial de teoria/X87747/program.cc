#include <iostream>
#include <vector>
using namespace std;

/* Pre: v.size() > 0 */
/* Post: el resultat es el nombre de solitaris a v */
int solitaris(const vector<int> &v)
{
  int count = 0;
  int llargada = v.size();
  if (llargada == 1) return 1;
  //Tractarem el primer i l'ultim cas com si fossin especials
  if (llargada != 1 and v[0] != v[1]) ++count;

  for (int i = 1; i < llargada-1; ++i)
  {
    if (v[i] != v[i-1] and v[i] != v[i+1]) ++count;
  }

  if (llargada != 1 and v[llargada-1] != v[llargada-2]) ++count;
  return count;
}
