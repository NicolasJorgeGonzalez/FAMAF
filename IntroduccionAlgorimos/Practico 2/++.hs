conc :: [a] -> [a] -> [a]
conc [] a = a
conc (x:xs) (y) = x: (conc xs y) e