/*  Use a table StudentTable(RollNo, GPA) and populate the table with {(1, 5.8); (2, 
6.5); (3, 3.4); (4,7.8); (5, 9.5)} unless a different DB schema is explicitly specified. */

SET SERVEROUTPUT ON;

CREATE TABLE studenttable(rollno NUMBER, GPA NUMBER);
INSERT INTO  STUDENTTABLE VALUES(&ROLLNO, &GPA);


/* Q3. Input the date of issue and date of return for a book. Calculate and display the fine 
with the appropriate message using a PL/SQL block. The fine is charged as per 
the table 8.1: */

DECLARE
    v_issue_date DATE;
    v_return_date DATE;
    v_days_late NUMBER;
    v_fine NUMBER;
BEGIN
    -- Prompt the user for input
    DBMS_OUTPUT.PUT_LINE('1. Enter the issue date (YYYY-MM-DD): ');
    v_issue_date := TO_DATE('&issue\ date', 'YYYY-MM-DD'); -- User input for issue date

    DBMS_OUTPUT.PUT_LINE('Enter the return date (YYYY-MM-DD): ');
    v_return_date := TO_DATE('&2', 'YYYY-MM-DD'); -- User input for return date

    -- Calculate the number of days late
    v_days_late := v_return_date - v_issue_date;

    IF v_days_late <= 7 THEN
        v_fine := 0;
    ELSIF v_days_late <= 15 THEN
        v_fine := v_days_late * 1;
    ELSIF v_days_late <= 30 THEN
        v_fine := v_days_late * 2;    
    ELSE
        v_fine := 5;
    END IF;

    -- Display the appropriate message
    IF v_fine = 0 THEN
        DBMS_OUTPUT.PUT_LINE('No fine. Book returned on time.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Fine: ' || v_fine || ' Rupees. Book returned ' || v_days_late || ' days late.');
    END IF;
END;
/



