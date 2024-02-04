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

data Cola = VaciaC | Encolada Deportista Cola

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ restocola) = Just restocola

encolar :: Deportista -> Cola -> Cola
encolar deportista VaciaC = Encolada deportista VaciaC
encolar deportista (Encolada deportistas restocola) = Encolada deportistas (Encolada deportista VaciaC)

busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC zona = Nothing
busca (Encolada (Futbolista zonas n p a) restocola) zona | zonas == zona = Just (Futbolista zona n p a)
                                                         | otherwise = (busca restocola zona)

data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving Show

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

la_long :: ListaAsoc a b -> Int 
la_long Vacia = 0
la_long (Nodo a b restoLista) = 1 + la_long restoLista

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia Vacia = Vacia
la_concat Vacia lista2 = lista2
la_concat lista1 Vacia = lista1
la_concat (Nodo a b restocola) lista2 = Nodo a b (la_concat restocola lista2) 

la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a b = Nodo a b Vacia
la_agregar (Nodo x y restocola) a b | x == a = (Nodo x b restocola)  
                                    | otherwise = Nodo x y (la_agregar restocola a b)

la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b restocola) = (a,b) : la_pares restocola

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia clave = Nothing
la_busca (Nodo a b restocola) clave | a == clave = Just b 
                                    | otherwise = la_busca restocola clave