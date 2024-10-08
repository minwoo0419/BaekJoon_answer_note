-- 코드를 작성해주세요
select id, fish_name, length
from fish_info a
natural join fish_name_info 
where a.length > all(select b.length from fish_info b where b.length is not null and a.fish_type = b.fish_type and a.id != b.id)
order by id;