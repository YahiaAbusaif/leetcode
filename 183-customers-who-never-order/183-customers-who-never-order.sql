/* Write your T-SQL query statement below */
SELECT name as'Customers'
from Customers as C
LEFT JOIN Orders as O
on C.id=O.customerId
where O.id is null;