-- 코드를 입력하세요
with recursive cte as(
    select 0 hour
    union all
    select hour + 1
    from cte
    where hour < 23
)
SELECT a.hour, ifnull(b.cnt, 0)
from cte a
left join (select hour(datetime) hour, count(animal_id) cnt from animal_outs group by hour(datetime)) b
on a.hour = b.hour
order by 1;