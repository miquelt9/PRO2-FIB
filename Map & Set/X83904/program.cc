#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> totes, cap;
    string nom;
    cin >> nom;
    while (nom != ".")
    {
      totes.insert(nom);
      cin >> nom;
    }
    cap = totes;

    int n_activitats;
    cin >> n_activitats;
    set<string> falta;
    for (int i = 0; i < n_activitats; ++i) {
        falta = totes;
        cin >> nom;
        while (nom != ".") {
            cap.erase(nom);
            falta.erase(nom);
            cin >> nom;
        }
        for (set<string>::iterator it = falta.begin(); it != falta.end(); ++it) totes.erase(*it);
    }

    cout << "Totes les activitats:";
    for (set<string>::iterator it = totes.begin(); it != totes.end(); ++it)
    {
      cout << ' ' << *it;
    }
    cout << endl;

    cout << "Cap activitat:";
    for (set<string>::iterator it = cap.begin(); it != cap.end(); ++it)
    {
      cout << ' ' << *it;
    }
    cout << endl;
}
