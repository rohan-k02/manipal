/* Q2. Write a PL/SQL block that will display the ID, name, dept_name and tot_cred of 
the first 10 students with lowest total credit. */

DECLARE
    CURSOR c1 IS SELECT * FROM student ORDER BY tot_cred ASC;
BEGIN
    FOR stud in c1
    LOOP
        IF c1%ROWCOUNT > 10 THEN EXIT;
        END IF;
        DBMS_OUTPUT.PUT_LINE('ID: '|| stud.id || CHR(9) || 'Name: ' || stud.name || CHR(9) || 'Department Name: ' || stud.dept_name || CHR(9) || 'Total Credits: ' || stud.tot_cred);        
    END LOOP;
END;
/

/*
ID: 70557       Name: Snow      Department Name: Physics        Total Credits: 0
ID: 12345       Name: Shankar   Department Name: Comp. Sci.     Total Credits: 32
ID: 55739       Name: Sanchez   Department Name: Music  Total Credits: 38
ID: 45678       Name: Levy      Department Name: Physics        Total Credits: 46
ID: 54321       Name: Williams  Department Name: Comp. Sci.     Total Credits: 54
ID: 44553       Name: Peltier   Department Name: Physics        Total Credits: 56
ID: 76543       Name: Brown     Department Name: Comp. Sci.     Total Credits: 58
ID: 76653       Name: Aoi       Department Name: Elec. Eng.     Total Credits: 60
ID: 19991       Name: Brandt    Department Name: History        Total Credits: 80
ID: 98765       Name: Bourikas  Department Name: Elec. Eng.     Total Credits: 98
*/