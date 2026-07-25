# Write your MySQL query statement below
#select salary as SecondHighestSalary from Employee order by salary limit 1,1;

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary = (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1, 1
);