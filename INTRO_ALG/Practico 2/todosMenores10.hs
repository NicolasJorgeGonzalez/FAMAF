todosMenores10 :: [Int] -> Bool
todosMenores10 [] = True
todosMenores10 (num:nums) | num < 10 = todosMenores10(nums)
                          | num > 10 = False