-- 코드를 작성해주세요
-- 코드를 작성해주세요
select a.id, a.email, a.first_name, a.last_name
from developers a
where a.skill_code & (select sum(b.code) from skillcodes b where b.category = 'Front End')
order by a.id;