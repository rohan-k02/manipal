/* Q1. Create Employee table with following constraints:
Make EmpNo as Primary key.
Do not allow EmpName, Gender, Salary and Address to have null values.
Allow Gender to have one of the two values: 'M', 'F'. */

CREATE TABLE employee
(emp_no INT PRIMARY KEY,
 emp_name VARCHAR (20) NOT NULL,
 emp_address VARCHAR (20)NOT NULL,
 gender CHAR(1) CHECK (gender IN ('M', 'F')) NOT NULL,
 salary DECIMAL(10,2) NOT NULL);

 /* Q2. Create Department table with following:
Make DeptNo as Primary key
Make DeptName as candidate key */

CREATE TABLE department
(
    dept_no INT PRIMARY KEY,
    dept_name VARCHAR(100) UNIQUE NOT NULL);

/* Q3. Make DNo of Employee as foreign key which refers to DeptNo of Department. */

ALTER TABLE employee ADD dno INT,
ADD CONSTRAINT fk_employee_deptno FOREIGN KEY (dno) REFERENCES department(dept_no);

/* Q4. Insert few tuples into Employee and Department which satisfies the above constraints*/

INSERT INTO department VALUES(&dept_no, '&dept_name');

INSERT INTO employee VALUES (&emp_no, '&emp_name', '&emp_address', '&gender', &salary, &dno);

/* Q5. Try to insert few tuples into Employee and Department which violates some of the above constraints. */

INSERT INTO department VALUES(4, 'HR'); -- Output:  unique constraint (D25.SYS_C00174236) violated

INSERT INTO employee VALUES (5, 'Sky', 'JNU', 'T', 30000, 3); -- Output: check constraint (D25.SYS_C00174213) violated

/* Q6. Try to modify/delete a tuple which violates a constraint. */
DELETE FROM department WHERE dept_no=1; -- Output: integrity constraint (D25.FK_EMPLOYEE_DNO) violated - child record

/* Q7. Modify the foreign key constraint of Employee table such that whenever a department 
tuple is deleted, the employees belonging to that department will also be deleted. */

SELECT CONSTRAINT_NAME, SEARCH_CONDITION FROM user_constraints WHERE table_name = 'EMPLOYEE';


ALTER TABLE employee DROP CONSTRAINT FK_EMPLOYEE_DNO;


ALTER TABLE employee ADD CONSTRAINT fk_employee_deptno_cascade FOREIGN KEY (dno) REFERENCES department(dept_no) ON DELETE CASCADE;

/* Q8. Create a named constraint to set the default salary to 10000 and test the constraint by 
 inserting a new record. */

 ALTER TABLE EMPLOYEE MODIFY SALARY DEFAULT 10000;

 INSERT INTO EMPLOYEE (emp_no, emp_name, emp_address, gender, dno) VALUES (06, 'Ajaey', 'Kanpur', 'M', 3); -- Output: 1 row created.

 SELECT * FROM EMPLOYEE;

/*
    EMP_NO EMP_NAME             EMP_ADDRESS          G     SALARY        DNO
---------- -------------------- -------------------- - ---------- ----------
         1 Aditya               Mumbai               M      50000          1
         2 Yash                 Bhopal               M      40000          2
         3 Dhruv                Mangalore            M      60000          3
         4 John Doe             123 Main St.         M      50000          1
         6 Ajaey                Kanpur               M      10000          3

*/

/* Add date of birth column (DOB) to Employee Table. Insert appropriate DOB values 
for different employees and try the exercise problems given below: */

/* Q24. Display the birth date of all the employees in the following format:
‘DD-MON-YYYY’
‘DD-MON-YY’
‘DD-MM-YY’ */

ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY-MM-DD'

UPDATE EMPLOYEE SET DOB = ('2002-01-24');

SELECT emp_no, emp_name, emp_address, gender, salary, TO_CHAR(DOB, 'DD-MON-YYYY') AS BirthDate FROM EMPLOYEE;

/*

    EMP_NO EMP_NAME             EMP_ADDRESS          G     SALARY BIRTHDATE
---------- -------------------- -------------------- - ---------- -----------
         1 Aditya               Mumbai               M      50000 24-JAN-2002
         2 Yash                 Bhopal               M      40000 24-JAN-2002
         3 Dhruv                Mangalore            M      60000 24-JAN-2002
         4 John Doe             123 Main St.         M      50000 24-JAN-2002
         6 Ajaey                Kanpur               M      10000 24-JAN-2002
*/


SELECT emp_no, emp_name, emp_address, gender, salary, TO_CHAR(DOB, 'DD-MON-YY') AS BirthDate FROM EMPLOYEE;

/* 
    EMP_NO EMP_NAME             EMP_ADDRESS          G     SALARY BIRTHDATE
---------- -------------------- -------------------- - ---------- ---------
         1 Aditya               Mumbai               M      50000 24-JAN-02
         2 Yash                 Bhopal               M      40000 24-JAN-02
         3 Dhruv                Mangalore            M      60000 24-JAN-02
         4 John Doe             123 Main St.         M      50000 24-JAN-02
         6 Ajaey                Kanpur               M      10000 24-JAN-02
*/

SELECT emp_no, emp_name, emp_address, gender, salary, TO_CHAR(DOB, 'DD-MM-YY') AS BirthDate FROM EMPLOYEE;

/* 
    EMP_NO EMP_NAME             EMP_ADDRESS          G     SALARY BIRTHDAT
---------- -------------------- -------------------- - ---------- --------
         1 Aditya               Mumbai               M      50000 24-01-02
         2 Yash                 Bhopal               M      40000 24-01-02
         3 Dhruv                Mangalore            M      60000 24-01-02
         4 John Doe             123 Main St.         M      50000 24-01-02
         6 Ajaey                Kanpur               M      10000 24-01-02
*/

/* Q25. List the employee names and the year (fully spelled out) in which they are born */

SELECT emp_name, TO_CHAR(DOB, 'YEAR') AS Year FROM EMPLOYEE;

/*
 EMP_NAME             YEAR
-------------------- ------------------------------------------
Aditya               TWO THOUSAND TWO
Yash                 TWO THOUSAND TWO
Dhruv                TWO THOUSAND TWO
John Doe             TWO THOUSAND TWO
Ajaey                TWO THOUSAND TWO

*/

SELECT emp_name, TO_CHAR(DOB, 'Year') AS Year FROM EMPLOYEE;

/*
EMP_NAME             YEAR
-------------------- ------------------------------------------
Aditya               Two Thousand Two
Yash                 Two Thousand Two
Dhruv                Two Thousand Two
John Doe             Two Thousand Two
Ajaey                Two Thousand Two
*/

SELECT emp_name, TO_CHAR(DOB, 'year') AS Year FROM EMPLOYEE;

/*
EMP_NAME             YEAR
-------------------- ------------------------------------------
Aditya               two thousand two
Yash                 two thousand two
Dhruv                two thousand two
John Doe             two thousand two
Ajaey                two thousand two
*/






/* Q9. List all Students with names and their department names. */


SELECT NAME, DEPT_NAME FROM STUDENT;

/*
NAME                 DEPT_NAME
-------------------- --------------------
Zhang                Comp. Sci.
Shankar              Comp. Sci.
Brandt               History
Chavez               Finance
Peltier              Physics
Levy                 Physics
Williams             Comp. Sci.
Sanchez              Music
Snow                 Physics
Brown                Comp. Sci.
Aoi                  Elec. Eng.

NAME                 DEPT_NAME
-------------------- --------------------
Bourikas             Elec. Eng.
Tanaka               Biology

*/


/* Q10. List all instructors in CSE department. */

SELECT * FROM INSTRUCTOR WHERE DEPT_NAME= 'Comp. Sci.';

/*
ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
45565 Katz                 Comp. Sci.                75000
83821 Brandt               Comp. Sci.                92000
*/

/* Q11. Find the names of courses in CSE department which have 3 credits */

SELECT TITLE FROM COURSE WHERE dept_name='Comp. Sci' AND CREDITS=3;

/*
TITLE
--------------------------------------------------
Computational Biology
Robotics
Image Processing
Database System Concepts
Intro. to Digital Systems
Investment Banking
World History
Music Video Production
*/


/* Q12. For the student with ID 12345 (or any other value), show all course-id and title of all 
courses registered for by the student. */

SELECT course_id,title FROM course WHERE course_id IN (SELECT course_id FROM takes WHERE ID = 12345);

/* 
COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-190   Game Design
CS-315   Robotics
CS-347   Database System Concepts
*/

/* 13. List all the instructors whose salary is in between 40000 and 90000. */

SELECT * FROM INSTRUCTOR WHERE SALARY BETWEEN 40000 AND 90000;

/*
ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
10101 Srinivasan           Comp. Sci.                65000
12121 Wu                   Finance                   90000
15151 Mozart               Music                     40000
32343 El Said              History                   60000
33456 Gold                 Physics                   87000
45565 Katz                 Comp. Sci.                75000
58583 Califieri            History                   62000
76543 Singh                Finance                   80000
76766 Crick                Biology                   72000
98345 Kim                  Elec. Eng.                80000
*/

/* Q14. Display the IDs of all instructors who have never taught a course. */

SELECT ID FROM INSTRUCTOR WHERE ID NOT IN (SELECT ID FROM TEACHES);

/*
ID
-----
33456
58583
76543
*/

/* Q15. Find the student names, course names, and the year, for all students those who have 
attended classes in room-number 303. */

SELECT S.NAME, C.TITLE, T.YEAR FROM STUDENT S, COURSE C, TAKES T, SECTION SC WHERE S.ID=T.ID AND C.COURSE_ID=T.COURSE_ID AND ROOM_NUMBER=514 AND T.SEC_ID=SC.SEC_id AND T.YEAR=SC.YEAR AND T.SEMESTER=SC.SEMESTER;  

/*
NAME                 TITLE
-------------------- --------------------------------------------------
      YEAR
----------
Chavez               Investment Banking
      2010

Brandt               World History
      2010

Sanchez              Music Video Production
      2010


9 rows selected.

*/

/* Q16. For all students who have opted courses in 2015, find their names and course id’s 
with the attribute course title replaced by c-name. */


SELECT S.NAME, C.COURSE_ID, C.TITLE AS C_NAME FROM STUDENT S, COURSE C, TAKES T WHERE T.YEAR=2010 AND S.ID=T.ID AND C.COURSE_ID=T.COURSE_ID;  

/*
NAME                 COURSE_I C_NAME
-------------------- -------- --------------------------------------------------
Tanaka               BIO-301  Genetics
Levy                 CS-101   Intro. to Computer Science
Bourikas             CS-315   Robotics
Shankar              CS-315   Robotics
Brown                CS-319   Image Processing
Levy                 CS-319   Image Processing
Chavez               FIN-201  Investment Banking
Brandt               HIS-351  World History
Sanchez              MU-199   Music Video Production
9 rows selected.
*/

/* Q17. Find the names of all instructors whose salary is greater than the salary of at least 
one instructor of CSE department and salary replaced by inst-salary. */

SELECT NAME, SALARY as INST_SALARY FROM INSTRUCTOR WHERE SALARY > (SELECT MIN(SALARY) FROM INSTRUCTOR WHERE DEPT_NAME='Comp. Sci.');

/* 
NAME                 INST_SALARY
-------------------- -----------
Wu                         90000
Einstein                   95000
Gold                       87000
Katz                       75000
Singh                      80000
Crick                      72000
Brandt                     92000
Kim                        80000

8 rows selected.
*/

/* Q18. Find the names of all instructors whose department name includes the substring ‘ch’. */

SELECT NAME FROM INSTRUCTOR WHERE DEPT_NAME LIKE '%ng%';

/*
NAME
--------------------
Singh
*/

/* Q19. List the student names along with the length of the student names. */

SELECT NAME, LENGTH(NAME) AS NAME_LENGTH FROM STUDENT;

/*
NAME                 NAME_LENGTH
-------------------- -----------
Zhang                          5
Shankar                        7
Brandt                         6
Chavez                         6
Peltier                        7
Levy                           4
Williams                       8
Sanchez                        7
Snow                           4
Brown                          5
Aoi                            3

NAME                 NAME_LENGTH
-------------------- -----------
Bourikas                       8
Tanaka                         6

13 rows selected.
*/

/* Q20. List the department names and 3 characters from 3rd position of each department name */

SELECT DEPT_NAME, SUBSTR(DEPT_NAME, 3, 3) FROM DEPARTMENT;

/*
DEPT_NAME            SUB
-------------------- ---
Biology              olo
Comp. Sci.           mp.
Elec. Eng.           ec.
Finance              nan
History              sto
Music                sic
Physics              ysi

7 rows selected.
*/

/* Q21. List the instructor names in upper case. */
SELECT UPPER(NAME) FROM INSTRUCTOR;

/*
UPPER(NAME)
--------------------
SRINIVASAN
WU
MOZART
EINSTEIN
EL SAID
GOLD
KATZ
CALIFIERI
SINGH
CRICK
BRANDT
KIM

12 rows selected.
*/

/* Q22. Replace NULL with value1(say 0) for a column in any of the table */

SELECT NVL(END_HR,17) FROM TIME_SLOT;

/*
NVL(END_HR,17)
--------------
             8
             8
             8
             9
             9
             9
            11
            11
            11
            13
            13
            13
            11
            11
            15
            15
            16
            16
            16
            12
*/

/* Q23. Display the salary and salary/3 rounded to nearest hundred from Instructor. */

SELECT SALARY, ROUND(SALARY/3, -2) FROM INSTRUCTOR;

/*
    SALARY ROUND(SALARY/3,-2)
---------- ------------------
     65000              21700
     90000              30000
     40000              13300
     95000              31700
     60000              20000
     87000              29000
     75000              25000
     62000              20700
     80000              26700
     72000              24000
     92000              30700

    SALARY ROUND(SALARY/3,-2)
---------- ------------------
     80000              26700

12 rows selected.
*/