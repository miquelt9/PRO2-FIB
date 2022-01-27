#include <iostream>
#include <vector>
using namespace std;

/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
int comptatge_frontisses(const vector<int> &v)
{
  int llargada = v.size();
  if (llargada == 1) return 1;
  //La nostra gran tàctica consistira en primer sumar de v[1] fins el final
  //i tot seguit anar comparant les sumes i restar i sumar, que sinó el jutge
  //segur que ens dona un EE
  int k = 0;
  int a_comparar = v[k];
  int count, suma_pre, suma_pos;
  suma_pos = suma_pre = count = 0;

  for (int i = 1; i < llargada; ++i) suma_pos += v[i];
  if (suma_pos - suma_pre == a_comparar) ++count;
  ++k;

  while (k < llargada)
  {
    a_comparar = v[k];
    suma_pre += v[k-1];
    suma_pos -= v[k];
    if (suma_pos - suma_pre == a_comparar)
    {
      //  cerr << "Frontissa was found: " << a_comparar << endl;
        ++count;
    }
    ++k;
  }

  return count;
}
/*
//main per fer les proves:
int main()
{
  cerr << "Mida del vector: ";
  int n, m;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> m;
    v[i] = m;
  }
  cerr << endl << "El teu vector és:";
  for (int i = 0; i < n; ++i) cout << " " << v[i];
  cerr << endl;
  m = comptatge_frontisses(v);
  cerr << endl << "Nº de frontisses = " << m << endl;
}
*/
