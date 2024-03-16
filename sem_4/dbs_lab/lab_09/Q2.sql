/* Q2. Based on the University Database Schema in Lab 2, write a procedure which takes
the dept_name as input parameter and lists all the instructors associated with the
department as well as list all the courses offered by the department. Also, write an
anonymous block with the procedure call. */

CREATE OR REPLACE PROCEDURE list_inst(dname instructor.dept_name%TYPE) IS
    CURSOR inst IS SELECT name FROM instructor WHERE dept_name=dname;
    CURSOR cour IS SELECT title FROM course WHERE dept_name=dname;
    BEGIN
        DBMS_OUTPUT.PUT_LINE('Instructors:');
        FOR i IN inst LOOP
            DBMS_OUTPUT.PUT_LINE(i.name);
        END LOOP;
        
        DBMS_OUTPUT.PUT_LINE(chr(13)||chr(10)||'Courses:');
        FOR i in cour LOOP
            DBMS_OUTPUT.PUT_LINE(i.title);
        END LOOP;
    END;
/

DECLARE
BEGIN
    list_inst('&Dept_Name');
END;
/


/* 
Instructors:
Crick

Courses:
Intro. to Biology
Genetics
Computational Biology
*/