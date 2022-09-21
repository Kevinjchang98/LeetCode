# Write your MySQL query statement below
select a.employee_id from employees a
where a.employee_id not in
(
    select e.employee_id
    from employees e
    join salaries s on e.employee_id = s.employee_id
)
union
select b.employee_id from salaries b
where b.employee_id not in
(
    select e.employee_id
    from employees e
    join salaries s on e.employee_id = s.employee_id
)
order by employee_id asc