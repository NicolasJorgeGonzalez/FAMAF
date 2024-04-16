ordenaPares :: [(Int, Int)] -> [(Int, Int)]
ordenaPares [] = []  -- caso base: la lista vacía ya está ordenada
ordenaPares ((x1,y1):xs)
  | x1 > y1 = (y1,x1) : ordenaPares xs  -- si el primer par es mayor que el segundo, intercámbialos y sigue ordenando el resto
  | otherwise = (x1,y1) : ordenaPares xs  -- si el primer par es menor o igual que el segundo, déjalo donde está y sigue ordenando el resto
