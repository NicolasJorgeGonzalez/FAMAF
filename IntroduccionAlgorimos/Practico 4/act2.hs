data Color = Rojo | Amarillo | Azul | Verde deriving (Show, Eq)
data Forma = Triangulo | Cuadrado | Rombo | Circulo deriving (Show, Eq)
type Figura = (Forma, Color, Int)

tam :: Figura -> Int
tam (f,c,t) = t 