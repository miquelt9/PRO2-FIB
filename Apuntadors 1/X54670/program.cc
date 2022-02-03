/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
void concat(Cua &c)
{
  while (c.mida() != 0)
  {
    int p = c.primer();
    demanar_torn(p);
    c.avancar();
  }
}
