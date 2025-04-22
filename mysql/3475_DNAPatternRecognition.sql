-- Problem 3475: DNA Pattern Recognition 
-- https://leetcode.com/problems/find-products-with-three-consecutive-digits/

-- Write your MySQL query statement below
-- 使用正則表達式依題意判斷
SELECT
    *,
    dna_sequence REGEXP '^ATG' AS has_start,
    dna_sequence REGEXP 'TAA$|TAG$|TGA$' AS has_stop,
    dna_sequence REGEXP 'ATAT' AS has_atat,
    dna_sequence REGEXP 'GGG' AS has_ggg
FROM samples
ORDER BY sample_id;