# Write your MySQL query statement below


with cte as (
    select * , if(order_date = customer_pref_delivery_date , 1 , 0) as ok from delivery d where order_date = (
        select min(order_date) from delivery d2 where d2.customer_id = d.customer_id
    )   
)


select round(avg(if(ok=1,1,0)),4)*100 as immediate_percentage from cte;