-- Problem 1831: Maximum Transaction Each Day
-- https://leetcode.com/problems/maximum-transaction-each-day/

-- Write your MySQL query statement below
-- 用原本的 Transactions Table 和 自己組成的 MaxTransactions 做 JOIN
-- MaxTransactions 依日期分組，找到每天最大的數量
SELECT
    transaction_id
FROM
    Transactions
JOIN
    (
        SELECT
            DATE_FORMAT(day, '%Y-%m-%d') AS `date`,
            MAX(amount) AS max_amount
        FROM
            Transactions
        GROUP BY
            DATE_FORMAT(`day`, '%Y-%m-%d')
    ) MaxTransactions
ON
    (
        DATE_FORMAT(Transactions.`day`, '%Y-%m-%d') = MaxTransactions.`date`
        AND
        Transactions.amount = MaxTransactions.max_amount
    )
ORDER BY
    transaction_id ASC;