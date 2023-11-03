-- 1a)
data Forma = Piedra | Papel | Tijera

le_gana :: Forma -> Forma -> Bool
le_gana Piedra Tijera = True
le_gana Piedra _      = False
le_gana Papel Piedra  = True
le_gana Papel _       = False
le_gana Tijera Papel  = True
le_gana Tijera _      = False

-- 1b)
type Nombre = String
data Jugador = Mano Nombre Forma

ganador :: Jugador -> Jugador -> Maybe Nombre
ganador (Mano nombre1 forma1) (Mano nombre2 forma2)| le_gana forma1 forma2 == True = Just nombre1
                                                   | le_gana forma2 forma1 == True = Just nombre2
                                                   | otherwise = Nothing

-- 2)
quien_jugo :: Forma -> [Jugador] -> [Nombre]
quien_jugo _ [] = []
quien_jugo Tijera ((Mano nombre Tijera):restoJugadores) = nombre: (quien_jugo Tijera (restoJugadores))
quien_jugo Tijera ((Mano nombre _):restoJugadores)      = (quien_jugo Tijera (restoJugadores))
quien_jugo Piedra ((Mano nombre Piedra):restoJugadores) = nombre: (quien_jugo Piedra (restoJugadores))
quien_jugo Piedra ((Mano nombre _):restoJugadores)      = nombre: (quien_jugo Piedra (restoJugadores))
quien_jugo Papel ((Mano nombre Papel):restoJugadores)   = nombre: (quien_jugo Papel (restoJugadores))
quien_jugo Papel ((Mano nombre _):restoJugadores)       = nombre: (quien_jugo Papel (restoJugadores))

-- 3) 
data NotaMusical = Do | Re | Mi | Fa | Sol | La | Si 
data Figura     = Negra | Corchea deriving (Eq, Show)
data Melodia    = Vacia | Entonar NotaMusical Figura Melodia

contar_tiempos :: Melodia -> Int 
contar_tiempos Vacia = 0
contar_tiempos (Entonar _ figura (restoMelodia))| figura == Negra   = 2 + (contar_tiempos restoMelodia)
                                                | figura == Corchea = 1 + (contar_tiempos restoMelodia)