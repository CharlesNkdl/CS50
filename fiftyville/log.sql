-- Keep a log of any SQL queries you execute as you solve the mystery.
-- get the schema
--.schema;
-- get information
SELECT * FROM crime_scene_reports;
-- get info omly on humphrey street
SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street';
-- get logs of the date of the bakery
SELECT * FROM bakery_Security_logs WHERE year = 2021 AND month = 7 AND day = 28;
-- crossexam license plate the day of the robbery with people
SELECT DISTINCT people.* FROM people
JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28;
-- refine by time
SELECT DISTINCT people.* FROM people
JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour >= 9 AND bakery_security_logs.hour <= 11;
-- Follow line
--cat log.sql | sqlite3 fiftyville.db  > follow.txt
-- get transcript : Ruth : car left within 10 minutes after, Eugene : Earlier ATM Legett Street withdraw cash, Raymond = after leaving bakery, call for ticket
SELECT * FROM interviews;
-- with Logs from before culprit = one from
SELECT DISTINCT people.* FROM people
JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_Security_logs.minute <= 25;
-- One of Vanessa Barry Iman Sofia Luca Diana Kelsey Bruce, now check atm from legett street
SELECT DISTINCT people.* FROM people JOIN bank_accounts ON people.id= bank_accounts.person_id JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE year = 2021 AND day = 28 AND month = 7 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- No Vanessa,Barry,Sofia,Kelsey = Suspect = Iman, Luca, Diana, Bruce so check phone
SELECT phone_calls.* FROM phone_calls JOIN  people ON  people.phone_number = phone_calls.caller JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate
   ...> WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
   ...> AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_Security_logs.minute <= 25 AND phone_calls.day = 28;
--We can delete from suspect : Iman , Luca So only Bruce and Diana is left
-- Now check Flight and who is on it
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports
  JOIN flights ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29 ORDER BY flights.hour, flights.minute;
-- First flights is to NYC so now check passenger on it
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat FROM people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20
 ORDER BY passengers.passport_number;
 -- Only bruce is on it so he is the culprit, duration of the call of bruce was 49 s so now we can check who is the associate
 SELECT name, phone_calls.duration FROM people
  JOIN phone_calls ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;
   -- Robin is the one he called so he is the associate !