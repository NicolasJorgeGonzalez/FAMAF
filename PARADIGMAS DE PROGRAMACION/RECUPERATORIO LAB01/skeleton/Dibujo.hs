module Dibujo where

-- Definicion  del lenguaje
data Dibujo a = Basica a 
              | Rotar (Dibujo a)
              | Apilar Int Int (Dibujo a) (Dibujo a)
              | Encimar (Dibujo a) (Dibujo a)
              | Torsion Int Int (Dibujo a)
              deriving(Show, Eq)


-- Funcion Map (de Basicas) para nuestro sub-lenguaje.
mapDib :: (a -> b) -> Dibujo a -> Dibujo b
mapDib f (Basica x)          = Basica (f x) 
mapDib f (Rotar d1)          = Rotar (mapDib f d1)
mapDib f (Apilar n m d1 d2)  = Apilar n m (mapDib f d1) (mapDib f d2)
mapDib f (Encimar d1 d2)     = Encimar (mapDib f d1) (mapDib f d2)
mapDib f (Torsion n1 n2 dib) = Torsion n1 n2 (mapDib f dib)


-- Funcion Fold para nuestro sub-lenguaje.
foldDib :: (a -> b) -> 
           (b -> b) ->
           (Int -> Int -> b -> b -> b) -> 
           (b -> b -> b) ->
           (Int -> Int -> b -> b) ->
           (Dibujo a) -> b

foldDib sB sR sA sEn sTs d =
    let foldDibRecursiva = foldDib sB sR sA sEn sTs
    in case d of
        Basica x          -> sB x
        Rotar d           -> sR $ foldDibRecursiva d
        Apilar m n d1 d2  -> sA m n (foldDibRecursiva d1) (foldDibRecursiva d2)
        Encimar d1 d2     -> sEn (foldDibRecursiva d1) (foldDibRecursiva d2)
        Torsion n1 n2 dib -> sTs n1 n2 (foldDibRecursiva dib)



--COMPLETAR (EJERCICIO 1-a)
mapToBool:: Dibujo (String, Int) -> Dibujo Bool
mapToBool (Basica (str,n))         | ((length str) == n) = Basica True
                                   | otherwise           = Basica False
mapToBool (Rotar dib)              = Rotar (mapToBool dib)
mapToBool (Apilar n1 n2 dib1 dib2) = Apilar n1 n2 (mapToBool dib1)(mapToBool dib2)
mapToBool (Encimar dib1 dib2)      = Encimar (mapToBool dib1)(mapToBool dib2)
mapToBool (Torsion n1 n2 dib)      = Torsion n1 n2 (mapToBool dib)

--COMPLETAR (EJERCICIO 1-b)
mapToBool2 ::Dibujo (String, Int) -> Dibujo Bool
mapToBool2 dib = (mapDib (\(str,n) -> ((length str) == n))) dib


--COMPLETAR (EJERCICIO 1-c)
dibujoToText:: Dibujo String -> String
dibujoToText (Basica str)             = str
dibujoToText (Rotar dib)              = dibujoToText dib
dibujoToText (Apilar n1 n2 dib1 dib2) = (dibujoToText dib1) ++ (dibujoToText dib2)
dibujoToText (Encimar dib1 dib2)      = (dibujoToText dib1) ++ (dibujoToText dib2)
dibujoToText (Torsion n1 n2 dib)      = dibujoToText dib

-- COMPLETAR (EJERCICIO 1-d)
dibujoToText2:: (Dibujo String) -> String
dibujoToText2 (dib) = foldDib (\x -> x)(\x -> x)(\a b x y -> (x ++ y))(\x y -> (x ++ y))(\a b x -> x) dib
