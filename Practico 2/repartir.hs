repartir :: [String] -> [String] -> [(String,String)]
repartir [] strs2 = []
repartir strs [] = []
repartir (str:strs) (str2:strs2) = (str, str2): (repartir strs strs2)