data Color = Rojo | Amarillo | Azul | Verde deriving (Show, Eq)
data Forma = Triangulo | Cuadrado | Rombo | Circulo deriving (Show, Eq)
type Figura = (Forma, Color, Int)

rojo :: Figura -> Bool
rojo (f,c,t) = c == Rojo

azul :: Figura -> Bool
azul (f,c,t) = c == Azul

amarillo :: Figura -> Bool
amarillo  (f,c,t) = c == Amarillo

verde :: Figura -> Bool
verde (f,c,t) = c == Verde

circulo :: Figura -> Bool
circulo (f,c,t) = f == Circulo

rombo :: Figura -> Bool
rombo (f,c,t) = f == Rombo

cuadrado :: Figura -> Bool
cuadrado (f,c,t) = f == Cuadrado

triangulo :: Figura -> Bool
triangulo (f,c,t) = f == Triangulo

tam :: Figura -> Int
tam (f,c,t) = t 

propA :: [Figura] -> Bool
propA [] = True
propA (x : xs) = rojo x && propA xs

propB :: [Figura] -> Bool
propB []= True
propB (x:xs) = tam x < 5 && propB xs

propC :: [Figura] -> Bool
propC [] = True
propC (x:xs)| triangulo x == False = propC xs
            | (triangulo x && rojo x) && propC xs = True
            | otherwise = False

propD :: [Figura] -> Bool
propD [] = False
propD (x:xs)| cuadrado x && verde x = True
            | otherwise = propD xs

propE :: [Figura] -> Bool
propE [] = True
propE (x:xs)| circulo x == False = propE xs
            | (circulo x && azul x && tam x < 10) /= True = False
            | otherwise = propE xs

propF :: [Figura] -> Bool
propF [] = True
propF (x:xs)| triangulo x == False = propF xs
            | triangulo x && azul x = False
            | otherwise = propF xs

propG :: [Figura] -> Bool
propG [] = True
propG (x:xs)|(circulo x && verde x) = False
            |(circulo x && amarillo x) = False
            |otherwise = propG xs

propH :: [Figura] -> Bool
propH [] = False
propH (x:xs)|(cuadrado x && tam x < 5) = True
            |otherwise = propH xs

propI :: [Figura] -> Bool
propI [] = False
propI (x:xs)|((circulo x && rojo x)&&(cuadrado x && rojo x)) = True
            |otherwise = propI xs