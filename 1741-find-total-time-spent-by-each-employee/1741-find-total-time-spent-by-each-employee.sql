# Write your MySQL query statement below

select day, b.emp_id, sum(total_time) as total_time
from
(
    select event_day as day, emp_id, (out_time - in_time) as total_time
    from employees
) b
group by day, emp_id