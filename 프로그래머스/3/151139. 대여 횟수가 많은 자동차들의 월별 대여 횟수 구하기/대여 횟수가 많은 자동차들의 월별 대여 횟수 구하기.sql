-- 코드를 입력하세요
SELECT month(a.start_date), a.car_id, count(a.history_id)
from car_rental_company_rental_history a
where 5 <= (select count(b.history_id) from car_rental_company_rental_history b where a.car_id = b.car_id and year(b.start_date) = 2022 and month(b.start_date) between 8 and 10)
and year(a.start_date) = 2022 and month(a.start_date) between 8 and 10
group by a.car_id, month(a.start_date)
having count(a.history_id) > 0
order by month(a.start_date), a.car_id desc;