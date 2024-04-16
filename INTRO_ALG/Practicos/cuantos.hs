cuantos :: [Int] -> Bool
cuantos (x:xs) | x == length(x:xs) = True
               | x /= length(x:xs) = False
cuantos [] = False