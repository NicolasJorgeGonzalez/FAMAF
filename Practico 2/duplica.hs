duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = (2*x):(duplica(xs))