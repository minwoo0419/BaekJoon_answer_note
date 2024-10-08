-- 코드를 작성해주세요
with recursive cte as(
    select id, parent_id, 1 as gen
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, cte.gen + 1 as gen
    from ecoli_data a
    join cte on cte.id = a.parent_id
)
select count(c.id) as count, c.gen as generation
from cte c
where c.id not in (select d.parent_id from cte d where d.gen = c.gen + 1)
group by c.gen
order by generation;