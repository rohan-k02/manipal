/*  Use a table StudentTable(RollNo, GPA) and populate the table with {(1, 5.8); (2, 
6.5); (3, 3.4); (4,7.8); (5, 9.5)} unless a different DB schema is explicitly specified. */

SET SERVEROUTPUT ON;

CREATE TABLE studenttable(rollno NUMBER, GPA NUMBER);
-- INSERT INTO  STUDENTTABLE VALUES(&ROLLNO, &GPA);

INSERT ALL
INTO studenttable(rollno, GPA) VALUES(1, 5.8)
INTO studenttable(rollno, GPA) VALUES(2, 6.5)
INTO studenttable(rollno, GPA) VALUES (3, 3.4)
INTO studenttable(rollno, GPA) VALUES(4, 7.8)
INTO studenttable(rollno, GPA) VALUES(5, 9.5)
SELECT 1 FROM DUAL;

