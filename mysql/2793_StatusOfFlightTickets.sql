-- Problem 2793: Status of Flight Tickets
-- https://leetcode.com/problems/status-of-flight-tickets/

-- Write your MySQL query statement below
-- 使用 ROW_NUMBER() 讓 Passengers.booking_time 以 Passengers.flight_id 分組後從小排到大
-- 排完後的 row_number 如果小於等於 Flights.capacity 就顯示 Status 是 'Confirmed'
-- 否則顯示 Status 是 'Waitlist'
SELECT
    passenger_id,
    CASE
        WHEN ROW_NUMBER() OVER (PARTITION BY Passengers.flight_id ORDER BY Passengers.booking_time ASC) <= Flights.capacity 
        THEN 'Confirmed'
        ELSE 'Waitlist'
    END AS Status
FROM
    Passengers
JOIN
    Flights
ON
    Passengers.flight_id = Flights.flight_id
ORDER BY
    passenger_id ASC; 