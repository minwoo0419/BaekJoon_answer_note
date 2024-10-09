-- 코드를 입력하세요
SELECT a.member_name, d.review_text, date_format(d.review_date, '%Y-%m-%d') as review_date
from member_profile a
natural join(select b.member_id, count(*) as count from rest_review b group by b.member_id order by count desc limit 1) c
natural join rest_review d
order by review_date, d.review_text;
