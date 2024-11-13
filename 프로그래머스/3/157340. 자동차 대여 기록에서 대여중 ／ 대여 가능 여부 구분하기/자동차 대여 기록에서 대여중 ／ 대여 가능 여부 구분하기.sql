-- 코드를 입력하세요
SELECT a.car_id, case when a.car_id in (select distinct b.car_id
                                   from car_rental_company_rental_history b
                                   where b.start_date <= '2022-10-16'
                                   and b.end_date >= '2022-10-16') then '대여중'
                                   else '대여 가능' end
from car_rental_company_rental_history a
group by a.car_id
order by a.car_id desc;