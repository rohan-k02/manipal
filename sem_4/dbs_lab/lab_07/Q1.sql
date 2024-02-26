/* Q1. Write a PL/SQL block to display the GPA of given student.*/ 

DECLARE
    v_roll_no StudentTable.RollNo%TYPE := 2; -- Replace with the actual RollNo
    v_gpa StudentTable.GPA%TYPE;
BEGIN
    SELECT GPA INTO v_gpa
    FROM StudentTable
    WHERE RollNo = v_roll_no;

    DBMS_OUTPUT.PUT_LINE('Student with RollNo ' || v_roll_no || ' has a GPA of ' || v_gpa);
END;
/