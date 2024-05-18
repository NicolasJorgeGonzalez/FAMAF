multiplos3 :: [Int] -> [Int]
multiplos3 [] = []
multiplos3 (x:xs) | mod x 3 == 0 = x: multiplos3 xs
                  | mod x 3 /= 0 = multiplos3 xs