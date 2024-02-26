/* Q5. Alter StudentTable by appending an additional column LetterGrade Varchar2(2). 
Then write a PL/SQL block to update the table with letter grade of each student. 

ALTER TABLE StudentTable ADD (LetterGrade VARCHAR2(2));
*/

DECLARE
    v_roll_no StudentTable.RollNo%TYPE:=1;
    v_gpa StudentTable.GPA%TYPE;
    v_letter_grade VARCHAR2(10);    
    v_letter_grade2 VARCHAR2(10);

BEGIN
    WHILE v_roll_no < 6
    LOOP
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

        UPDATE StudentTable SET LetterGrade=v_letter_grade WHERE RollNo=v_roll_no;

        SELECT LetterGrade INTO v_letter_grade2
        FROM StudentTable
        WHERE RollNo = v_roll_no;  
              
        DBMS_OUTPUT.PUT_LINE('Student with RollNo ' || v_roll_no || ' has a letter grade of ' || v_letter_grade2);
        v_roll_no:=v_roll_no+1;
    END LOOP;
END;
/