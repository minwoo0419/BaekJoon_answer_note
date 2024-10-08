-- 코드를 작성해주세요
# select c.id
# from ecoli_data a
# join ecoli_data b
# on a.id = b.parent_id
# join ecoli_data c
# on b.id = c.parent_id
# where a.parent_id is null
# order by c.id;

with recursive cte as (
    select id, parent_id, 1 as ge
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, cte.ge + 1 as ge
    from ecoli_data a
    join cte on cte.id = a.parent_id
)
select cte.id as id
from cte
where cte.ge = 3
order by id;