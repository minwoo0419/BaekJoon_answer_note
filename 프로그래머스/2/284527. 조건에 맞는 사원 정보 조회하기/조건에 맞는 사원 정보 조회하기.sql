-- 코드를 작성해주세요
select sum(b.score) score, a.emp_no, a.emp_name, a.position, a.email
from hr_employees a
natural join hr_grade b
where year = 2022
group by emp_no
order by 1 desc
limit 1;
