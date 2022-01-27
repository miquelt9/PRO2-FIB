#include "BinTreeIOEst.hh"
#include "Estudiant.hh"

void read_bintree_est(BinTree<Estudiant>& a)
{
  Estudiant est;
  est.llegir();
  if(est.consultar_DNI() != 0 or est.consultar_nota() != 0)
  {
    BinTree<Estudiant> l;
    read_bintree_est(l);
    BinTree<Estudiant> r;
    read_bintree_est(r);
    a = BinTree<Estudiant> (est,l,r);
  }
}

void write_bintree_est(const BinTree<Estudiant>& a)
{
	if (not a.empty())
  {
		write_bintree_est(a.left());
		a.value().escriure();
		write_bintree_est(a.right());
  }
}
