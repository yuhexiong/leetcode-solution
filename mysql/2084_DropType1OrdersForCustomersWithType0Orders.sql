-- Problem 2084: Drop Type 1 Orders for Customers With Type 0 Orders
-- https://leetcode.com/problems/drop-type-1-orders-for-customers-with-type-0-orders/

-- Write your MySQL query statement below
-- 選擇 order_type 是 0 的與完全沒有任何 order_type 是 0 (order_type全部是 1)的人
SELECT *
FROM Orders
WHERE order_type = 0
UNION
SELECT *
FROM Orders
WHERE customer_id NOT IN (
    SELECT customer_id
    FROM Orders
    WHERE order_type = 0
);
