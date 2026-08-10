# Write your MySQL query statement below
SELECT  user_id,count(*) AS prompt_count,
        round(avg(tokens),2) AS avg_tokens 
        FROM prompts 
        GROUP BY user_id 
        HAVING prompt_count>=3 
        AND avg(tokens)<max(tokens)  
        ORDER BY avg_tokens DESC;