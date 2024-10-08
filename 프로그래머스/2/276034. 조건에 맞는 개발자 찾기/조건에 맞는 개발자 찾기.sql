-- 코드를 작성해주세요
select distinct id, email, first_name, last_name
from developers
inner join skillcodes a
on skill_code & a.code
where a.name in ('C#', 'Python')
order by id;