paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) | x == True = paratodo xs
                | otherwise = False

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

factorial :: Int -> Int
factorial 0 = 1
factorial num1 = num1 * factorial (num1 - 1)

promedio :: [Int] -> Int
promedio lista = (sumatoria lista) `div` length(lista)