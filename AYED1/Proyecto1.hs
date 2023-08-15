--1a)
esCero :: Int -> Bool
esCero x | x == 0 = True
         | otherwise = False 
--1b)
esPositivo :: Int -> Bool
esPositivo x | x > 0 = True
             | otherwise = False
 --1c)
esVocal :: Char -> Bool
esVocal x | ((x == 'a') || (x == 'e') || (x=='i') || (x == 'o') || (x == 'u')) = True
          | otherwise = False
--1d)
valorAbsoluto :: Int -> Int
valorAbsoluto x | x >= 0 = x
                | x < 0 = (x * (-1)) 
--2a)
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x:xs) | x == True = paraTodo (xs)
                | otherwise = False
--2a')
paraTodo' :: [Bool] -> Bool
paraTodo' [] = True
paraTodo' (x:xs) = x == True && paraTodo' xs
--2b)
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
--2c)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
-- 2d)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)
-- 2e)
promedio :: [Int] -> Int
promedio (x:xs) = div (sumatoria (x : xs)) 2
--3)
pertenece :: Int -> [Int] -> Bool
pertenece n [] = True
pertenece n (x:xs)| n == x = True 
                  | otherwise = pertenece n (xs)
--3')
pertenece' :: Int -> [Int] -> Bool
pertenece' n [] = False
pertenece' n (x:xs)= n == x || pertenece' n (xs)

--4a)
paraTodo'' :: [a] -> (a -> Bool) -> Bool
paraTodo'' [] f = True
paraTodo'' (x:xs) f = f (x) && paraTodo'' xs f
--4b)
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] f = False
existe' (x:xs) f = f (x) || existe' xs f
--4c)
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] f = 0
sumatoria' (xs) f = sumatoria (map f xs)