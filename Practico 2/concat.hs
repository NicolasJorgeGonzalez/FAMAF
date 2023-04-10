concate :: [[a]] -> [a]
concate [] = []
concate (x:xs) = x ++ (concate xs)