-- 코드를 작성해주세요
select count(a.id) fish_count, b.fish_name
from fish_info a
natural join fish_name_info b
group by b.fish_name
order by count(a.id) desc;