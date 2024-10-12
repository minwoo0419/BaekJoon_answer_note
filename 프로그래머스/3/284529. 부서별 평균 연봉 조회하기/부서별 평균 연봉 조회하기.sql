-- 코드를 작성해주세요
select a.dept_id, a.dept_name_en, round(avg(b.sal)) avg_sal
from hr_department a
natural join hr_employees b
group by dept_id
order by avg_sal desc;