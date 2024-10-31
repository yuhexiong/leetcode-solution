-- Problem 2837: Total Traveled Distance
-- https://leetcode.com/problems/total-traveled-distance/

-- Write your MySQL query statement below
-- 使用 LEFT JOIN 讓沒有旅行的使用者保留資料, 再使用 IFNULL 補空值
SELECT
    Users.user_id,
    Users.name,
    IFNULL(SUM(Rides.distance), 0) AS `traveled distance`
FROM
    Users
LEFT JOIN
    Rides
ON
    Users.user_id = Rides.user_id
GROUP BY
    Users.user_id
ORDER BY
    Users.user_id ASC;