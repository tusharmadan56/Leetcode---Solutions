# Write your MySQL query statement below

select t.request_at as Day , Round(sum(case when t.status!='completed' then 1 else 0 END )/count(*),2) as 'Cancellation Rate'
from Trips t where t.client_id not in (select users_id from Users where banned='YES') and  t.driver_id not in (select users_id from users where banned = 'YES') and t.request_at between '2013-10-01' and '2013-10-03' group by t.request_at ;

