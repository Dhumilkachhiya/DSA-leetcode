# Write your MySQL query statement below
select v.customer_id, count(*) as count_no_trans from visits v Left join Transactions t on v.visit_id=t.visit_id where t.transaction_id is null group by v.customer_id;

#where v.customer_id is null 
#group by v.customer_id;


