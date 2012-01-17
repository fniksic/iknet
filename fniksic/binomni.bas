' Binomni koeficijent:
' (m povrh n)
'   = m * (m - 1) * ... * (m - n + 1) / (1 * 2 * ... * n), ako je n >= 0
'   = 0, ako je n < 0

DIM m AS LONG
DIM n AS LONG
DIM rezultat AS LONG

INPUT m
INPUT n

IF n < 0 THEN
    rezultat = 0
ELSE
    ' Koristimo se svojstvom (m povrh n) = (m povrh m-n)
    IF n > m / 2 THEN
        n = m - n
    END IF

    rezultat = 1

    ' Obratite pozornost kako se i mnozenje i dijeljenje
    ' obavlja u istoj petlji. Sto nam garantira da je rezultat
    ' u svakom koraku petlje uvijek cijeli broj?
    FOR i = 1 TO n
        rezultat = rezultat * (m - i + 1) / i
    NEXT
END IF

PRINT rezultat

