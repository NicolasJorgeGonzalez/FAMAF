-- 1a)

data Carrera = Matematica | Fisica | Computacion | Astronomia
               deriving (Eq, Ord)

-- 1b)

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Computacion"
titulo Astronomia = "Licenciatura en Astronomia"

--1c), 2a)

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si
                  deriving (Eq, Ord, Show)
--1d)

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol= 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B' 

-- 3a) 

minimoElemento :: Ord a => [a] -> a 
minimoElemento [x] = x
minimoElemento (x:(y:xs))| x <= y = minimoElemento (x:xs)
                         | otherwise = minimoElemento (y:xs) 

-- 3b)

minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound 
minimoElemento' zs = minimoElemento zs 

-- 3c)

-- *Main> minimoElemento [Fa, La, Sol, Re, Fa] 
-- Re

-- 4a)

-- Sinonimos de tipo
type Altura = Int
type NumCamiseta = Int
-- Tipos algebraicos sin par ́ametros (aka enumerados)
data Zona = Arco | Defensa | Mediocampo | Delantera
            deriving (Eq, Show)
data TipoReves = DosManos | UnaMano
            deriving (Eq, Show)
data Modalidad = Carretera | Pista | Monte | BMX
            deriving (Eq, Show)              
data PiernaHabil = Izquierda | Derecha
            deriving (Eq, Show)

-- Sinonimo
type ManoHabil = PiernaHabil
-- Deportista -- es un tipo algebraico con constructores param ́etricos
data Deportista =  Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura | Futbolista Zona NumCamiseta PiernaHabil Altura 
                   deriving (Eq, Show)

-- 4b) Ciclista :: Modalidad -> Deportista

-- 4c)

contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista a):xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs

-- 4d)

contar_futbolista :: [Deportista] -> Zona -> Int
contar_futbolista [] z = 0
contar_futbolista ((Futbolista Arco _ _ _):xs) Arco = 1 + contar_futbolista xs Arco
contar_futbolista ((Futbolista Defensa _ _ _):xs) Defensa = 1 + contar_futbolista xs Defensa
contar_futbolista ((Futbolista Mediocampo _ _ _):xs) Mediocampo = 1 + contar_futbolista xs Mediocampo
contar_futbolista ((Futbolista Delantera _ _ _):xs) Delantera = 1 + contar_futbolista xs Delantera
contar_futbolista (_:xs) z = contar_futbolista xs z 

-- 4e) 

igual_zona :: Zona -> Deportista -> Bool
igual_zona z (Futbolista zona _ _ _) = zona == z
igual_zona z _ = False


contar_futbolista2 :: [Deportista] -> Zona -> Int
contar_futbolista2 [] z = 0
contar_futbolista2 xs z = length (filter (igual_zona z) xs) 

-- 5a)

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

-- 5b)

data Alteracion = Bemol | Natural | Sostenido
                  deriving (Eq, Show)

--5c)

data NotaMusical = Nota NotaBasica Alteracion
                   deriving (Show)
-- 5d-5e)
instance Eq NotaMusical
    where n1 == n2 = sonidoCromatico n1 == sonidoCromatico n2
instance Ord NotaMusical
    where  n1 <= n2 = sonidoCromatico n1 <= sonidoCromatico n2

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota notaBasica alteracion)| alteracion == Bemol = sonidoNatural notaBasica - 1 
                                            | alteracion == Sostenido = sonidoNatural notaBasica + 1
                                            | alteracion == Natural = sonidoNatural notaBasica

-- 6)

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento xs = Just (head xs)

-- 7a1)

data Cola = VaciaC | Encolada Deportista Cola
            deriving Show

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ colaRestante) = Just colaRestante

-- 7a2)

encolar :: Deportista -> Cola -> Cola
encolar deportista VaciaC = Encolada deportista VaciaC -- Una vez llegamos al final de la cola, insertamos al deportista
encolar deportista (Encolada deportistas colaRestante) = Encolada deportistas (encolar deportista colaRestante) -- Si la cola que le pasamos no es vacia, llama la funcion "encolar" con el resto de la cola hasta que sea vacio e inserte a nuestro deportista.

-- 7a3)

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC zona = Nothing
busca (Encolada (Futbolista z n p a) colaRestante) zona | zona == z = Just (Futbolista z n p a)
                                                        | otherwise = busca colaRestante zona
busca (Encolada _ colaRestante) zona = busca colaRestante zona -- En caso de que ingresemos un deportista que no sea Futbolista, va a descartar a este deportista y va a seguir con el resto
