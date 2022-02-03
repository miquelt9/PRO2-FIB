bool i_buscar(node_arbreGen* n, const T& x) const
{
  if (n == NULL) return false;
  if (n->info == x) return true;
  bool found = false;
  for (int i = 0; i < n->seg.size(); ++i)
  {
    found = i_buscar(n->seg[i], x);
    if (found) return true;
  }
  return false;
}

/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const
{
  return i_buscar(this->primer_node, x);
}
