/* Q7. Based on the University Database Schema in Lab 2, create a package to include
the following:
a) A named procedure to list the instructor_names of given department
b) A function which returns the max salary for the given department
c) Write a PL/SQL block to demonstrate the usage of above package components */

CREATE OR REPLACE PACKAGE q7 AS 
PROCEDURE dept_inst(dname VARCHAR);

FUNCTION dept_highest(dname VARCHAR)
RETURN NUMBER;
END q7;
/

CREATE OR REPLACE PACKAGE BODY q7 AS 

PROCEDURE dept_inst(dname VARCHAR) IS
CURSOR inst IS SELECT name FROM instructor WHERE dept_name=dname;
BEGIN
        DBMS_OUTPUT.PUT_LINE(chr(13)||chr(10)||'Instructors for ' || dname);
        FOR i IN inst LOOP
            DBMS_OUTPUT.PUT_LINE(i.name);
        END LOOP;
END;

FUNCTION dept_highest(dname VARCHAR)
RETURN NUMBER AS
inst_max NUMBER;
BEGIN
    SELECT MAX(salary) INTO inst_max FROM instructor WHERE dept_name=dname;
    RETURN inst_max;
END;
END q7;
/

DECLARE
    CURSOR depts IS SELECT dept_name FROM department; 
BEGIN
    FOR i IN depts LOOP
        q7.dept_inst(i.dept_name);
        DBMS_OUTPUT.PUT_LINE('Maximum salary of ' || i.dept_name || ' is ' || q7.dept_highest(i.dept_name));
    END LOOP;
END;
/
