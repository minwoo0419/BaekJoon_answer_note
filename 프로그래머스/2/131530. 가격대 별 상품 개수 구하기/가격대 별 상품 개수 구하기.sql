-- 코드를 입력하세요
SELECT b.price_group, count(a.product_id)
from product a
join (select distinct price, truncate(price / 10000, 0) * 10000 price_group from product) b
on a.price = b.price
group by b.price_group
order by b.price_group;

