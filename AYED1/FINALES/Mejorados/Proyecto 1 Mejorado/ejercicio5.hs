paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] predicado = True
paratodo' (x:xs) predicado | (predicado x) == True = paratodo' xs predicado
                           | otherwise = False

paratodo'' :: [a] -> (a -> Bool) -> Bool
paratodo'' [] predicado = True
paratodo'' (x:xs) predicado = predicado x && paratodo'' xs predicado