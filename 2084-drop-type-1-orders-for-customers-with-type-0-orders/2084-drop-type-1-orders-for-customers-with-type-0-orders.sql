# Write your MySQL query statement below
select *
from orders
where customer_id not in 
(
    select distinct customer_id
    from orders
    where order_type = 0
)
union
select *
from orders
where customer_id in
(
    select distinct customer_id
    from orders
    where order_type = 0
)
and order_type != 1