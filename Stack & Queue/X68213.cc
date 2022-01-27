#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Llibre{
  int categoria;
  string titol;
};

//Pre: Es dona un vector d'stacks de Llibre i seguidament
//     ve un cin amb el títol i la categoria
//Pos: El llibre s'afageix a la categoria
void afegir_llibre(vector<stack<Llibre>>& piles) {
  Llibre a;
  cin >> a.titol >> a.categoria;
  piles[a.categoria-1].push(a);
}

//Pre: Es dona un vector d'stacks de Llibre i seguidament
//     ve el nº de llibres a retirar i la categoria de la pila
//Pos: Es retiren els llibres de la categoria
void retirar_llibre(vector<stack<Llibre>>& piles) {
  int n, cat;
  cin >> n >> cat;
  --cat;
  for(int i = 0; i < n; ++i) {
    piles[cat].pop();
  }
}

void mostrar_llibres(const vector<stack<Llibre>>& piles) {
  int n;
  cin >> n;
  cout << "Pila de la categoria " << n << endl;
  --n;
  stack<Llibre> pila = piles[n];
  int llargada = pila.size();
  for(int i = 0; i < llargada; ++i) {
    cout << pila.top().titol << endl;
    pila.pop();
  }
  cout << endl;
}

int main(){
  int operacio, n;
  cin >> n;
  vector<stack<Llibre>> piles(n);
  cin >> operacio;
  while(operacio != -4) {
    if(operacio == -1) afegir_llibre(piles);
    if(operacio == -2) retirar_llibre(piles);
    if(operacio == -3) mostrar_llibres(piles);
    cin >> operacio;
  }
}
