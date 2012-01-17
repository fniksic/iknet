DIM m AS LONG
DIM n AS LONG
DIM cijeliDio AS LONG
DIM ostatci(1000) AS LONG
DIM znamenke(1000) AS INTEGER
DIM brojDecimala AS INTEGER
DIM pocetakPerioda AS INTEGER

INPUT m
INPUT n

brojDecimala = 0
pocetakPerioda = 0
cijeliDio = m \ n

DO
    m = m MOD n

    IF m <> 0 THEN

        ' Trazimo je li se ostatak vec ponovio
        FOR i = 1 TO brojDecimala
            IF ostatci(i) = m THEN
                pocetakPerioda = i
                EXIT FOR
            END IF
        NEXT

        ' Ako smo pronasli ponavljanje, izlazimo
        IF pocetakPerioda <> 0 THEN EXIT DO

        brojDecimala = brojDecimala + 1
        ostatci(brojDecimala) = m
        m = m * 10
        znamenke(brojDecimala) = m \ n
    END IF
LOOP WHILE m <> 0 AND brojDecimala <= 1000

' Ispis, pogledajte u helpu funkcije LTRIM$ i STR$
PRINT LTRIM$(STR$(cijeliDio));
IF brojDecimala > 0 THEN PRINT ".";
FOR i = 1 TO brojDecimala
    IF i = pocetakPerioda THEN PRINT "(";
    PRINT LTRIM$(STR$(znamenke(i)));
NEXT
IF pocetakPerioda <> 0 THEN PRINT ")" ELSE PRINT

