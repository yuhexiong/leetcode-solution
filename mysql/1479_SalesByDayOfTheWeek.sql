-- Problem 1479: Sales by Day of the Week
-- https://leetcode.com/problems/sales-by-day-of-the-week/

-- Write your MySQL query statement below
-- 使用 DAYOFWEEK 來選擇星期, 並用 SUM 加總
SELECT 
    Items.item_category AS Category, 
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 2 THEN quantity ELSE 0 END ) AS Monday,
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 3 THEN quantity ELSE 0 END ) AS Tuesday, 
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 4 THEN quantity ELSE 0 END ) AS Wednesday,
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 5 THEN quantity ELSE 0 END ) AS Thursday, 
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 6 THEN quantity ELSE 0 END ) AS Friday, 
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 7 THEN quantity ELSE 0 END ) AS Saturday,
    SUM(CASE WHEN DAYOFWEEK(Orders.order_date) = 1 THEN quantity ELSE 0 END ) AS Sunday
FROM 
    Items 
LEFT JOIN 
    Orders 
ON Orders.item_id = Items.item_id 
GROUP BY Items.item_category
ORDER BY Items.item_category;