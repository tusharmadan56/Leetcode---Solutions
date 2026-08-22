# Write your MySQL query statement below


with cte as (
    select product_id , min(year) as year from sales group by product_id
)

select sales.product_id , sales.year as first_year , sales.quantity , sales.price from sales join cte on sales.product_id = cte.product_id and sales.year = cte.year;