# Write your MySQL query statement below
select Max(salary) SecondHighestSalary from Employee where salary < (select Max(salary) from Employee);