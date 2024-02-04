pertenece :: Int -> [Int] -> Bool
pertenece num1 [] = False
pertenece num1 (x:xs) | num1 == x = True
                      | otherwise = pertenece num1 xs