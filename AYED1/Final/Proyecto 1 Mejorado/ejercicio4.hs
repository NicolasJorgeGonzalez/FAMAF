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

