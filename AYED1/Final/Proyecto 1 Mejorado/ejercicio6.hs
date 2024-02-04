paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] predicado = True
paratodo' (x:xs) predicado | (predicado x) == True = paratodo' xs predicado
                           | otherwise = False

paratodo'' :: [a] -> (a -> Bool) -> Bool
paratodo'' [] predicado = True
paratodo'' (x:xs) predicado = predicado x && paratodo'' xs predicado


existe' :: [a] -> (a -> Bool) -> Bool
existe' [] predicado = False
existe' (x:xs) predicado | predicado x == True = True
                         | otherwise = existe' xs predicado

existe'' :: [a] -> (a -> Bool) -> Bool
existe'' [] f = False
existe'' (x:xs) f = f (x) || existe'' xs f


sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] predicado = 0
sumatoria' (xs) predicado = sumatoria (map predicado xs)


productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

productoria' :: [a] -> (a -> Int) -> Int
productoria' [] predicado = 1
productoria' (xs) predicado = productoria (map predicado xs)

esPar :: Int -> Bool
esPar num1 | num1 `mod` 2 == 0 = True
           | otherwise = False

todosPares :: [Int] -> Bool
todosPares [] = False
todosPares (xs) = paratodo'' xs esPar

esMultiplo :: Int -> Int -> Bool
esMultiplo num1 num2 = num2 `mod` num1 == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo num1 [] = False
hayMultiplo num1 (x:xs) = esMultiplo num1 x || hayMultiplo num1 xs

cuadrados :: Int -> Int
cuadrados x = x^2

sumaCuadrados :: Int -> Int
sumaCuadrados 0 = 0
sumaCuadrados x = sumatoria' ([0..(x-1)]) cuadrados

esDivisor :: Int -> Int -> Bool
esDivisor num1 num2 = num1 `mod` num2 == 0

existeDivisor :: Int-> [Int] -> Bool
existeDivisor num1 [] = False
existeDivisor num1 (x:xs) = esDivisor num1 x || existeDivisor num1 xs

esPrimo:: Int -> Bool
esPrimo num1 = not (existeDivisor num1 [2..(num1-1)])

esFib :: Int -> Bool
esFib num1 = num1 == fib num1 

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib num1 =  fib (num1-1) + fib (num1-2)

todosFib :: [Int] -> Bool
todosFib [] = True  -- La lista vacía cumple la condición trivialmente
todosFib xs = and (map esFib xs) --  and verifica si todos los resultados son verdaderos. Si la lista está vacía, todosFib devuelve True 
