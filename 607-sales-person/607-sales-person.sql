# Write your MySQL query statement below
select name
from salesperson
where name not in 
(
    select distinct sp.name
    from orders o
    left join company c on o.com_id = c.com_id
    left join salesperson sp on o.sales_id = sp.sales_id
    where c.name = "RED"
)
