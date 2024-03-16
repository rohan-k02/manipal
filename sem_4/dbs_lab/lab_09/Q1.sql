/* Q1. Write a procedure to display a message “Good Day to You”. */

CREATE OR REPLACE PROCEDURE msg IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('Good Day to You');
    END;
/

DECLARE
BEGIN
    msg;
END;
/

/*
Good Day to You
*/