/* Q1. The HRD manager has decided to raise the salary of all the Instructors in a given 
department number by 5%. Whenever, any such raise is given to the instructor, a 
record for the same is maintained in the salary_raise table. It includes the Instuctor 
Id, the date when the raise was given and the actual raise amount. Write a PL/SQL 
block to update the salary of each Instructor and insert a record in the salary_raise 
table.
salary_raise(Instructor_Id, Raise_date, Raise_amt */


DECLARE
    CURSOR c1 IS SELECT * FROM INSTRUCTOR FOR UPDATE;
    v_final_salary INSTRUCTOR.SALARY%TYPE;
    v_raise_amt INSTRUCTOR.SALARY%TYPE;
    v_raise_date DATE;
    rate CONSTANT NUMBER := 5;
BEGIN
    FOR inst in c1
    LOOP
        v_raise_amt := inst.salary*rate/100;
        v_final_salary := inst.salary + v_raise_amt;
        UPDATE instructor SET salary = v_final_salary WHERE CURRENT OF c1;
        v_raise_date := TO_DATE('&v_raise_date', 'YYYY-MM-DD');
        INSERT INTO salary_raise VALUES(inst.id, v_raise_date, v_raise_amt);
        DBMS_OUTPUT.PUT_LINE('Raised salary of ID ' ||  inst.id || ' by ' || v_raise_amt);
    END LOOP;
END;
/


/*
Raised salary of ID 10101 by 3250
Raised salary of ID 12121 by 4500
Raised salary of ID 15151 by 2000
Raised salary of ID 22222 by 4750
Raised salary of ID 32343 by 3000
Raised salary of ID 33456 by 4350
Raised salary of ID 45565 by 3750
Raised salary of ID 58583 by 3100
Raised salary of ID 76543 by 4000
Raised salary of ID 76766 by 3600
Raised salary of ID 83821 by 4600
Raised salary of ID 98345 by 4000
*/
