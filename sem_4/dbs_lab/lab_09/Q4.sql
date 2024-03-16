/* Q4. Based on the University Database Schema in Lab 2, write a procedure which takes
the dept-name as input parameter and lists all the students associated with the
department as well as list all the courses offered by the department. Also, write an
anonymous block with the procedure call */

CREATE OR REPLACE PROCEDURE list_stud(dname instructor.dept_name%TYPE) IS
    CURSOR stud IS SELECT name FROM student WHERE dept_name=dname;
    CURSOR cour IS SELECT title FROM course WHERE dept_name=dname;
    BEGIN
        DBMS_OUTPUT.PUT_LINE('Students:');
        FOR i IN stud LOOP
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
    list_stud('&Dept_Name');
END;
/


/* 
Students:
Tanaka

Courses:
Intro. to Biology
Genetics
Computational Biology
*/