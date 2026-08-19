# Write your MySQL query statement below


with cte as (select a1.machine_id,a1.process_id,round(a2.timestamp - a1.timestamp , 3) as diff from activity a1 join activity a2 on a1.machine_id=a2.machine_id and a2.process_id=a1.process_id where a1.activity_type = 'start' and a2.activity_type = 'end')

select machine_id , round(avg(diff),3) as processing_time from cte group by machine_id;