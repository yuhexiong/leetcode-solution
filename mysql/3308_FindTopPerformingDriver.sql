-- Problem 3308: Find Top Performing Driver
-- https://leetcode.com/problems/find-top-performing-driver/

-- Write your MySQL query statement below
SELECT
    VehicleOrder.fuel_type,
    VehicleOrder.driver_id,
    VehicleOrder.driver_rating AS rating,
    VehicleOrder.driver_total_distance AS distance
FROM
    (
        -- 將算好的數字進行排序, 以 fuel_type 為組
        SELECT
            DriverPerformances.fuel_type, 
            DriverPerformances.driver_id, 
            DriverPerformances.driver_rating, 
            DriverPerformances.driver_total_distance, 
            ROW_NUMBER() OVER (
                PARTITION BY DriverPerformances.fuel_type
                ORDER BY 
                    DriverPerformances.driver_rating DESC, 
                    DriverPerformances.driver_total_distance DESC, 
                    DriverPerformances.accidents ASC
            ) AS row_num
        FROM
            (
                -- 選取同一 driver 在不同 Vehicles.fuel_type 中的平均評分, 總距離 與失誤次數
                SELECT
                    Vehicles.vehicle_id,
                    Vehicles.fuel_type,
                    Drivers.driver_id,
                    ROUND(AVG(Trips.rating),2) AS driver_rating,
                    SUM(Trips.distance) AS driver_total_distance,
                    Drivers.accidents
                FROM
                    Drivers
                JOIN Vehicles
                ON Vehicles.driver_id = Drivers.driver_id
                JOIN
                    Trips
                ON Vehicles.vehicle_id = Trips.vehicle_id
                GROUP BY Drivers.driver_id, Vehicles.fuel_type
            ) AS DriverPerformances
        JOIN
            Trips
        ON 
            DriverPerformances.vehicle_id = Trips.vehicle_id
    ) AS VehicleOrder
-- 只選取 row_num = 1 的, 即排序第一
WHERE
    VehicleOrder.row_num = 1
ORDER BY VehicleOrder.fuel_type ASC;