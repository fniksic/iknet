DECLARE SUB ispis ()
DECLARE SUB nextPerm ()

' SHARED varijable su vidljive iz svih funkcija i procedura
DIM SHARED a(20) AS INTEGER
DIM SHARED n AS INTEGER
DIM SHARED kraj AS INTEGER

DIM v AS INTEGER
DIM i AS INTEGER
DIM j AS INTEGER
DIM rijec AS STRING

INPUT rijec

' Prvo rijec pretvaramo u array a odgovarajucih ASCII vrijednosti.
' Usput obavljamo uzlazno sortiranje algoritmom Insertion sort.

n = LEN(rijec)
FOR i = 1 TO n
    v = ASC(MID$(rijec, i, 1))
    FOR j = i - 1 TO 1 STEP -1
        IF a(j) > v THEN
            SWAP a(j), a(j + 1)
        ELSE
            EXIT FOR
        END IF
    NEXT j
    a(j + 1) = v
NEXT i

' Ovo ce biti korisno kasnije.
a(n + 1) = 0

' Procedura nextPerm postavlja kraj = 1 kad dodje do zadnje permutacije.
kraj = 0
WHILE kraj = 0
    CALL ispis
    CALL nextPerm
WEND

SUB ispis
    DIM i AS INTEGER

    FOR i = 1 TO n
        PRINT CHR$(a(i));
    NEXT i
    PRINT
END SUB

SUB nextPerm
    DIM i AS INTEGER
    DIM k AS INTEGER
   
    ' Krecuci s kraja niza trazimo prvo mjesto gdje niz pada.
    ' Ako je niz cijelo vrijeme uzlazan gledajuci s kraja,
    ' tj. silazan gledajuci s pocetka, stigli smo do zadnje
    ' permutacije; zavrsavamo s kraj = 1.

    kraj = 1
    FOR k = n - 1 TO 1 STEP -1
        IF a(k) < a(k + 1) THEN
            kraj = 0
            EXIT FOR
        END IF
    NEXT k

    IF kraj = 0 THEN
        ' a(k) mijenjamo s prvim strogo vecim od njega iz "repa".
        ' Uzimamo u obzir cinjenicu da je "rep" sortiran silazno.
        ' Tu koristimo postavljeni a(n + 1) = 0 kako bi kod bio
        ' elegantniji.
        FOR i = k + 2 TO n + 1
            IF a(k) >= a(i) THEN
                SWAP a(k), a(i - 1)
                EXIT FOR
            END IF
        NEXT i

        ' "Rep" je i dalje sortiran silazno pa ga sortiramo uzlazno.
        FOR i = k + 1 TO (n + k + 1) \ 2
            SWAP a(i), a(n - i + k + 1)
        NEXT i
    END IF
END SUB

