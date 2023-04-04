mayoresQue :: Int -> [Int] -> [Int]
mayoresQue mnum [] = []
mayoresQue mnum (num:nums) | num > mnum = num:(mayoresQue mnum (nums))
                           | num <= mnum = (mayoresQue mnum (nums))