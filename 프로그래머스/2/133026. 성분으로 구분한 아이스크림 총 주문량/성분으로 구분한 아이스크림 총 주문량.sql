-- 코드를 입력하세요
SELECT b.ingredient_type, sum(a.total_order) as total_order
from first_half a
natural join icecream_info b
group by ingredient_type
order by total_order