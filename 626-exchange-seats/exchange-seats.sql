# Write your MySQL query statement below


select id , ifnull(if(id%2 , lead(student) over(order by id) , lag(student) over(order by id)),student) as student from seat;