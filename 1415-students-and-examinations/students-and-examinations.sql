# Write your MySQL query statement below

with cte as (select *
from students s, subjects sub )


select cte.student_id , cte.student_name , cte.subject_name,   count(e.student_id) as 'attended_exams' from 
cte left join examinations e on cte.student_id = e.student_id and cte.subject_name = e.subject_name group by cte.student_id , cte.subject_name order by student_id,cte.subject_name;

