esDivisor :: Int -> Int -> Bool
esDivisor num1 num2 = num1 `mod` num2 == 0

existeDivisor :: Int-> [Int] -> Bool
existeDivisor num1 [] = False
existeDivisor num1 (x:xs) = esDivisor num1 x || existeDivisor num1 xs

esPrimo:: Int -> Bool
esPrimo num1 = not (existeDivisor num1 [2..(num1-1)])

listaPrimos :: [Int] -> [Int]
listaPrimos [] = []
listaPrimos (x:xs) | (esPrimo x) == True = x : listaPrimos xs
                   | otherwise = listaPrimos xs

listaPrimos' :: [Int] -> [Int]
listaPrimos' (xs) = filter esPrimo xs

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos (xs) = productoria (filter esPrimo xs)