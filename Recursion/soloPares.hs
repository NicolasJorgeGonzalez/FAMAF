soloPares :: [Int] -> [Int]
soloPares [] = []
soloPares (num:nums) | num `mod` 2 == 0 = num:(soloPares(nums))
                     | num `mod` 2 /= 0 = soloPares(nums)