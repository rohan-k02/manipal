/* Q8. Based on the University database schema, write a PL/SQL block to display the details of the Instructor whose name is supplied by the user.
Use exceptions to show appropriate error message for the following cases:
a. Multiple instructors with the same name
b. No instructor for the given name */

DECLARE
    v_name instructor.name%TYPE;

BEGIN
    SELECT name INTO v_name
    FROM instructor
    WHERE name='&name';

    DBMS_OUTPUT.PUT_LINE(v_name||' Found');

EXCEPTION
    WHEN no_data_found THEN dbms_output.put_line('No Rows Found');
    WHEN dup_val_on_index THEN dbms_output.put_line('Multiple Rows Found');
end;
/