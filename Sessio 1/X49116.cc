 #include <vector>
//#include "maxmin.hh"
using namespace std;

struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 {
     parint r;
     r.prim = r.seg = v[0];
     int llargada = v.size();
     for (int i = 1; i < llargada; ++i) {
         if (r.prim < v[i]) r.prim = v[i];
         if (r.seg > v[i]) r.seg = v[i];
     }
     return r;
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 {
     pair<int,int> r;
     r.first = r.second = v[0];
     int llargada = v.size();
     for (int i = 1; i < llargada; ++i) {
         if (r.first < v[i]) r.first = v[i];
         if (r.second > v[i]) r.second = v[i];
     }
     return r;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 {
     x = y = v[0];
     int llargada = v.size();
     for (int i = 1; i < llargada; ++i) {
         if (x < v[i]) x = v[i];
         if (y > v[i]) y = v[i];
     }
 }
