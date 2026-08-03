select name from salesperson where sales_id not in(
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c
      ON o.com_id = c.com_id
    WHERE c.name = 'RED');