#include <map>
#include <iostream>
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
      else ++diccionari[s];
    }
    else if(c == 'e')
    {
      if(it != diccionari.end() and it->second != 0) --diccionari[s];
    }
    else if(c == 'f')
    {
      if(it == diccionari.end()) cout << "0" << endl;
      else cout << it->second << endl;
    }
  }
}
