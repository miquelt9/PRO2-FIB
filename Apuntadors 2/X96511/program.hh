
int i_freq(node_arbreGen* n, const T& x) const
{
  int aparicions = 0;
  if (n == NULL) return 0;
  if (n->info == x) ++aparicions;
  for(int i = 0; i < n->seg.size(); ++i)
  {
    aparicions += i_freq(n->seg[i], x);
  }
  return aparicions;
}

/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const
{
  return i_freq(primer_node, x);
}
