/* Bagian I */
/* Deklarasi Fakta */

% Fakta Pria
pria(panji).
pria(qika).
pria(shelby).
pria(rifia).
pria(barok).
pria(aqua).
pria(eriq).
pria(francesco).
pria(mauang).
pria(jamet).

% Fakta Wanita
wanita(frieren).
wanita(mary).
wanita(yennefer).
wanita(myers).
wanita(gizelle).
wanita(eve).
wanita(rhiannon).
wanita(roxy).
wanita(ruby).
wanita(aihoshino).
wanita(suzy).

% Fakta Usia
usia(panji, 78).
usia(frieren, 75).
usia(qika, 55).
usia(mary, 51).
usia(myers, 40).
usia(shelby, 25).
usia(yennefer, 30).
usia(rifia, 35).
usia(gizelle, 20).
usia(eve, 10).
usia(rhiannon, 5).
usia(barok, 75).
usia(roxy, 73).
usia(aqua, 53).
usia(ruby, 48).
usia(eriq, 50).
usia(aihoshino, 32).
usia(francesco, 23).
usia(suzy, 23).
usia(mauang, 15).
usia(jamet, 3).

% Fakta Menikah (Dibuat dua arah agar mempermudah logika)
menikah(panji, frieren).
menikah(frieren, panji).
menikah(qika, mary).
menikah(mary, qika).
menikah(qika, myers).
menikah(myers, qika).
menikah(rifia, aqua).
menikah(aqua, rifia).
menikah(barok, roxy).
menikah(roxy, barok).
menikah(ruby, eriq).
menikah(eriq, ruby).
menikah(francesco, suzy).
menikah(suzy, francesco).

% Fakta Anak (anak(Anak, OrangTua))
anak(qika, panji).
anak(qika, frieren).

anak(shelby, qika).
anak(shelby, mary).
anak(yennefer, qika).
anak(yennefer, mary).
anak(rifia, qika).
anak(rifia, mary).

anak(gizelle, qika).
anak(gizelle, myers).

anak(rhiannon, yennefer).
anak(eve, yennefer).

anak(aihoshino, rifia).
anak(aihoshino, aqua).
anak(mauang, rifia).
anak(mauang, aqua).

anak(aqua, barok).
anak(aqua, roxy).
anak(ruby, barok).
anak(ruby, roxy).

anak(francesco, ruby).
anak(francesco, eriq).

anak(jamet, francesco).
anak(jamet, suzy).

saudara(X,Y):-
    anak(X,Z),
    anak(Y,Z),
    Y \=Z.
saudaratiri(X,Y):-
    anak(X,Ortusama),
    anak(Y,Orutsama),
    anak(X,OrtulainX),
    anak(X,OrtulainY),
    OrtulainX \= OrtulainY,
    Ortusama \= OrtulainY,
    Ortusama \= OrtulainX,
    X \= Y.
kakak(X,Y):-
    saudara(X, Y), 
    usia(X, UsiaX), 
    usia(Y, UsiaY), 
    UsiaX > UsiaY.

keponakan(X, Y) :- 
    anak(X, Z), 
    saudara(Z, Y).
mertua(X, Y) :- 
    anak(Z, X), 
    menikah(Z, Y).
nenek(X, Y) :- 
    wanita(X), 
    anak(Z, X), 
    anak(Y, Z)
keturunan(X, Y) :- 
    anak(X, Y).
keturunan(X, Y) :- 
    anak(X, Z), 
    keturunan(Z, Y).

lajang(X) :- 
    (pria(X) ; wanita(X)), 
    \+ menikah(X, _).

anakbungsu(X) :- 
    anak(X, Ortu), 
    \+ (anak(Y, Ortu), X \= Y, usia(X, UsiaX), usia(Y, UsiaY), UsiaX > UsiaY).

anaksulung(X) :- 
    anak(X, Ortu), 
    \+ (anak(Y, Ortu), X \= Y, usia(X, UsiaX), usia(Y, UsiaY), UsiaX < UsiaY).

yatimpiatu(X) :- 
    (pria(X) ; wanita(X)), 
    \+ anak(X, _).