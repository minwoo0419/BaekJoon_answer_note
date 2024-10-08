-- 코드를 작성해주세요
select year(a.differentiation_date) as year, b.max_size-a.size_of_colony as year_dev, a.id
from ecoli_data a, (select year(c.differentiation_date) as year, max(c.size_of_colony) as max_size from ecoli_data c group by year(c.differentiation_date)) b
where year(a.differentiation_date) = b.year
order by year, year_dev;
