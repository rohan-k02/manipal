-- Q1. Create a table employee with (emp_no, emp_name, emp_address)
CREATE TABLE EMPLOYEE
(EMP_NO INTEGER PRIMARY KEY,
 EMP_NAME VARCHAR (20),
 EMP_ADDRESS VARCHAR (20));

-- Q2. Insert five employees information.
INSERT INTO EMPLOYEE (EMP_NO, EMP_NAME, EMP_ADDRESS)
VALUES (1, 'John Doe', '123 Main St');

INSERT INTO EMPLOYEE (EMP_NO, EMP_NAME, EMP_ADDRESS)
VALUES (2, 'Jane Smith', '456 Park Ave');

INSERT INTO EMPLOYEE (EMP_NO, EMP_NAME, EMP_ADDRESS)
VALUES (3, 'Robert Johnson', '789 Broadway');

INSERT INTO EMPLOYEE (EMP_NO, EMP_NAME, EMP_ADDRESS)
VALUES (4, 'Emily Davis', '321 Elm St');

INSERT INTO EMPLOYEE (EMP_NO, EMP_NAME, EMP_ADDRESS)
VALUES (5, 'David Brown', '654 Oak Ave');

-- Q3. Display names of all employees.
SELECT EMP_NAME FROM EMPLOYEE;

-- Q4. Display all the employees from ‘MANIPAL’.
SELECT * FROM EMPLOYEE WHERE EMP_ADDRESS = 'MANIPAL';

-- Q5. Add a column named salary to employee table.
ALTER TABLE EMPLOYEE ADD SALARY INTEGER;

-- Q6. Assign the salary for all employees.
UPDATE EMPLOYEE SET SALARY=50000;

-- Q7. View the structure of the table employee using describe.
DESC EMPLOYEE;

-- Q8. Delete all the employees from ‘MANGALORE’
DELETE FROM EMPLOYEE WHERE EMP_ADDRESS = 'MANGALORE';

-- Q9. Rename employee as employee1.
RENAME EMPLOYEE TO EMPLOYEE1;

-- Q10. Drop the table employee1.
DROP EMPLOYEE1;