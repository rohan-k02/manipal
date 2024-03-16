/* Q8. Write a PL/SQL procedure to return simple and compound interest (OUT
parameters) along with the Total Sum (IN OUT) i.e. Sum of Principle and Interest
taking as input the principle, rate of interest and number of years (IN parameters).
Call this procedure from an anonymous block. */

CREATE OR REPLACE PROCEDURE  interest(principal IN NUMBER,rate IN NUMBER,years IN NUMBER, times IN NUMBER, si OUT NUMERIC, ci OUT NUMERIC, tot_sum IN OUT NUMERIC) AS
BEGIN
    si := (principal*rate*years)/100;
    ci := principal*power((1+rate/times),times*years);
    tot_sum := principal + si + ci;
END;
/

DECLARE
si NUMERIC(10,2);
CI NUMERIC(10,2);
tot_sum NUMERIC(10,2);
begin
	interest(10000,5,2,3,si,ci,tot_sum);
	dbms_output.put_line('Simple Interest: ' || si);
	dbms_output.put_line('Compound Interest: '|| ci);
	dbms_output.put_line('Tot Sum '||tot_sum);
end;,  
/