# Write your MySQL query statement below

select name as Employee from Employee e where e.salary > (select salary from Employee e2 where e2.id = e.managerId); 