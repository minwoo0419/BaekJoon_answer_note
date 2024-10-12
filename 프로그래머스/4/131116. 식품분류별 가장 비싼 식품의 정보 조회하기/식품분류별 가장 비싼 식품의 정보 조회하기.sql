-- 코드를 입력하세요
SELECT a.category, c.max_price max_price, a.product_name
from food_product a
join (select max(price) as max_price, category 
      from food_product 
      group by category) c
on a.category = c.category
where a.price = c.max_price and a.category in ("과자", "국", "김치", "식용유") 
order by 2 desc;