-- Step 1: Find details of the crime on July 28, 2024 at Humphrey Street
SELECT * FROM crime_scene_reports
WHERE date = '2024-07-28' AND street = 'Humphrey Street';

-- Find interviews related to the theft on July 28, 2024
SELECT * FROM interviews
WHERE year = 2024 AND month = 7 AND day = 28;

-- Find flights that departed on July 28, 2024, within a short time after the crime
SELECT * FROM flights
WHERE origin_airport_id = (
    SELECT id FROM airports WHERE city = 'Fiftyville'
)
AND year = 2024 AND month = 7 AND day = 28
ORDER BY hour, minute;

-- Get destination city of that flight
SELECT city FROM airports
WHERE id = [destination_airport_id];

-- Find people who were on that flight
SELECT * FROM passengers
WHERE flight_id = [flight_id];

-- Get names of those people
SELECT * FROM people
WHERE id IN (
    SELECT passenger_id FROM passengers
    WHERE flight_id = [flight_id]
);

-- Find bank transactions on the same day
SELECT * FROM atm_transactions
WHERE year = 2024 AND month = 7 AND day = 28;

SELECT * FROM phone_calls
WHERE year = 2024 AND month = 7 AND day = 28;

-- Looking for the crime scene details on July 28 on Humphrey Street
SELECT * FROM crime_scene_reports
WHERE year = 2024 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
