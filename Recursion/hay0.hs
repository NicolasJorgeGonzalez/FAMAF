hay0 :: [Int] -> Bool
hay0 [] = False
hay0 (num:nums) | num == 0 = True
                | num /= 0 = hay0(nums)