-- 1a)
esCero :: Int -> Bool
esCero x | x == 0 = True
         | otherwise = False 
-- ej) *Main> esCero 0
-- True
-- *Main> esCero 1
-- False


-- 1b)
esPositivo :: Int -> Bool
esPositivo x | x > 0 = True
             | otherwise = False
-- ej) *Main> esPositivo 4
-- True
-- *Main> esPositivo 0
-- False


 -- 1c)
esVocal :: Char -> Bool
esVocal x | ((x == 'a') || (x == 'e') || (x=='i') || (x == 'o') || (x == 'u')) = True
          | otherwise = False
-- ej) *Main> esVocal 'a'
-- True
-- *Main> esVocal 'b'
-- False


-- 1d)
valorAbsoluto :: Int -> Int
valorAbsoluto x | x >= 0 = x
                | x < 0 = (x * (-1)) 
-- ej) *Main> valorAbsoluto 5
-- 5
-- *Main> valorAbsoluto (-10)
-- 10


-- 2a)
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x:xs) | x == True = paraTodo (xs)
                | otherwise = False
-- ej) *Main> paraTodo [True,False,True]
-- False
-- *Main> paraTodo [True,True,True]
-- True

-- 2a')
paraTodo' :: [Bool] -> Bool
paraTodo' [] = True
paraTodo' (x:xs) = x == True && paraTodo' xs
-- ej) *Main> paraTodo' [True,False,True]
-- False
-- *Main> paraTodo' [True,True,True]
-- True


-- 2b)
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
-- ej) *Main> promedio [1,6,2,7]
-- 8
-- *Main> promedio [21,61,24,9]
-- 57


-- 2c)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
-- ej) *Main> promedio [1,6,2,7]
-- 8
-- *Main> promedio [21,61,24,9]
-- 57


-- 2d)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)
-- ej) *Main> promedio [1,6,2,7]
-- 8
-- *Main> promedio [21,61,24,9]
-- 57


-- 2e)
promedio :: [Int] -> Int
promedio (x:xs) = div (sumatoria (x : xs)) 2
-- ej) *Main> promedio [1,6,2,7]
-- 8
-- *Main> promedio [21,61,24,9]
-- 57


-- 3)
pertenece :: Int -> [Int] -> Bool
pertenece n [] = True
pertenece n (x:xs)| n == x = True 
                  | otherwise = pertenece n (xs)
--ej) *Main> pertenece 5 [1,2,4]
-- False
-- *Main> pertenece 5 [1,2,5,7]
-- True


-- 3')
pertenece' :: Int -> [Int] -> Bool
pertenece' n [] = False
pertenece' n (x:xs)= n == x || pertenece' n (xs)
--ej) *Main> pertenece' 5 [1,2,4]
-- False
-- *Main> pertenece' 5 [1,2,5,7]
-- True


-- 4a)
paraTodo'' :: [a] -> (a -> Bool) -> Bool
paraTodo'' [] f = True
paraTodo'' (x:xs) f = f (x) && paraTodo'' xs f
-- ej) *Main> paraTodo'' [1,2,4,0] esPositivo 
-- False
-- *Main> paraTodo'' [1,2,4,7] esPositivo 
-- True


-- 4b)
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] f = False
existe' (x:xs) f = f (x) || existe' xs f

existe'' :: [a] -> (a -> Bool) -> Bool --Para 6b) y 6d)
existe'' (xs) f = existe' (xs) f
-- ej) *Main> existe'' [0,3,4,(-2)] esPositivo 
-- True
-- *Main> existe'' [0,(-2)] esPositivo 
-- False


-- 4c)
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] f = 0
sumatoria' (xs) f = sumatoria (map f xs)
-- ej) *Main> sumatoria' [1,3,4,5] factorial
-- 151
-- *Main> sumatoria' [5,2,6,5] factorial
-- 962


-- 5) 
paraTodo''' :: [a] -> (a -> Bool) -> Bool
paraTodo''' xs f = paraTodo'' (xs) f
-- ej) *Main> paraTodo''' [0,0,0,0] esCero 
-- True
-- *Main> paraTodo''' [0,0,0,1] esCero 
-- False


-- 6a)
esPar :: Int -> Bool
esPar x = x `mod` 2 == 0

todosPares :: [Int] -> Bool
todosPares [] = True
todosPares (xs) = paraTodo''' (xs) esPar
-- ej) *Main> todosPares  [2,1,6,4]
-- False
-- *Main> todosPares  [2,8,6,4]
-- True


-- 6b)
esMultiplo :: Int -> Int -> Bool
esMultiplo y x = x `mod` y == 0 

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo y (xs) = existe'' xs (esMultiplo y)
-- ej) *Main> hayMultiplo 2 [1,3,5,11]
-- False
-- *Main> hayMultiplo 2 [1,3,5,10]
-- True


-- 6c)
cuadrados :: Int -> Int
cuadrados x = x^2

sumaCuadrados :: Int -> Int
sumaCuadrados 0 = 0
sumaCuadrados x = sumatoria' ([0..(x-1)]) cuadrados
-- ej) *Main> sumaCuadrados 3
-- 5
-- *Main> sumaCuadrados 120
-- 568820


-- 6d)
esDivisor :: Int -> Int -> Bool
esDivisor y x = y `mod` x == 0

existeDivisor :: Int -> [Int] -> Bool
existeDivisor y [] = False
existeDivisor y xs = existe'' xs (esDivisor y)
-- ej) *Main> existeDivisor 2 [3,5,8,9]
-- False
-- *Main> existeDivisor 16 [3,5,8,9]
-- True


-- 6e)
esPrimo :: Int -> Bool
esPrimo n | n <= 1 = False  -- Trata 0 y números negativos como no primos
          | otherwise = existeDivisor n [2..(n-1)]
-- ej) *Main> esPrimo 4
-- False
-- *Main> esPrimo 7
-- True


--6f)
factorial' :: Int -> Int
factorial' x = factorial x
-- ej) *Main> factorial' 5
-- 120
-- *Main> factorial' 3
-- 6


-- 6g)
soloPrimos :: [Int] -> [Int]
soloPrimos (xs) = filter esPrimo xs

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos (xs) = productoria (soloPrimos xs)
-- ej) *Main> multiplicaPrimos [0,4,3,5]
-- 4
-- *Main> multiplicaPrimos [1,4,3,5]
-- 4
-- *Main> multiplicaPrimos [1,3,7,5]
-- 1


-- 6h) 
-- fib :: Int -> Int
-- fib 0 = 0
-- fib 1 = 1
-- fib x =  fib (x-1) + fib (x-2)

-- esFib :: Int -> Bool
-- esFib n = n == fib x 


-- 6i)
