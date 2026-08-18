SELECT department, employee, salary
FROM (
    SELECT 
        d.name AS department,
        e.name AS employee,
        e.salary,
        RANK() OVER(
            PARTITION BY e.departmentId 
            ORDER BY e.salary DESC
        ) AS renk
    FROM employee e
    JOIN department d 
        ON e.departmentId = d.id
) AS rnk
WHERE renk = 1;