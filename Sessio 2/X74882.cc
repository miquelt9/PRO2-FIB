#include "Cjt_estudiants.hh"

//Pre: a i b contenen els mateixos estudiants i sense repeticions
//Pos: a conté la millor nota de cada estudiant i esta ordenat per dni creixent
void millor_nota(Cjt_estudiants& a, const Cjt_estudiants& b) {
	int mida = a.mida();
	//cerr << mida << endl << endl;
	Estudiant est1, est2;
	for (int i = 1; i <= mida; ++i) 
	{	
		//cerr << i << endl;
		est1 = a.consultar_iessim(i);
		est2 = b.consultar_iessim(i);
		if (est1.te_nota() and est2.te_nota()) {
			if (est1.consultar_nota() < est2.consultar_nota()) {
				a.modificar_estudiant(est2);
			}
		}
		else if (est2.te_nota()) {
			a.modificar_estudiant(est2);
		}
	}
}

int main(){
	//Creem els 2 conjunts
	Cjt_estudiants conjunt1, conjunt2;
	//Llegim l'entrada:
	conjunt1.llegir();
	conjunt2.llegir();
	//conjunt1.escriure();
	millor_nota(conjunt1, conjunt2);
	conjunt1.escriure();
}