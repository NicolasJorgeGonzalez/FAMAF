mayoresQue10 :: [Int] -> [Int]
mayoresQue10 [] = []
mayoresQue10 (num:nums) | num > 10 = num:(mayoresQue10(nums))
                        | num <= 10 = (mayoresQue10(nums))