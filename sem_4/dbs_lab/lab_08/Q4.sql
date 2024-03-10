/* Q4. Find all students who take the course with Course-id: CS101 and if he/ she has 
less than 30 total credit (tot-cred), deregister the student from that course. (Delete 
the entry in Takes table) */

DECLARE
    CURSOR c1 IS SELECT s.id, t.course_id FROM takes t, student s WHERE s.id=t.id AND t.course_id='CS-101' AND s.tot_cred < 30;
BEGIN
    FOR stud IN c1 LOOP
        DELETE FROM takes WHERE id=stud.id AND course_id=stud.course_id;
        DBMS_OUTPUT.PUT_LINE(c1%ROWCOUNT||' rows affected');
    END LOOP;
END;
/

