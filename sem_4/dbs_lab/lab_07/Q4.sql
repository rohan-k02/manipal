/* Q4. Write a PL/SQL block to print the letter grade of all the students(RollNo: 1 - 5). */

DECLARE
    v_roll_no StudentTable.RollNo%TYPE:=0;
    v_gpa StudentTable.GPA%TYPE;
    v_letter_grade VARCHAR2(10);
BEGIN
    LOOP
        v_roll_no:= v_roll_no+1;

        IF v_roll_no > 5 THEN EXIT;
        END IF;
        SELECT GPA INTO v_gpa
        FROM StudentTable
        WHERE RollNo = v_roll_no;

        -- Determine the letter grade based on GPA
        IF v_gpa >= 9 THEN
            v_letter_grade := 'A+';
        ELSIF v_gpa >= 8 THEN
            v_letter_grade := 'A';
        ELSIF v_gpa >= 7 THEN
            v_letter_grade := 'B';
        ELSIF v_gpa >= 6 THEN
            v_letter_grade := 'C';
        ELSIF v_gpa >= 5 THEN
            v_letter_grade := 'D';
        ELSIF v_gpa >= 4 THEN
            v_letter_grade := 'E';
        ELSE
            v_letter_grade := 'F';
        END IF;

        DBMS_OUTPUT.PUT_LINE('Student with RollNo ' || v_roll_no || ' has a letter grade of ' || v_letter_grade);
    END LOOP;
END;
/