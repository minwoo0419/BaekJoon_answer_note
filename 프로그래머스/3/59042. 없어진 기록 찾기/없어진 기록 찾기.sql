-- 코드를 입력하세요
SELECT a.animal_id, a.name
from animal_outs a
left join animal_ins b
on a.animal_id = b.animal_id
where b.intake_condition is null
order by a.animal_id;
