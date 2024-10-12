-- 코드를 작성해주세요
with python as(
    select code
    from skillcodes
    where name = "Python"
),
front_end as(
    select code
    from skillcodes
    where category = "Front End"
),
C as(
    select code
    from skillcodes
    where name = "C#"
), grade as(
    select id, case
    when skill_code & (select code from Python) and (select count(*) from front_end where skill_code & code) > 0 then 'A'
    when skill_code & (select code from C) then 'B'
    when (select count(*) from front_end where skill_code & code) > 0 then 'C' end grade
    from developers
)
select b.grade, a.id, a.email
from developers a
natural join grade b
where b.grade is not null
order by b.grade, a.id;