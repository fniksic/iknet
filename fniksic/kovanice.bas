' Isplata novcanog iznosa minimalnim brojem kovanica
' od 10, 5, 2 i 1 kn. Ovo je primjer greedy (pohlepnog)
' algoritma. Uvjerite se da ovakvim pristupom necemo
' dobiti najbolje rjesenje ako uzmemo kovanice od 10, 8, 5
' i 1 kn, npr. za isplatu iznosa od 13 kn. Zasto je
' rezultat za 10, 5, 2 i 1 kn ipak dobar?

CONST brojKovanica = 4

DIM iznos AS LONG
DIM potrebno AS LONG
DIM kovanice(brojKovanica) AS LONG

' Pokusaj postaviti ove vrijednosti na 10, 8, 5, 1
kovanice(1) = 10
kovanice(2) = 5
kovanice(3) = 2
kovanice(4) = 1

INPUT iznos

FOR i = 1 TO brojKovanica
    potrebno = iznos \ kovanice(i)
    iznos = iznos MOD kovanice(i)
    PRINT "Potrebno je "; potrebno; " kovanica od "; kovanice(i); " kn."
NEXT

