with temp as (
select distinct departmentId, salary from Employee as e1 where (
    select count(distinct salary) from Employee as e2  
    where e1.departmentId= e2.departmentId 
    and e1.salary<e2.salary
) < 3
)

select d.name as 'Department', e.name as 'Employee', salary as 'Salary'
from Employee as e
left join Department as d
on d.id=e.departmentId 
where EXISTS (select * from temp as f where e.departmentId =  f.departmentId and e.salary=f.salary)

;