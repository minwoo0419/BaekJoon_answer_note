-- 코드를 작성해주세요
with fish as(
    select id, case when length is null then 10 else length end length, fish_type
    from fish_info
)
select count(id) fish_count, max(length) max_length, fish_type
from fish
group by fish_type
having avg(length) >= 33
order by fish_type;