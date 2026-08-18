# Write your MySQL query statement below


select c1.name from Customer c1 left join Customer c2 on c1.referee_id = c2.id where c1.referee_id!=2 or c1.referee_id is NULL;