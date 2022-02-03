
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const
{
  return i_maxim(primer_node);
}

T i_maxim(node_arbreNari* n) const
{
  T maxim = n->info;
  for (int i = 0; i < n->seg.size(); ++i)
  {
    if (n->seg[i] != NULL) maxim = max(maxim, i_maxim(n->seg[i]));
  }
  return maxim;
}
