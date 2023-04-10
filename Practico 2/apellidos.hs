apellidos :: [(String, String, Int)] -> [String] 
apellidos [] = []
apellidos ((nombre,apellido,edad):resto) = apellido:(apellidos resto)