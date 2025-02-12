-- 1a)

data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq, Ord)

-- 1b)

titulo :: Carrera -> String
titulo Matematica  = "Licenciatura en Matematica"
titulo Fisica      = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Computacion"
titulo Astronomia  = "Licenciatura en Astronomia"

-- ej) *Main> titulo Matematica 
-- "Licenciatura en Matematica"
-- *Main> titulo Computacion 
-- "Licenciatura en Computacion"

--1c), 2a)

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)

--1d)

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do  = 'C'
cifradoAmericano Re  = 'D'
cifradoAmericano Mi  = 'E'
cifradoAmericano Fa  = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La  = 'A'
cifradoAmericano Si  = 'B'

-- ej) *Main> cifradoAmericano  Do
-- 'C'
-- *Main> cifradoAmericano  Re
-- 'D'

-- 3a)

minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:(y:xs))| x <= y    = minimoElemento (x:xs)
                         | otherwise = minimoElemento (y:xs)

-- ej) *Main> minimoElemento [1,4,5,2]
-- 1

-- 3b)

minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' zs = minimoElemento zs

-- ej) *Main> minimoElemento' [1,4,5,2]:: Int
-- 1

-- 3c)

-- *Main> minimoElemento [Fa, La, Sol, Re, Fa]
-- Re

-- 4a)

-- Sinonimos de tipo
type Altura      = Int
type NumCamiseta = Int

-- Tipos algebraicos sin parametros
data Zona        = Arco | Defensa | Mediocampo | Delantera deriving (Eq, Show)
data TipoReves   = DosManos | UnaMano                      deriving (Eq, Show)
data Modalidad   = Carretera | Pista | Monte | BMX         deriving (Eq, Show)
data PiernaHabil = Izquierda | Derecha                     deriving (Eq, Show)

-- Sinonimo
type ManoHabil = PiernaHabil

-- Deportista 
data Deportista =  Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura | Futbolista Zona NumCamiseta PiernaHabil Altura deriving (Eq, Show)

-- 4b) Ciclista :: Modalidad -> Deportista

-- 4c)

contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista a):xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs

-- ej) *Main> contar_velocistas [Velocista 180, Velocista 175]
-- 2

-- 4d)

contar_futbolista :: [Deportista] -> Zona -> Int
contar_futbolista [] z = 0
contar_futbolista ((Futbolista Arco _ _ _):xs) Arco             = 1 + contar_futbolista xs Arco
contar_futbolista ((Futbolista Defensa _ _ _):xs) Defensa       = 1 + contar_futbolista xs Defensa
contar_futbolista ((Futbolista Mediocampo _ _ _):xs) Mediocampo = 1 + contar_futbolista xs Mediocampo
contar_futbolista ((Futbolista Delantera _ _ _):xs) Delantera   = 1 + contar_futbolista xs Delantera
contar_futbolista (_:xs) z = contar_futbolista xs z

-- ej) *Main> contar_futbolista [Futbolista Delantera 15 Derecha 180, Velocista 190] Arco 
-- 0

-- 4e)

igual_zona :: Zona -> Deportista -> Bool
igual_zona z (Futbolista zona _ _ _) = zona == z
igual_zona z _ = False

contar_futbolista2 :: [Deportista] -> Zona -> Int
contar_futbolista2 [] z = 0
contar_futbolista2 xs z = length (filter (igual_zona z) xs)

-- ej) *Main> contar_futbolista2 [Futbolista Delantera 15 Derecha 180, Velocista 190] Arco 
-- 0

-- 5a)

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do  = 0
sonidoNatural Re  = 2
sonidoNatural Mi  = 4
sonidoNatural Fa  = 5
sonidoNatural Sol = 7
sonidoNatural La  = 9
sonidoNatural Si  = 11

-- ej) *Main> sonidoNatural Do
-- 0
-- *Main> sonidoNatural Re
-- 2

-- 5b)

data Alteracion = Bemol | Natural | Sostenido deriving (Eq, Show)

--5c)

data NotaMusical = Nota NotaBasica Alteracion deriving (Show)

-- 5d-5e)

instance Eq NotaMusical
    where n1  == n2  = sonidoCromatico n1  == sonidoCromatico n2
instance Ord NotaMusical
    where  n1 <= n2  = sonidoCromatico n1  <= sonidoCromatico n2

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota notaBasica alteracion)| alteracion == Bemol     = sonidoNatural notaBasica - 1
                                            | alteracion == Sostenido = sonidoNatural notaBasica + 1
                                            | alteracion == Natural   = sonidoNatural notaBasica

-- ej) *Main> sonidoCromatico (Nota Re Bemol)
-- 1 


-- 6)

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento xs = Just (head xs)

-- ej) *Main> primerElemento [1,2,3,4,5,6]
-- Just 1

-- 7a1)

data Cola = VaciaC | Encolada Deportista Cola deriving Show

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ colaRestante) = Just colaRestante

-- ej) *Main> atender (Encolada (Velocista 178) VaciaC)
-- Just VaciaC

-- 7a2)

encolar :: Deportista -> Cola -> Cola
encolar deportista VaciaC = Encolada deportista VaciaC -- Una vez llegamos al final de la cola, insertamos al deportista
encolar deportista (Encolada deportistas colaRestante) = Encolada deportistas (encolar deportista colaRestante) -- Si la cola que le pasamos no es vacia, llama la funcion "encolar" con el resto de la cola hasta que sea vacio e inserte a nuestro deportista.

-- ej) *Main> encolar (Velocista 190) (Encolada (Velocista 180) (Encolada (Velocista 175) VaciaC))
-- Encolada (Velocista 180) (Encolada (Velocista 175) (Encolada (Velocista 190) VaciaC))

-- 7a3)

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC zona = Nothing
busca (Encolada (Futbolista z n p a) colaRestante) zona | zona == z = Just (Futbolista z n p a)
                                                        | otherwise = busca colaRestante zona
busca (Encolada _ colaRestante) zona = busca colaRestante zona -- En caso de que ingresemos un deportista que no sea Futbolista, va a descartar a este deportista y va a seguir con el resto

-- ej) *Main> busca (Encolada (Velocista 193) (Encolada (Velocista 188) (Encolada (Futbolista Arco 1 Derecha 190) (Encolada (Futbolista Delantera 10 Izquierda 169) VaciaC )))) Arco
-- Just (Futbolista Arco 1 Derecha 190)

-- 7b)
-- Yo considero que el tipo cola se parece mucho a las listas

-- 8a)

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
type GuiaTel       = ListaAsoc String Int
type Diccionario   = ListaAsoc String String
type Padron        = ListaAsoc Int String

-- 8b1)

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b (restoLista)) = 1 + (la_long (restoLista))

-- ej) *Main> la_long (Nodo "Nicolas" 1 (Nodo "Nicolas" 150 (Vacia)))
-- 2

-- 8b2)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia  Vacia  = Vacia
la_concat Vacia  (Nodo a b (restoLista)) = Nodo a b (restoLista)
la_concat (Nodo a b (restoLista)) Vacia  = Nodo a b (restoLista)
la_concat (Nodo a b (restoLista)) lista2 = Nodo a b (la_concat restoLista lista2)

-- ej) *Main> la_concat (Nodo "Nicolas" 18 (Vacia)) (Nodo "Elian" 23 (Vacia))
-- Nodo "Nicolas" 18 (Nodo "Elian" 23 Vacia)

-- 8b3)
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a' b' = Nodo a' b' (Vacia)
la_agregar (Nodo a b (restoLista)) a' b'| a == a' = (Nodo a b' (restoLista))
                                        | a /= a' = (Nodo a b (la_agregar (restoLista) a' b'))

-- ej) *Main> la_agregar (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia))) "Julieta" 18
-- Nodo "Nicolas" 18 (Nodo "Elian" 23 (Nodo "Julieta" 18 Vacia))

-- 8b4)

la_pares :: ListaAsoc a b -> [(a, b)] 
la_pares Vacia = []
la_pares (Nodo a b (restoLista)) = (a, b): la_pares (restoLista)

-- ej) *Main> la_pares (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia)))
-- [("Nicolas",18),("Elian",23)]

-- 8b5)

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b 
la_busca Vacia a' = Nothing
la_busca (Nodo a b (restoLista)) a'| a == a'   = Just b
                                   | otherwise = la_busca (restoLista) a'

-- ej) *Main> la_busca (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia))) "Julieta"
-- Nothing
-- *Main> la_busca (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia))) "Nicolas"
-- Just 18

-- 8b6)

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar a' Vacia = Vacia
la_borrar a' (Nodo a b (restoLista))| a == a'   = restoLista
                                    | otherwise = (Nodo a b (la_borrar a' (restoLista)))
                            
-- ej) *Main> la_borrar "Julieta" (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia)))
-- Nodo "Nicolas" 18 (Nodo "Elian" 23 Vacia)
-- *Main> la_borrar  "Nicolas" (Nodo "Nicolas" 18 (Nodo "Elian" 23 (Vacia)))
-- Nodo "Elian" 23 Vacia