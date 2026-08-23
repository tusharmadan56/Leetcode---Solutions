# Write your MySQL query statement below


with cte as (select * , sum(weight) over(
    order by turn
) as tot
from queue)


select person_name from cte where tot<=1000 order by tot desc limit 1;