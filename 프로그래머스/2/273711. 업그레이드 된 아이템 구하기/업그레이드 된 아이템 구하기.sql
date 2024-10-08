-- 코드를 작성해주세요
select b.item_id, a.item_name, a.rarity
from item_info a
natural join item_tree b
where b.parent_item_id in (select c.item_id from item_info c where c.rarity = 'RARE')
order by b.item_id desc;
