with T as (Select * from Trips
where client_id not in (Select users_id from Users where banned ='Yes') and driver_id not in (Select users_id from Users where banned ='Yes') and request_at between '2013-10-01' and '2013-10-03' ),

C as(Select request_at, count(IF(status LIKE '%cancelled%', 1, NULL) )as cancelled, count(status) as complete from T
group by request_at)

Select
request_at as Day,
round(cancelled/complete, 2) as "Cancellation Rate"
from C
group by request_at