#include <iostream>
#include <stack>
using namespace std;

bool parentitzada(stack<char>& pila) {
  char c;
  cin >> c;
  if(c == '.') return pila.empty();
  else {
    if(c == '(' or c == '[') pila.push(c);
    else if(c == ')' or c == ']') {
      if(pila.empty()) return false;

      else if(c == ')'){
        if(pila.top() == '(') pila.pop();
        else return false;
      }
      else if(c == ']'){
        if(pila.top() == '[') pila.pop();
        else return false;
      }
    }
  }
  return parentitzada(pila);
}

int main() {
  stack<char> pila;
  if(parentitzada(pila)) cout << "Correcte" << endl;
  else cout << "Incorrecte" << endl;
}
