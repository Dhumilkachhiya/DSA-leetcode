# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit from products p join orders o on p.product_id=o.product_id where MONTH(o.order_date)=02 and YEAR(o.order_date)=2020 group by o.product_id having sum(o.unit)>=100;


