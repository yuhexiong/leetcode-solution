-- Problem 3338: Second Highest Salary II
-- https://leetcode.com/problems/second-highest-salary-ii/

-- Write your MySQL query statement below
SELECT
    employees.emp_id,
    employees.dept
FROM
    employees
JOIN
    (   
        -- 使用 ROW_NUMBER 依照 dept 分群再以 salary 由大到小排序
        -- 最後只 JOIN 排名第二的
        SELECT
            salary,
            dept,
            ROW_NUMBER() OVER (PARTITION BY dept ORDER BY salary DESC) AS ranking
        FROM
            (
                SELECT DISTINCT
                    salary,
                    dept
                FROM
                    employees
            ) distinctSalary
    ) rankingByDept
ON
    (
        rankingByDept.ranking = 2
        AND employees.salary = rankingByDept.salary
        AND employees.dept = rankingByDept.dept
    );