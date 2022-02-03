// int i_arb_sumes(node_arbre* asum) const
// {
//   int esq = 0, dre = 0;
//   if (asum == NULL) return 0;
//   else {
//     if (asum->segE != NULL)
//     {
//       esq = i_arb_sumes(asum->segE);
//       asum->segE->info += esq;
//     }
//     if (asum->segD != NULL)
//     {
//       dre = i_arb_sumes(asum->segD);
//       asum->segD->info += dre;
//     }
//     asum->info += esq + dre;
//   }
//   return asum->info;
// }
//
// /* Pre: cert */
// /* Post: l'arbre asum és l'arbre suma del p.i. */
// void arb_sumes(Arbre<int> &asum) const
// {
//   asum.primer_node->info = i_arb_sumes(asum.primer_node);
// }

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const
{
  asum.primer_node = suma_nodes(primer_node);
}


static node_arbre* suma_nodes(node_arbre* m)
{
  node_arbre* n;
  if (m == NULL) n = NULL;
  else
  {
    n = new node_arbre;
    n->info = m->info;
    n->segE = suma_nodes(m->segE);
    if(n->segE != NULL) n->info += (n->segE)->info;
    n->segD = suma_nodes(m->segD);
    if(n->segD != NULL) n->info += (n->segD)->info;
  }
  return n;
}
