# Write your MySQL query statement below


with cte as (
    select *   from products p1 where change_date = (
        select max(change_date) from products p2 where p2.product_id = p1.product_id and p2.change_date <= '2019-08-16'
    )
),

p as (
    select distinct product_id from products
)

select p.product_id , ifnull(cte.new_price , 10) as price from p left join cte on p.product_id = cte.product_id;

#select * from p;

-- select * from products p left join cte c on p.product_id = c.product_id ;