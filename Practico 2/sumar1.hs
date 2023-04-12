sumar1:: [Int] -> [Int]
sumar1 [] = []
sumar1 (num:nums) = (num+1):(sumar1 nums)