-- Problem 2988: Manager of the Largest Department
-- https://leetcode.com/problems/manager-of-the-largest-department/

-- Write your MySQL query statement below
-- 先使用 RANK 使用 COUNT(emp_id) 從大排到小來寫出部門排名
WITH RankDep AS (
    SELECT 
        dep_id, 
        RANK() OVER(ORDER BY COUNT(emp_id) DESC) AS dep_rank
    FROM 
        Employees
    GROUP BY 
        dep_id
)

-- 選擇部門 id 在部門排名中第一名的
SELECT
    emp_name AS manager_name,
    dep_id
FROM
    Employees
WHERE 
    `position` = 'Manager'
HAVING dep_id IN
    (
        SELECT
            dep_id
        FROM
            RankDep
        WHERE
            dep_rank = 1
    )
ORDER BY
    dep_id ASC;