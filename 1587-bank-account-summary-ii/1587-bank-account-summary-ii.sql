# Write your MySQL query statement below
select *
from
(
    select name, sum(amount) as balance
    from transactions t
    left join users u on t.account = u.account
    group by t.account
) a
where a.balance > 10000