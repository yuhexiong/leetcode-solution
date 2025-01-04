-- Problem 3415: Find Products with Three Consecutive Digits
-- https://leetcode.com/problems/find-products-with-three-consecutive-digits/

-- Write your MySQL query statement below
-- 使用正則表達式取得有三位數字但沒有四位數字的資料
SELECT 
    product_id, 
    name
FROM 
    Products
WHERE 
    name REGEXP '[0-9]{3}' AND name NOT REGEXP '[0-9]{4,}'
ORDER BY 
    product_id ASC;