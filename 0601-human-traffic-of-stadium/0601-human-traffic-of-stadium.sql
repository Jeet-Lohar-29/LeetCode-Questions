# Write your MySQL query statement below
WITH FilteredStadium AS (
    SELECT id, visit_date, people
    FROM Stadium
    WHERE people >= 100
),
GroupedStadium AS (
    SELECT *,
           id - ROW_NUMBER() OVER (ORDER BY id) AS island_id
    FROM FilteredStadium
),
IslandCounts AS (
    SELECT *,
           COUNT(*) OVER (PARTITION BY island_id) AS island_size
    FROM GroupedStadium
)
SELECT id, visit_date, people
FROM IslandCounts
WHERE island_size >= 3
ORDER BY visit_date ASC;
