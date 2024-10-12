-- 코드를 입력하세요
SELECT a.food_type, a.rest_id, a.rest_name, a.favorites
from rest_info a
join (select max(favorites) max_favorites, food_type from rest_info group by food_type) b
on a.food_type = b.food_type and a.favorites = b.max_favorites
order by a.food_type desc;