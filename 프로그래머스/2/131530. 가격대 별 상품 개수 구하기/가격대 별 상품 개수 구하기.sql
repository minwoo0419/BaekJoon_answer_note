-- 코드를 입력하세요
SELECT c.price_group, count(a.product_id)
from product a
join (select truncate(b.price / 10000, 0) * 10000 price_group, b.product_id
     from product b) c on a.product_id = c.product_id
group by c.price_group
order by c.price_group
