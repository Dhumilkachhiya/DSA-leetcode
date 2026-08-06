# Write your MySQL query statement below
select s.student_id,s.student_name,sub.subject_name,(SELECT COUNT(*)
        FROM Examinations e
        WHERE e.student_id = s.student_id
        AND e.subject_name = sub.subject_name ) as attended_exams  
        from students s CROSS join Subjects sub order by s.student_id,sub.subject_name;