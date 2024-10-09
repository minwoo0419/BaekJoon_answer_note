-- 코드를 입력하세요
with cte as (
SELECT a.car_id, round(a.daily_fee * (100 - c.discount_rate) / 100 * 30) as fee, e.count
from car_rental_company_car a
natural join car_rental_company_discount_plan c
left join (
        select d.car_id, count(*) as count
        from car_rental_company_rental_history d
        where not (d.start_date > '2022-11-30' or d.end_date < '2022-11-01')
        group by d.car_id
    ) e
on a.car_id = e.car_id
where a.car_type in ('SUV', '세단') and c.duration_type = '30일 이상'
)

select a.car_id,a.car_type, b.fee
from car_rental_company_car a
natural join cte b
where b.fee >= 500000 and b.fee < 2000000 and b.count is null
order by b.fee desc, a.car_type, a.car_id desc;