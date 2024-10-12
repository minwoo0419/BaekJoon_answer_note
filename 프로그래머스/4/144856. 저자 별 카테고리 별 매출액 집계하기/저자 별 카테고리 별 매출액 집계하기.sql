-- 코드를 입력하세요
SELECT a.author_id, b.author_name, a.category, sum(a.price * c.sales) total_sales
from book a
natural join author b
natural join book_sales c
where year(c.sales_date) = 2022 and month(c.sales_date) = 1
group by a.author_id, a.category
order by b.author_id, a.category desc;