rev :: [a] -> [a]
rev [] = [] -- caso base: lista vacía devuelve una lista vacía
rev (x:xs) = rev xs ++ [x] -- va pegando la cola de la lista "xs" al inicio de la lista asi hasta que la lista original se quede sin elementos