/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a) {
    if (m == NULL) {
        u = a = NULL;
        return NULL;
    }

    node_llista *first, *aux;
    first = aux = new node_llista;
    aux->info = m->info;
    aux->ant = NULL;
    m = m->seg;

    while (m != NULL) {
        node_llista* aux2 = new node_llista;
        aux2->info = m->info;
        aux->seg = aux2;
        aux2->ant = aux;

        if (oact == m) a = aux2;
        aux = aux2;
        m = m->seg;
    }
    u = aux;
    return first;
}

/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) {
    if (this != &original) {
        longitud = original.longitud;
        esborra_node_llista(primer_node);
        primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
    }
    return *this;
}
