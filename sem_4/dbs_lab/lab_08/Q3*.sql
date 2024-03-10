/* Q3. Print the Course details and the total number of students registered for each course 
along with the course details - (Course-id, title, dept-name, credits, 
instructor_name, building, room-number, time-slot-id, tot_student_no ) */

DECLARE
    CURSOR C1 IS (SELECT c.course_id, c.title, c.dept_name, c.credits, i.name, s.building, s.room_number, s.time_slot_id FROM course c, takes t, instructor i, section s WHERE c.course_id=s.course_id AND i.id=t.id AND t.sec_id=s.sec_id) UNION (SELECT COUNT FROM );

BEGIN
    FOR cour in c1 LOOP
        DBMS_OUTPUT.PUT_LINE(cour.course_id||'|'||cour.title||'|'||cour.dept_name||'|'||cour.credits||'|'||cour.name||'|'||cour.building||'|'||cour.room_number||'|'||cour.time_slot_id);
        DBMS_OUTPUT.PUT_LINE(c1%ROWCOUNT);
    END LOOP;
END;
/