-- 코드를 작성해주세요
select count(id) fish_count
from fish_info
natural join fish_name_info
where fish_name in ('BASS', 'SNAPPER');