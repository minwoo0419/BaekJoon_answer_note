-- 코드를 작성해주세요
select distinct a.id, a.email, a.first_name, a.last_name
from developers a
join (select b.code from skillcodes b where b.category = 'Front End') b
on a.skill_code & b.code
order by a.id;