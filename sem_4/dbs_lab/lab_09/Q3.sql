/* Q3. Based on the University Database Schema in Lab 2, write a Pl/Sql block of code
that lists the most popular course (highest number of students take it) for each of
the departments. It should make use of a procedure course_popular which finds
the most popular course in the given department. */


CREATE OR REPLACE PROCEDURE course_popular(dname department.dept_name%TYPE) IS
    CURSOR cour IS SELECT course_id, title FROM course WHERE course_id IN (SELECT course_id FROM (SELECT course_id, COUNT(course_id) AS course_count FROM takes NATURAL JOIN course GROUP BY dept_name, course_id HAVING dept_name=dname) WHERE ROWNUM = 1);
    BEGIN
        FOR i in cour LOOP
            DBMS_OUTPUT.PUT_LINE('Most popular course is: ' || i.course_id ||' ' || i.title);
        END LOOP;
    END;
/

DECLARE
BEGIN
    course_popular('&Dept_Name');
END;
/

/*
Most popular course is: BIO-101 Intro. to Biology
*/