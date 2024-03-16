/* Q6. Based on the University Database Schema in Lab 2, write a Pl/Sql block of code
that lists the highest paid Instructor in each of the Department. It should make use
of a function department_highest which returns the highest paid Instructor for the
given branch. */

CREATE OR REPLACE FUNCTION department_highest(dname department.dept_name%TYPE)
RETURN NUMBER AS
inst_max NUMBER;
BEGIN
    SELECT MAX(salary) INTO inst_max FROM instructor WHERE dept_name=dname;
    RETURN inst_max;
END;
/

DECLARE
    CURSOR depts IS SELECT dept_name FROM department; 
BEGIN
    FOR i IN depts LOOP
        DBMS_OUTPUT.PUT_LINE('Maximum salary of ' || i.dept_name || ' is ' || department_highest(i.dept_name));
    END LOOP;
END;
/

/*
Maximum salary of Biology is 75600
Maximum salary of Comp. Sci. is 96600
Maximum salary of Elec. Eng. is 84000
Maximum salary of Finance is 94500
Maximum salary of History is 65100
Maximum salary of Music is 42000
Maximum salary of Physics is 99750
*/