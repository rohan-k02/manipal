/* Q1. Find courses that ran in Fall 2009 or in Spring 2010 */
(SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Fall' and T.YEAR='2009' AND C.COURSE_ID=T.COURSE_ID) UNION (SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Spring' AND  T.YEAR='2010' AND C.COURSE_ID=t.COURSE_ID);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-315   Robotics
CS-319   Image Processing
CS-347   Database System Concepts
FIN-201  Investment Banking
HIS-351  World History
MU-199   Music Video Production
PHY-101  Physical Principles

8 rows selected.
*/


/* Q2. Find courses that ran in Fall 2009 and in spring 2010 */
(SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Fall' and T.YEAR='2009' AND C.COURSE_ID=T.COURSE_ID) INTERSECT (SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Spring' AND  T.YEAR='2010' AND C.COURSE_ID=t.COURSE_ID);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/


/* Q3. Find courses that ran in Fall 2009 but not in Spring 2010 */
(SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Fall' and T.YEAR='2009' AND C.COURSE_ID=T.COURSE_ID) MINUS (SELECT T.COURSE_ID, C.TITLE FROM TAKES T, COURSE C WHERE T.SEMESTER='Spring' AND  T.YEAR='2010' AND C.COURSE_ID=t.COURSE_ID);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-347   Database System Concepts
PHY-101  Physical Principles
*/


/* Q4. Find the name of the course for which none of the students registered.*/
SELECT TITLE FROM COURSE
MINUS
SELECT C.TITLE FROM COURSE C, TAKES T WHERE T.COURSE_ID = C.COURSE_ID;

/*
TITLE
--------------------------------------------------
Computational Biology
*/

/* 
Nested Subqueries
Set Membership (in / not in):
*/

/* Q5. Find courses offered in Fall 2009 and in Spring 2010. */
SELECT COURSE_ID, TITLE FROM COURSE WHERE COURSE_ID IN (SELECT C.COURSE_ID FROM TAKES T, COURSE C WHERE T.SEMESTER='Fall' and T.YEAR='2009' AND C.COURSE_ID=T.COURSE_ID) AND COURSE_ID IN (SELECT T.COURSE_ID FROM TAKES T, COURSE C WHERE T.SEMESTER='Spring' AND  T.YEAR='2010' AND C.COURSE_ID=T.COURSE_ID);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/

/* Q6. Find the total number of students who have taken course taught by the instructor with ID 10101 */
SELECT COUNT(ID) FROM TAKES WHERE COURSE_ID IN (SELECT COURSE_ID FROM TEACHES WHERE ID=10101);

/*
 COUNT(ID)
----------
        11
*/

/* Q7. Find courses offered in Fall 2009 but not in Spring 2010. */
SELECT COURSE_ID, TITLE FROM COURSE WHERE COURSE_ID IN (SELECT C.COURSE_ID FROM TAKES T, COURSE C WHERE T.SEMESTER='Fall' and T.YEAR='2009' AND C.COURSE_ID=T.COURSE_ID) AND COURSE_ID NOT IN (SELECT T.COURSE_ID FROM TAKES T, COURSE C WHERE T.SEMESTER='Spring' AND  T.YEAR='2010' AND C.COURSE_ID=T.COURSE_ID);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-347   Database System Concepts
PHY-101  Physical Principles
*/

/* Q8. Find the names of all students whose name is same as the instructor’s name. */
SELECT name FROM student WHERE name IN (SELECT name FROM instructor);

/*
NAME
--------------------
Brandt
*/

/*
Set Comparison (>=some/all)
*/

/* Q9. Find names of instructors with salary greater than that of some (at least one) instructor in the Biology department. */
SELECT name FROM instructor WHERE salary > SOME(SELECT salary FROM instructor WHERE dept_name='Biology');

/*
NAME
--------------------
Einstein
Brandt
Wu
Gold
Kim
Singh
Katz

7 rows selected.
*/

/* Q10. Find the names of all instructors whose salary is greater than the salary of all instructors in the Biology department. */
SELECT name FROM instructor WHERE salary > ALL (SELECT salary FROM instructor WHERE dept_name='Biology';);

/*
NAME
--------------------
Einstein
Brandt
Wu
Gold
Kim
Singh
Katz

7 rows selected.
*/

/* Q11. Find the departments that have the highest average salary. */
SELECT dept_name, AVG(salary) FROM instructor GROUP BY dept_name ORDER BY AVG(salary) DESC;

/*
DEPT_NAME            AVG(SALARY)
-------------------- -----------
Physics                    91000
Finance                    85000
Elec. Eng.                 80000
Comp. Sci.            77333.3333
Biology                    72000
History                    61000
Music                      40000

7 rows selected.
*/

/* Q12. Find the names of those departments whose budget is lesser than the average salary of all instructors. */
SELECT dept_name FROM department WHERE budget < ALL(SELECT AVG(salary) FROM instructor);

/*
DEPT_NAME
--------------------
History
Physics
*/

/*
Test for Empty Relations (exists/ not exists)
*/

/* Q13. Find all courses taught in both the Fall 2009 semester and in the Spring 2010 semester. */
SELECT course_id, title FROM course WHERE EXISTS (SELECT course_id FROM section 
WHERE semester = 'Fall'  AND year = 2009 AND course.course_id = section.course_id)
INTERSECT
SELECT course_id, title FROM course WHERE EXISTS (SELECT course_id FROM section 
WHERE semester = 'Spring' AND year = 2010 AND course.course_id = section.course_id);

/*
COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
*/

/* Q14. Find all students who have taken all courses offered in the Biology department. */
SELECT id, name FROM student WHERE EXISTS
(SELECT t.ID FROM takes t, course c WHERE 
t.course_id = c.course_id AND c.dept_name = 'Biology' AND student.ID = t.ID);

/*
ID    NAME
----- --------------------
98988 Tanaka
*/

/*
Test for Absence of Duplicate Tuples
*/

/* Q15. Find all courses that were offered at most once in 2009. */
SELECT course_id, title FROM course WHERE course_id IN 
(SELECT course_id FROM section WHERE year = 2009 
GROUP BY course_id HAVING COUNT(course_id) < 2);


/*
COURSE_I TITLE
-------- --------------------------------------------------
BIO-101  Intro. to Biology
CS-101   Intro. to Computer Science
CS-347   Database System Concepts
EE-181   Intro. to Digital Systems
PHY-101  Physical Principles
*/

/* Q16. Find all the students who have opted at least two courses offered by CSE department. */
SELECT id, name FROM student WHERE ID IN
(SELECT t.id FROM takes t, course c 
WHERE t.course_id = c.course_id AND c.dept_name = 'Comp. Sci.' GROUP BY t.id HAVING COUNT(t.id) > 1);

/*
ID    NAME
----- --------------------
00128 Zhang
12345 Shankar
45678 Levy
54321 Williams
76543 Brown
98765 Bourikas

6 rows selected.
*/

/*
Subqueries in the From Clause
*/

/* Q17. Find the average instructors salary of those departments where the average salary is greater than 42000 */
SELECT dept_name, AVG(salary) FROM instructor GROUP BY dept_name HAVING AVG(salary) > 42000;

/*
DEPT_NAME            AVG(SALARY)
-------------------- -----------
Comp. Sci.            77333.3333
Finance                    85000
Physics                    91000
History                    61000
Biology                    72000
Elec. Eng.                 80000
*/


/*
Views
*/

/* Q18. Create a view all_courses consisting of course sections offered by Physics 
department in the Fall 2009, with the building and room number of each section. */
CREATE VIEW all_courses AS
SELECT sc.sec_id, sc.building, sc.room_number FROM section sc, course c
WHERE c.dept_name='Physics' AND sc.year=2009 AND sc.semester='Fall' AND sc.course_id=c.course_id;

/* View created. */

/* Q19. Select all the courses from all_courses view. */
SELECT * FROM ALL_COURSES;

/*
SEC_ID   BUILDING        ROOM_NU
-------- --------------- -------
1        Watson          100
*/

/* Q20. Create a view department_total_salary consisting of department name and total 
salary of that department. */
CREATE VIEW department_total_salary AS
SELECT dept_name, SUM(salary) AS total_salary
FROM instructor
GROUP BY dept_name
ORDER BY SUM(salary) DESC;

/*
DEPT_NAME            TOTAL_SALARY
-------------------- ------------
Comp. Sci.                 232000
Finance                    170000
Music                       40000
Physics                    182000
History                    122000
Biology                     72000
Elec. Eng.                  80000

7 rows selected.
*/