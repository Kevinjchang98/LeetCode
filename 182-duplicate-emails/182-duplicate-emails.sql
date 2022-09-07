# Write your MySQL query statement below
select
    email
from
(
    select
        email,
        count(email) as freq
    from
        Person
    group by
        email
) as f
where
    freq > 1