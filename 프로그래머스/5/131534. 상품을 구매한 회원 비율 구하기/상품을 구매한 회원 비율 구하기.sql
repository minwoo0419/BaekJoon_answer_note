-- 코드를 입력하세요

SELECT year(a.sales_date) as year, month(a.sales_date) as month, count(distinct(a.user_id)) as purchased_users, round(count(distinct(a.user_id)) / (select count(*) from user_info where year(joined) = 2021), 1) as puchased_ratio
from online_sale a
natural join(select b.user_id from user_info b where year(joined) = 2021) b
group by year(a.sales_date), month(a.sales_date)
order by year, month;