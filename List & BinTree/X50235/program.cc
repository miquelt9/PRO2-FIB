#include "BinTree.hh"
#include <iostream>
using namespace std;

bool poda_subarbre(BinTree<int>& a, int x) {
    if(a.empty()) return false;
    if(a.value() == x) {
        a = BinTree<int>  ();
        return true;
    }
    BinTree<int> left = a.left();
    BinTree<int> right = a.right();
    bool b = (poda_subarbre(left, x) or poda_subarbre(right, x));
    a = BinTree<int> (a.value(), left, right);
    return b;
}
