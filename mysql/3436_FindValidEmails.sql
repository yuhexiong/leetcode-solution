-- Problem 3436: Find Valid Emails
-- https://leetcode.com/problems/find-valid-emails/

-- Write your MySQL query statement below
-- 使用正則表達式依題意判斷
SELECT 
    user_id,
    email
FROM users
WHERE REGEXP_LIKE(email, '^[a-zA-Z0-9_]+@[a-zA-Z]+\.com$')
ORDER BY user_id;