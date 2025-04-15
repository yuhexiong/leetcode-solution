-- Problem 1767: Find the Subtasks That Did Not Execute
-- https://leetcode.com/problems/find-the-subtasks-that-did-not-execute/

-- Write your MySQL query statement below
-- 使用遞迴顯示全部的資料
WITH RECURSIVE AllTasks AS (
    SELECT task_id, subtasks_count
    FROM Tasks
    UNION ALL
    SELECT task_id, subtasks_count - 1
    FROM AllTasks
    WHERE subtasks_count > 1
)

-- 選擇所有任務中不在已執行的表格內的
SELECT 
    task_id,
    subtasks_count AS subtask_id
FROM 
    AllTasks 
WHERE 
    (task_id, subtasks_count) NOT IN (SELECT * FROM Executed);