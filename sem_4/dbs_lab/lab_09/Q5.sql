/* Q5. Write a function to return the Square of a given number and call it from an
anonymous block. */

CREATE OR REPLACE FUNCTION sqr(n NUMBER)
RETURN NUMBER AS
BEGIN
    RETURN n*n;
END;
/

DECLARE
    num NUMBER; 
BEGIN
    num := &number;
    DBMS_OUTPUT.PUT_LINE('Square of ' || num || ' is ' || sqr(num));
END;
/

/*
Square of 5 is 25
*/