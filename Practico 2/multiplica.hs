multiplica :: Int -> [Int] -> [Int]
multiplica const [] = []
multiplica const (num:nums) = (const * num):(multiplica const (nums))