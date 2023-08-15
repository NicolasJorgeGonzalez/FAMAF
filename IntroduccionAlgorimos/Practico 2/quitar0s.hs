quitar0s :: [Int] -> [Int]
quitar0s [] = []
quitar0s (num:resto) | num /= 0 = num:(quitar0s resto)
                     | num == 0 = (quitar0s resto)