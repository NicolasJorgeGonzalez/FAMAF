mapDoble :: [Int] -> [Int]
mapDoble [] = []
mapDoble (x:xs) = (x * 2) : mapDoble xs

auxdoble :: Int -> Int
auxdoble 0 = 0
auxdoble x = x*2

mapDoble' :: [Int] -> [Int]
mapDoble' (xs) = map auxdoble xs