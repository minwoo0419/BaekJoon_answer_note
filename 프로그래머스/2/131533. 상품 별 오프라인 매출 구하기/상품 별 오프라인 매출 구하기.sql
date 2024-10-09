-- 코드를 입력하세요
SELECT a.product_code, a.price * b.sum as sales
from product a
natural join (select b.product_id, sum(b.sales_amount) as sum from offline_sale b group by b.product_id) b
order by sales desc, a.product_code;