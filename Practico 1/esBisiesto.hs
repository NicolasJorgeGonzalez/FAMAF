esBisiesto :: Int -> Bool 
esBisiesto num1 = (mod num1 400 == 0) || (mod num1 4 == 0 && mod num1 100 /= 0) 