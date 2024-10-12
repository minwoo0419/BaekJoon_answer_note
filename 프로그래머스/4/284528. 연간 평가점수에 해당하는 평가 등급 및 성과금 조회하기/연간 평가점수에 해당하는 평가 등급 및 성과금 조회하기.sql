-- 코드를 작성해주세요
with grade as(
    select a.emp_no, case
    when avg(score) >= 96 then 'S'
    when avg(score) >= 90 then 'A'
    when avg(score) >= 80 then 'B'
    else 'C' end grade
    from hr_employees a
    natural join hr_grade b
    group by emp_no
)
select a.emp_no, a.emp_name, b.grade, case 
when b.grade = 'S' then sal * 0.2
when b.grade = 'A' then sal * 0.15
when b.grade = 'B' then sal * 0.1
else 0 end bonus
from hr_employees a
natural join grade b
order by 1