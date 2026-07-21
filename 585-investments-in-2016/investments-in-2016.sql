# Write your MySQL query statement below


with f as ( select i1.pid,i1.tiv_2016 from Insurance i1 ,Insurance i2 where i1.pid<>i2.pid and i1.tiv_2015 = i2.tiv_2015 and i1.pid not in (
    select i3.pid from Insurance i3 ,Insurance i4 where i3.pid<>i4.pid and i3.lat=i4.lat and i3.lon=i4.lon)
    
    group by i1.pid)


    select round(sum(f.tiv_2016),2) as 'tiv_2016' from f;