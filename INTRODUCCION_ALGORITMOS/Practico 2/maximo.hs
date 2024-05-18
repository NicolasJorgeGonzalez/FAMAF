maximo :: [Int] -> Int 
maximo [a] =  a
maximo (x:xs) = x `max` (maximo xs)
