-- 1a) 
data Color = Rojo | Negro | Azul
             deriving Show

mismo_color :: Color -> Color -> Bool
mismo_color Rojo Rojo   = True
mismo_color Rojo _      = False
mismo_color Azul Azul   = True
mismo_color Azul _      = False
mismo_color Negro Negro = True
mismo_color Negro _     = False

-- 1b) 
data Tipo     = Auto | Moto | Camion deriving Show
data Vehiculo = Cons Tipo Color deriving Show

pintar_auto :: Vehiculo -> Color -> Maybe Vehiculo
pintar_auto (Cons Auto _) color = Just (Cons Auto color)
pintar_auto _ color             = Nothing

-- 2)
solo_de_color :: Color -> [Vehiculo] -> [Tipo]
solo_de_color color [] = []
solo_de_color Rojo ((Cons tipo Rojo):restoVehiculos)    = tipo: (solo_de_color Rojo (restoVehiculos))
solo_de_color Negro ((Cons tipo Negro):restoVehiculos)  = tipo: (solo_de_color Negro (restoVehiculos))
solo_de_color Azul ((Cons tipo Azul):restoVehiculos)    = tipo: (solo_de_color Azul(restoVehiculos))
solo_de_color color (x:xs) = solo_de_color color xs
-- 3) 
type Precio     = Int
type Nombre     = String 
data Producto   = Item Nombre Precio
data Compra     = Nada | AgregarProd Producto Int Compra

costo :: Compra -> Precio
costo Nada = 0
costo (AgregarProd (Item nombre precio) cantidad (restoCompra)) = (precio * cantidad) + costo (restoCompra)

