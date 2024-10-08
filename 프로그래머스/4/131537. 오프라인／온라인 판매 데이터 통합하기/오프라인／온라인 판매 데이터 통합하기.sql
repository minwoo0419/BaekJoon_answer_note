-- 코드를 입력하세요
SELECT date_format(sales_date, '%Y-%m-%d') as s, product_id, user_id, sales_amount
from online_sale
where year(sales_date) = 2022 and month(sales_date) = 3
union
SELECT date_format(sales_date, '%Y-%m-%d') as s, product_id, null, sales_amount
from offline_sale
where year(sales_date) = 2022 and month(sales_date) = 3
order by s, product_id, user_id;