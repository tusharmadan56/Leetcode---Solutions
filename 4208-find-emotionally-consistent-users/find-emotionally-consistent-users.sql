# Write your MySQL query statement below


with f1 as (
    select user_id,reaction,count(distinct content_id) as 'c1' from reactions group by user_id,reaction 
),
f2 as (
    select user_id , reaction , c1 , sum(c1) over(partition by user_id) as total_count from f1
)

select user_id , reaction as 'dominant_reaction' , Round(c1/total_count,2) as 'reaction_ratio' from f2   where total_count >= 5 and Round(c1/total_count,2)>=0.6 order by  Round(c1/total_count,2) desc , user_id ;