-- 코드를 입력하세요
SELECT a.flavor
from july a
join first_half b
on a.flavor = b.flavor
group by a.flavor
order by sum(a.total_order) + b.total_order desc limit 3;
