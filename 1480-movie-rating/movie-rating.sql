# Write your MySQL query statement below


(select m2.name as results  from movierating  m1 join users m2 on m1.user_id = m2.user_id group by m1.user_id order by count(*) desc , m2.name limit 1)

union all



(select m4.title as results    from movierating  m3 join movies m4 on m3.movie_id = m4.movie_id where month(m3.created_at)=2 and year(m3.created_at) = 2020 group by m3.movie_id  order by avg(m3.rating) desc , m4.title  limit 1)
