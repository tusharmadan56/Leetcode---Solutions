# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT Department,Employee,Salary
FROM(
    SELECT Employee.name as Employee,
    Department.name as Department,
    Employee.salary as Salary,

    DENSE_RANK() OVER(
        Partition by Department.name
        ORDER BY Employee.salary DESC
    )AS rnk

    FROM Employee 
    LEFT JOIN Department
    ON Employee.departmentId=Department.id
) t
where rnk<=3;