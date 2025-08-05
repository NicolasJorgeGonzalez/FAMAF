module Dibujo where

-- Definicion  del lenguaje
data Dibujo a = Basica a 
              | Rotar (Dibujo a)
              | Apilar Int Int (Dibujo a) (Dibujo a)
              | Encimar (Dibujo a) (Dibujo a)
              | Resize Int (Dibujo a)
              deriving(Show, Eq)


-- Funcion Map (de Basicas) para nuestro sub-lenguaje.
mapDib :: (a -> b) -> Dibujo a -> Dibujo b
mapDib f (Basica x)         = Basica (f x) 
mapDib f (Rotar d1)         = Rotar (mapDib f d1)
mapDib f (Apilar n m d1 d2) = Apilar n m (mapDib f d1) (mapDib f d2)
mapDib f (Encimar d1 d2)    = Encimar (mapDib f d1) (mapDib f d2)
mapDib f (Resize n1 d1)     = Resize n1 (mapDib f d1)


-- Funcion Fold para nuestro sub-lenguaje.
foldDib :: (a -> b) -> (b -> b) ->
       (Int -> Int -> b -> b -> b) -> 
       (b -> b -> b) ->
       (Int -> b -> b) ->
       Dibujo a -> b

foldDib sB sR sA sEn sRs d =
    let foldDibRecursiva = foldDib sB sR sA sEn sRs
    in case d of
        Basica x -> sB x
        Rotar d -> sR $ foldDibRecursiva d
        Apilar m n d1 d2 -> sA m n (foldDibRecursiva d1) (foldDibRecursiva d2)
        Encimar d1 d2 -> sEn (foldDibRecursiva d1) (foldDibRecursiva d2)
        Resize n1 d1 -> sRs n1 (foldDibRecursiva d1)

--COMPLETAR (EJERCICIO 1-a)
toBool:: Dibujo (Int,Int) -> Dibujo Bool
toBool (Basica(x,y))              | ((x `mod` y) == 0) = Basica (True)
                                  | ((y `mod` x) == 0) = Basica (True)
                                  | otherwise          = Basica (False)
toBool (Rotar(dib))              = Rotar(toBool(dib)) 
toBool (Apilar a b (dib1)(dib2)) = Apilar a b (toBool(dib1)) (toBool(dib2))
toBool (Encimar(dib1)(dib2))     = Encimar(toBool(dib1)) (toBool(dib2))
toBool (Resize n1 (dib))         = Resize n1 (toBool(dib))



--COMPLETAR (EJERCICIO 1-b)
toBool2:: Dibujo (Int,Int) -> Dibujo Bool
toBool2 dibujo = (mapDib (\(x,y) -> (x `mod` y == 0) || (y `mod` x == 0))) dibujo

--COMPLETAR (EJERCICIO 1-c)
profundidad:: Dibujo a -> Int
profundidad (Basica (a))                = 1
profundidad (Rotar (dib))               = 1 + (profundidad(dib))
profundidad (Apilar n1 n2 (dib1)(dib2)) = 1 + (profundidad(dib1) `max` profundidad(dib2))
profundidad (Encimar (dib1)(dib2))      = 1 + (profundidad(dib1) `max` profundidad(dib2))
profundidad (Resize n1 (dib))           = 1 + (profundidad(dib))

--COMPLETAR (EJERCICIO 1-d)
profundidad2:: Dibujo a -> Int
profundidad2 (dib) = foldDib (\x -> 1)(\x -> 1 + x)(\a b x y -> 1 + (x `max` y))(\x y -> 1 + (x `max` y))(\n1 x -> 1 + x) dib
