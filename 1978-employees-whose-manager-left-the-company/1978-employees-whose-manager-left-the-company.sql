# Write your MySQL query statement below
#select manager_id from Employees where manger_id NOT IN(select employee_id from Employees) 1

select employee_id from Employees where salary<30000 and manager_id IN(
select e1.manager_id from employees e1 LEFT join employees e2 on e1.manager_id=e2.employee_id where e2.employee_id IS NULL and e1.manager_id IS NOT NULL) order by employee_id;