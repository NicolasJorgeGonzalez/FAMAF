repetir :: Int-> Int-> [Int]
repetir 0 _ = [] 
repetir num1 num2 = num2: (repetir (num1-1) num2) -- Vemos el num1 como un contador que va disminuyendo y cuando llega a 0 corta el ciclo