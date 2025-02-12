esCero :: Int -> Bool
esCero num1 | num1 == 0 = True
            | otherwise = False

esPositivo :: Int -> Bool
esPositivo num1 | num1 > 0 = True
                | otherwise = False

esVocal :: Char -> Bool
esVocal char1 | char1 == 'a' = True
              | char1 == 'e' = True
              | char1 == 'i' = True
              | char1 == 'o' = True
              | char1 == 'u' = True
              | otherwise = False

valorAbsoluto :: Int -> Int
valorAbsoluto num1 | num1 >= 0 = num1
                   | otherwise = num1 * (-1)

