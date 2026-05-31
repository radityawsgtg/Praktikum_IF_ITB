/* FAKTA: Data orang tua */
parent(budi, andi).
parent(andi, sita).
parent(budi, rina).

/* ATURAN REKURSIF: Ancestor */
/* Basis: X adalah leluhur Y jika X adalah orang tua langsung Y */
ancestor(X, Y) :- 
    parent(X, Y).

/* Rekurens: X adalah leluhur Y jika X orang tua Z, dan Z adalah leluhur Y */
ancestor(X, Y) :- 
    parent(X, Z), 
    ancestor(Z, Y).