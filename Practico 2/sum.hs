suma :: [Int] -> Int
suma [] =   0
suma (num:nums) = num+(suma(nums))