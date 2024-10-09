-- 코드를 입력하세요
SELECT a.product_id, a.product_name, sum(b.amount) * a.price as total_sales
from food_product a
natural join food_order b
where year(b.produce_date) = 2022 and month(b.produce_date) = 5
group by a.product_id
order by total_sales desc, a.product_id;
