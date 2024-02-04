minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:(y:xs))| x <= y    = minimoElemento (x:xs)
                         | otherwise = minimoElemento (y:xs)

minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' xs = minimoElemento xs

-- Sinonimos de tipo
type Altura      = Int
type NumCamiseta = Int

-- Tipos algebraicos sin parametros
data Zona        = Arco | Defensa | Mediocampo | Delantera 
                   deriving (Eq, Show)

data TipoReves   = DosManos | UnaMano                      
                   deriving (Eq, Show)

data Modalidad   = Carretera | Pista | Monte | BMX         
                   deriving (Eq, Show)

data PiernaHabil = Izquierda | Derecha                     
                   deriving (Eq, Show)

-- Sinonimo
type ManoHabil = PiernaHabil

-- Deportista 
data Deportista =  Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura | Futbolista Zona NumCamiseta PiernaHabil Altura 
                   deriving (Eq, Show)

contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] zona = 0
contar_futbolistas ((Futbolista Arco _ _ _):xs) Arco = 1 + contar_futbolistas xs Arco
contar_futbolistas ((Futbolista Defensa _ _ _):xs) Defensa = 1 + contar_futbolistas xs Defensa
contar_futbolistas ((Futbolista Mediocampo _ _ _):xs) Mediocampo = 1 + contar_futbolistas xs Mediocampo
contar_futbolistas ((Futbolista Delantera _ _ _):xs) Delantera = 1 + contar_futbolistas xs Delantera
contar_futbolistas (_:xs) zona = contar_futbolistas xs zona

igual_zona :: Zona -> Deportista -> Bool
igual_zona z (Futbolista zona _ _ _) = zona == z
igual_zona z _ = False

contar_futbolista2 :: [Deportista] -> Zona -> Int
contar_futbolista2 [] z = 0
contar_futbolista2 xs z = length (filter (igual_zona z) xs)

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si 
                  deriving (Eq, Bounded)

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

data Alteracion = Bemol | Natural | Sostenido deriving Eq

data NotaMusical = Nota NotaBasica Alteracion deriving Eq

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota notaN Bemol) = sonidoNatural notaN - 1
sonidoCromatico (Nota notaN Sostenido) = sonidoNatural notaN + 1
sonidoCromatico (Nota notaN Natural) = sonidoNatural notaN

sonidoCromatico' :: NotaMusical -> Int
sonidoCromatico' (Nota notaBasica alteracion)| alteracion == Bemol     = sonidoNatural notaBasica - 1
                                             | alteracion == Sostenido = sonidoNatural notaBasica + 1
                                             | alteracion == Natural   = sonidoNatural notaBasica

-- instance Eq NotaMusical
--         where n1  == n2  = sonidoCromatico n1  == sonidoCromatico n2

instance Ord NotaMusical
    where
        n1 <= n2 = sonidoCromatico n1 <= sonidoCromatico n2
        n1 >= n2 = sonidoCromatico n1 >= sonidoCromatico n2

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x