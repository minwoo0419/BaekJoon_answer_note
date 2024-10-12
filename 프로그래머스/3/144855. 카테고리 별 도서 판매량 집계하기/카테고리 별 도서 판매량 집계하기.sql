-- 코드를 입력하세요
SELECT a.category, sum(b.sales)
from book a
natural join book_sales b
where year(b.sales_date) = 2022 and month(b.sales_date) = 1
group by a.category
order by a.category;