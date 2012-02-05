' Alphabet Soup, Facebook Hacker Cup 2012.

DECLARE FUNCTION min% (a AS INTEGER, b AS INTEGER)

DIM t AS INTEGER
DIM i AS INTEGER
DIM j AS INTEGER
DIM recenica AS STRING
DIM ascZnak AS INTEGER
DIM br(255) AS INTEGER
DIM rezultat AS INTEGER

INPUT t
FOR i = 1 TO t
    FOR j = 1 TO 255
        br(j) = 0
    NEXT j

    INPUT recenica
    FOR j = 1 TO LEN(recenica)
        ascZnak = ASC(MID$(recenica, j, 1))
        br(ascZnak) = br(ascZnak) + 1
    NEXT j

    rezultat = min(br(ASC("H")), min(br(ASC("A")), min(br(ASC("C")) \ 2, min(br(ASC("K")), min(br(ASC("E")), min(br(ASC("R")), min(br(ASC("U")), br(ASC("P")))))))))
    PRINT "Case #"; LTRIM$(STR$(i)); ": "; LTRIM$(STR$(rezultat))
NEXT i

FUNCTION min% (a AS INTEGER, b AS INTEGER)
    IF a < b THEN min% = a ELSE min% = b
END FUNCTION

