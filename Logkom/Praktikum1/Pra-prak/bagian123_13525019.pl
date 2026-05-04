| ?- menikah(X, adinda), pria(X).

X = todoroki ? 

| ?- anak(X, P), anak(P, G), anak(G, loid).

G = adinda
P = kawakaze
X = umaru ? ;

G = levi
P = razi
X = chopper ? ;

?-anak(chopper, P), anak(P, GP), saudara(GP, S), pria(S).

GP = levi
P = razi
S = karma ? ;

GP = levi
P = razi
S = karma ? ;

| ?- pria(X), sepupu(X, S), wanita(S).

S = kawakaze
X = razi ? ;

S = kawakaze
X = razi ? ;

S = anya
X = fathur ? ;

S = anya
X = fathur ? ;

| ?- keturunan(X, faqih), saudara(X, S), \+ (saudara(X, S2), S2 \= S).

S = ariana
X = owen ? ;

S = ariana
X = owen ? ;

S = owen
X = ariana ? ;

S = owen
X = ariana ? ;

S = fathur
X = nezuko ? ;

S = fathur
X = nezuko ? ;

S = nezuko
X = fathur ? ;

S = nezuko
X = fathur ? ;

| ?- pria(X), anak(P, X), wanita(P), saudara(X, S), pria(S).

no

| ?- menikah(X, Y), usia(X, UX), usia(Y, UY), Res is abs(UX - UY), Res > 10.

Res = 12
UX = 109
UY = 97
X = faqih
Y = karina ? ;

Res = 12
UX = 97
UY = 109
X = karina
Y = faqih ? ;

Res = 18
UX = 46
UY = 64
X = tsunade
Y = owen ? ;

Res = 18
UX = 64
UY = 46
X = owen
Y = tsunade ? ;

| ?- anaksulung(X), saudara(X, _).

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = karma ? ;

X = owen ? ;

X = owen ? ;

X = owen ? ;

X = owen ? ;

X = nezuko ? ;

X = nezuko ? ;

X = nezuko ? ;

X = nezuko ? ;

| ?- usia(X, U), U > 50, menikah(X, Y), saudara(Y, _).

U = 72
X = todoroki
Y = adinda ? ;

U = 72
X = todoroki
Y = adinda ? ;

U = 72
X = todoroki
Y = adinda ? ;

U = 72
X = todoroki
Y = adinda ? ;

U = 57
X = zoro
Y = ariana ? ;

U = 57
X = zoro
Y = ariana ? ;

BAGIAN II

| ?- sumToN(5, X).

X = 15 ? 

yes

| ?- countDigits(7, X).

X = 1 ? 

(79 ms) yes

| ?- countDigits(5071, X). 

X = 4 ? 

(16 ms) yes

| ?- 
countDigits(0, X).

X = 1 ? 

yes


| ?- palSteps(56, X).

X = 1 ? 

yes
| ?- palSteps(19, X). 

X = 2 ? 

yes
| ?- 

palSteps(87, X).

X = 4 ? 

yes

| ?- digitPowerSum(321, X).

X = 32 ? 

yes
| ?-  digitPowerSum(204, X). 

X = 12 ? 

yes
| ?- 
 digitPowerSum(0, X). 

X = 0 ? 
yes

| ?- safeBinary(1, X).

X = 2 ? 

yes
| ?- safeBinary(4, X). 

X = 8 ? 

yes
| ?- 
safeBinary(5, X). 

X = 13 ? 

yes
| ?- altFactorial(4, X). 

X = -19 ? 

yes
| ?- altFactorial(5, X). 

X = 101 ? 

yes
| ?- | ?- vaultTransform(12, 2, FinalCode).

FinalCode = 48 ? 

yes
| ?- vaultTransform(105, 3, FinalCode). 

FinalCode = 732 ? 

yes
| ?- 
palPrimeCount(1, 30, X). 

X = 5 ? 

(16 ms) yes
| ?- 
palPrimeCount(100, 200, X).

X = 5 ? 

yes
| ?- towerJourney(5, 10, FinalEnergy). 

FinalEnergy = 18 ? 

yes
| ?- towerJourney(10, 20, FinalEnergy). 

FinalEnergy = 35 ? 

yes
| ?-  towerJourney(12, 1, FinalEnergy). 

FinalEnergy = 21 ? 

yes
| ?- makeDiamond(1).
1

true ? 

yes
| ?- makeDiamond(5). 
    1
  1 2 1
1 2 3 2 1
  1 2 1
    1

true ? 

yes
| ?- 

| ?- fansBarcelona(["psg", "bayern", "psg", "bayern", "real madrid", "psg"], 2, Result).

Result = [[112,115,103],[98,97,121,101,114,110],[112,115,103],[98,97,121,101,114,110],[114,101,97,108,32,109,97,100,114,105,100],[112,115,103],[112,115,103],[112,115,103]] ? 

yes
| ?- 
| ?- fansBarcelona(["real madrid", "inter", "man city", "real madrid", "liverpool"], 3, Result).

Result = [[114,101,97,108,32,109,97,100,114,105,100],[105,110,116,101,114],[109,97,110,32,99,105,116,121],[114,101,97,108,32,109,97,100,114,105,100],[108,105,118,101,114,112,111,111,108],[104,97,116,101,114],[104,97,116,101,114],[104,97,116,101,114]] ? 

(156 ms) yes
| ?- 
