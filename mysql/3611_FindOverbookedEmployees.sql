-- Problem 3611: Find Overbooked Employees
-- https://leetcode.com/problems/find-overbooked-employees/description/

-- Write your MySQL query statement below
-- 先計算員工的每週總工時
WITH meetingHoursByWeek AS (
    SELECT
        employee_id AS employee_id,
        YEAR(meeting_date) AS meeting_year,
        WEEKOFYEAR(meeting_date) AS meeting_week,
        SUM(duration_hours) AS hours_by_week
    FROM
        meetings
    GROUP BY
        employee_id, meeting_year, meeting_week
)
-- 使用員工表格 JOIN 每週總工時，計算有超過 20 週的人
SELECT
    employees.employee_id AS employee_id,
    employees.employee_name AS employee_name,
    employees.department AS department,
    COUNT(*) AS meeting_heavy_weeks
FROM
    employees 
JOIN
    meetingHoursByWeek
ON
    employees.employee_id = meetingHoursByWeek.employee_id
WHERE
    hours_by_week > 20
GROUP BY
    employees.employee_id,
    employees.employee_name,
    employees.department
HAVING
    COUNT(*) > 1
ORDER BY
    meeting_heavy_weeks DESC, 
    employee_name ASC;
