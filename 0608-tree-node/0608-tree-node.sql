# Write your MySQL query statement below
select id,
    CASE
        WHEN p_Id IS null THEN 'Root'
        WHEN EXISTS (
            SELECT 1
            FROM tree t2
            WHERE t2.p_id = t.id
        )
        THEN 'Inner'
        ELSE 'Leaf'
    END AS type
from tree t;