# -- 코드를 입력하세요
SELECT a.car_id, case when a.car_id in (
    select car_id
    from car_rental_company_rental_history
    where start_date <= "2022-10-16" and end_date >= "2022-10-16"
    group by car_id
) then "대여중" else "대여 가능" end
from  (
    SELECT DISTINCT car_id 
    FROM car_rental_company_rental_history
) a
order by a.car_id desc;