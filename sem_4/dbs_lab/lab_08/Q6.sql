/* Q6. Write a PL/SQL block to print the list of Instructors teaching a specified course. */

DECLARE
        CURSOR c1(c_id course.course_id%TYPE) IS SELECT i.name FROM instructor i, teaches t WHERE i.ID=t.ID AND t.course_id = c_id;
BEGIN
    FOR cour in c1('CS-101') LOOP
        DBMS_OUTPUT.PUT_LINE(cour.name);
    END LOOP;
END;
/

