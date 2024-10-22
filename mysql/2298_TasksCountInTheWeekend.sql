-- Problem 2298: Tasks Count in the Weekend
-- https://leetcode.com/problems/tasks-count-in-the-weekend/

-- Write your MySQL query statement below
-- 使用 WEEKDAY 判斷星期, 再使用 SUM 加總
SELECT 
    SUM(WEEKDAY(submit_date)>=5) AS weekend_cnt,
    SUM(WEEKDAY(submit_date)<5) AS working_cnt
FROM Tasks;