/* Q5. Alter StudentTable(refer Lab No. 8 Exercise) by resetting column LetterGrade to 
F. Then write a PL/SQL block to update the table by mapping GPA to the 
corresponding letter grade for each student */

DECLARE
    CURSOR c1 IS SELECT * FROM StudentTable FOR UPDATE;
    v_letter_grade VARCHAR2(10);
    v_count NUMBER;
BEGIN
    FOR stud in c1 LOOP
        IF stud.gpa >= 9 THEN
            v_letter_grade := 'A+';
        ELSIF stud.gpa >= 8 THEN
            v_letter_grade := 'A';
        ELSIF stud.gpa >= 7 THEN
            v_letter_grade := 'B';
        ELSIF stud.gpa >= 6 THEN
            v_letter_grade := 'C';
        ELSIF stud.gpa >= 5 THEN
            v_letter_grade := 'D';
        ELSIF stud.gpa >= 4 THEN
            v_letter_grade := 'E';
        ELSE
            v_letter_grade := 'F';
        END IF;

        UPDATE StudentTable SET letter_grade=v_letter_grade WHERE CURRENT OF c1;
        v_count := c1%ROWCOUNT;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(v_count || ' rows affected.');

END;
/
