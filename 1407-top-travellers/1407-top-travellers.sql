# Write your MySQL query statement below
select u.name,
        sum( case
                when r.distance is not null then r.distance
                else 0
            END) as travelled_distance 
            from users u left join rides r
        on u.id=r.user_id 
        group by u.id 
        order by travelled_distance DESC,u.name;