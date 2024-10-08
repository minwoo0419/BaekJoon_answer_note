-- 코드를 작성해주세요
select a.id, case when a.r / a.c <= 0.25 then 'CRITICAL' when a.r / a.c <= 0.5 then 'HIGH' when a.r / a.c <= 0.75 then 'MEDIUM' else 'LOW' end colony_name
from (select *, rank() over (order by size_of_colony desc) as r, count(*) over () as c from ecoli_data) a
order by id;