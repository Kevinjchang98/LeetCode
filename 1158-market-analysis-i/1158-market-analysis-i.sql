# Write your MySQL query statement below
select users.user_id as buyer_id, join_date, count(distinct order_id) as orders_in_2019
from users
left join orders on users.user_id = orders.buyer_id
and year(order_date) = '2019'
group by users.user_id