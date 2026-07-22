# Write your MySQL query statement below


with cte as (select  case when income<20000 then 'Low Salary'
                when income between 20000 and 50000 then 'Average Salary'
                else 'High Salary'
            end as category 

from accounts),

cte2 as (
    select 'High Salary' as category 
        union 
        select 'Low Salary' as category 
        union 
        select 'Average Salary' as category 

        
)





select cte2.category , ifnull(count(cte.category),0) as accounts_count from cte2 left join cte on cte.category = cte2.category group by cte2.category ; 