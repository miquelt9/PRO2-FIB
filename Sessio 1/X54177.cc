#include <iostream>
using namespace std;

int main() {
	int n_seq, fi;
	cin >> n_seq >> fi;
	for (int i = 1; i <= n_seq; ++i) {
		int total, temp;
		total = 0;
		cin >> temp;
		while (temp != fi) {
			total += temp;
			cin >> temp;
		}
		string s;
        getline(cin, s);
		cout << "La suma de la secuencia " << i << " es " << total << endl;
	}
}
