/* Q2. Write a PL/SQL block to display the letter grade(0-4: F; 4-5: E; 5-6: D; 6-7: C; 
7-8: B; 8-9: A; 9-10: A+} of given student. */

DECLARE
    v_roll_no StudentTable.RollNo%TYPE := 5; -- Replace with the actual RollNo
    v_gpa StudentTable.GPA%TYPE;
    v_letter_grade VARCHAR2(10);
BEGIN
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
END;
/
