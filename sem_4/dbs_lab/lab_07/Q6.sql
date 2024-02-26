/* Q6. Write a PL/SQL block to find the student with max. GPA without using aggregate 
function */

DECLARE
    v_roll_no StudentTable.RollNo%TYPE;
    v_gpa StudentTable.GPA%TYPE;
    v_topper StudentTable.RollNo%TYPE:=1;
    v_max_gpa StudentTable.GPA%TYPE;
BEGIN

    SELECT GPA INTO v_max_gpa
    FROM StudentTable
    WHERE RollNo = v_topper;

    FOR v_roll_no in 1..5 LOOP
        SELECT GPA INTO v_gpa
        FROM StudentTable
        WHERE RollNo = v_roll_no;

        IF v_gpa > v_max_gpa THEN
            v_max_gpa:= v_gpa;
            v_topper:= v_roll_no;
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Student with RollNo ' || v_topper || ' has the highest GPA ' || v_max_gpa);
END;
/


