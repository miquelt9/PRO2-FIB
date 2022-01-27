#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> pila;
  int n, m;
  cin >> n;
  for(int i = 0; i < n/2; ++i) {
    cin >> m;
    pila.push(m);
  }
  if(n%2 == 1) cin >> m;
  bool palindrom = true;
  while(palindrom and not pila.empty()) {
    cin >> m;
    if(m != pila.top()) palindrom = false;
    else pila.pop();
  }
  if(palindrom) cout << "SI" << endl;
  else cout << "NO" << endl;
}
