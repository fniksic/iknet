' Zadatak KRIPTO, Otok Ivanic 2011.

DIM m AS INTEGER
DIM n AS INTEGER
DIM kljuc(5000) AS INTEGER
DIM sifrat AS STRING
DIM lenSifrat AS INTEGER
DIM lenStupac AS INTEGER
DIM indeks AS INTEGER
DIM linija AS STRING
DIM original AS STRING

' Ucitavamo kljuc

INPUT m
FOR i = 1 TO m
    INPUT kljuc(i)
NEXT i

' Ucitavamo sifrat

INPUT n
FOR i = 1 TO n
    INPUT linija
    sifrat = sifrat + linija
NEXT i

' Desifriranje

lenSifrat = LEN(sifrat)
lenStupac = lenSifrat / m
FOR i = 0 TO lenSifrat - 1
    indeks = (kljuc(i MOD m + 1) - 1) * lenStupac + i \ m + 1
    original = original + MID$(sifrat, indeks, 1)
NEXT i

' Ispis originalne poruke

FOR i = 0 TO n - 1
    PRINT MID$(original, i * 80 + 1, 80)
NEXT i

