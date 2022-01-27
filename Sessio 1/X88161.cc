#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equip {
	int n_equip, punts, marcats, rebuts;
};

vector<vector<pair<int,int>>> llegir_partits() {
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> r(n, vector<pair<int,int>>(n));
	for(int  i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) cin >> r[i][j].first >> r[i][j].second;
	}
	return r;
}

//Espais: 0 --> nº equip, 1 --> punts, 2 --> gols marcats, 3 --> gols rebuts
bool ord(const Equip& a, const Equip& b) {
	if(a.punts != b.punts) return a.punts > b.punts;
	if(a.rebuts - a.marcats != b.rebuts - b.marcats) return a.rebuts - a.marcats < b.rebuts - b.marcats;
	return a.n_equip < b.n_equip;
}

//Espais: 0 --> nº equip, 1 --> punts, 2 --> gols marcats, 3 --> gols rebuts
vector<Equip> calcular(const vector<vector<pair<int,int>>>& p) {
	int mida = p.size();
	vector<Equip> r(mida);
	for(int i = 0; i < mida; ++i) r[i].n_equip = i+1; //assignem el nº equip
	for(int i = 0; i < mida; ++i) r[i].punts = r[i].marcats = r[i].rebuts = 0; //fiquem tot a 0
		
	int visitant, local;
	for(int i = 0; i < mida; ++i) {
		for(int j = 0; j < mida; ++j) {
			if(i != j) {
				local = p[i][j].first;
				visitant = p[i][j].second;
				//punts
				if(local > visitant) r[i].punts += 3;
				else if(visitant > local) r[j].punts += 3;
				else ++r[i].punts, ++r[j].punts;
				//gols marcats
				r[i].marcats += p[i][j].first;
				r[j].marcats += p[i][j].second;
				//gols rebuts
				r[i].rebuts += p[i][j].second;
				r[j].rebuts += p[i][j].first;
			}
		}
	}
	return r;
}

void escriu_equip(const Equip& e) {
	cout << e.n_equip << " " << e.punts << " " << e.marcats << " " << e.rebuts << endl;
}

int main() {
	vector<vector<pair<int,int>>> graella;
	graella = llegir_partits();
	vector<Equip> resultats;
	resultats = calcular(graella);
	sort(resultats.begin(), resultats.end(), ord);
	for(int i = 0; i < resultats.size(); ++i) escriu_equip(resultats[i]);
}
