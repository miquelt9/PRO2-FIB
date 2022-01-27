#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string, int> diccionari;
  char c;
  string s;
  map<string, int>::const_iterator it;
  while(cin >> c >> s)
  {
    it = diccionari.find(s);
    if(c == 'a')
    {
      if(it == diccionari.end()) diccionari.insert(make_pair(s, 1));
      else diccionari[s] = it->second + 1;
    }
    else if(c == 'f')
    {
      if(it == diccionari.end()) cout << "0" << endl;
      else cout << it->second << endl;
    }
  }
}
