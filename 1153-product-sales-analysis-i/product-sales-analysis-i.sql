# Write your MySQL query statement below


select p.product_name , s1.year , s1.price from sales s1 join product p on s1.product_id = p.product_id ;