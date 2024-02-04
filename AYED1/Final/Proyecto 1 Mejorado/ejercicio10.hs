primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA valor [] = []
primIgualesA valor (x:xs) | (valor == x) = x : primIgualesA valor xs
                          | otherwise = []
iguales :: Eq a => a -> a -> Bool
iguales n x = (x==n)

primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' valor []= []
primIgualesA' valor xs = takeWhile (iguales valor) xs

primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales [x] = [x]
primIguales (x:(y:xs)) | x == y = x: primIguales(y:xs)
                       | otherwise = [x]

primIguales' :: Eq a => [a] -> [a]
primIguales' [] = []
primIguales' (x:xs) = x : primIgualesA x (xs)