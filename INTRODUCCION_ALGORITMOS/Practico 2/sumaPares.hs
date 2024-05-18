sumaPares :: [(Int, Int)] -> Int
sumaPares [] = 0 -- caso base: lista vacía devuelve cero
sumaPares ((x,y):resto) = x + y + sumaPares resto -- sumar los números del par de la cabeza y llamar recursivamente con la cola