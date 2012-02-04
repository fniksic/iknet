' Cezarova sifra jednostavan je kriptosustav. Poruka napisana slovima
' engleske abecede sifrira se tako da se svako slovo zamijeni slovom
' koje dolazi tri mjesta dalje u abecedi (kad dodjemo do kraja abecede,
' krenemo opet ispocetka):
'
'   Abeceda: ABCDEFGHIJKLMNOPQRSTUVWXYZ
' Sifrirano: DEFGHIJKLMNOPQRSTUVWXZYABC
'
' Pomak za k=3 mjesta mozemo generalizirati na bilo koji k. Primjerice,
' za k=13 dobijemo poznatu sifru ROT13 koja ima svojstvo da sifriranjem
' sifrirane poruke dobijemo originalnu poruku.
'
'   Abeceda: ABCDEFGHIJKLMNOPQRSTUVWXYZ
' Sifrirano: NOPQRSTUVWXYZABCDEFGHIJKLM

DIM i AS INTEGER
DIM k AS INTEGER
DIM poruka AS STRING
DIM znak AS STRING
DIM ascZnak AS INTEGER

INPUT k
INPUT poruka

FOR i = 1 TO LEN(poruka)
    znak = MID$(poruka, i, 1)
    ascZnak = ASC(znak)
    IF ascZnak >= ASC("A") AND ascZnak <= ASC("Z") THEN
        ascZnak = ascZnak + (k MOD 26)
        IF ascZnak > ASC("Z") THEN ascZnak = ascZnak - 26
    ELSEIF ascZnak >= ASC("a") AND ascZnak <= ASC("z") THEN
        ascZnak = ascZnak + (k MOD 26)
        IF ascZnak > ASC("z") THEN ascZnak = ascZnak - 26
    END IF
    PRINT CHR$(ascZnak);
NEXT
PRINT

