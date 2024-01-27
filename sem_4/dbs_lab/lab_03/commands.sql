22/1/24 Lab 3, Set Operations

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

22/1/24 Lab 4, Set Operations
