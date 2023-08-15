maximo :: [Int] -> Int 
maximo [a] =  a
maximo (x:(y:xs)) | x >= y = maximo(x:xs)
                  | x < y = maximo(y:xs)