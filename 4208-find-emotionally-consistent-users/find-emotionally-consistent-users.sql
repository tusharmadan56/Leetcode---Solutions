# Write your MySQL query statement below


with f1 as (
    select user_id,reaction,count(distinct content_id) as 'c1' from reactions group by user_id,reaction 
),

 f2 as (    
    select user_id,count(distinct content_id) as 'c' from reactions group by user_id having c>=5
)

select a.user_id , a.reaction as 'dominant_reaction' , Round(a.c1/b.c,2) as 'reaction_ratio' from f1 a join f2 b on a.user_id = b.user_id where Round(a.c1/b.c,2) > 0.6 order by Round(a.c1/b.c,2) desc;
