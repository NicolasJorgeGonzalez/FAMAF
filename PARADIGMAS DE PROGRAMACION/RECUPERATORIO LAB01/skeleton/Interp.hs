module Interp where
import Dibujo
import Graphics.Gloss
import Graphics.Gloss.Data.Vector
import qualified Graphics.Gloss.Data.Point.Arithmetic as V

type ImagenFlotante = Vector -> Vector -> Vector -> Picture

formaF :: Color -> ImagenFlotante
formaF col d w h = color col (line . map (d V.+) $
    [ vCero, uX, p13, p33, p33 V.+ uY , p13 V.+ uY
    , uX V.+ 4 V.* uY ,uX V.+ 5 V.* uY, x4 V.+ y5
    , x4 V.+ 6 V.* uY, 6 V.* uY, vCero])
  where p33   = 3 V.* (uX V.+ uY)
        p13   = uX V.+ 3 V.* uY
        x4    = 4 V.* uX
        y5    = 5 V.* uY
        uX    = (1/6) V.* w
        uY    = (1/6) V.* h
        vCero = (0,0)

cuadrado :: Color -> ImagenFlotante
cuadrado col d w h = color col (line . map (d V.+) $
  [vCero, x1, x1y1, y1, vCero])
  where
    uX    = w
    uY    = h
    vCero = (0, 0)
    x1    = w
    y1    = h
    x1y1  = w V.+ h

interp_rotar :: ImagenFlotante -> ImagenFlotante
interp_rotar imagen d w h = imagen (d V.+ w) h (V.negate w)


interp_apilar :: Int -> Int -> ImagenFlotante -> ImagenFlotante -> ImagenFlotante
interp_apilar n m imagen1 imagen2 x w h =
    let r' = fromIntegral n / fromIntegral (n + m)
        r  = fromIntegral m / fromIntegral (n + m)
        h' = r' V.* h
    in pictures [imagen1 (x V.+ h') w (r V.* h), imagen2 x w h']


interp_encimar :: ImagenFlotante -> ImagenFlotante -> ImagenFlotante
interp_encimar imagen1 imagen2 x w h = pictures [imagen1 x w h, imagen2 x w h]


--COMPLETAR (EJERCICIO 2-a)
interp_basica :: (Int, Int) -> ImagenFlotante
interp_basica (x,y) | (x > y)  = formaF(blue)
                    | (x == y) = cuadrado(green)
                    | (x < y)  = formaF(red)

--COMPLETAR (EJERCICIO 2-b)
interp :: Dibujo (Int, Int) -> ImagenFlotante
interp (Basica (x,y))           = interp_basica (x,y)
interp (Rotar dib)              = interp_rotar (interp dib)
interp (Apilar n1 n2 dib1 dib2) = interp_apilar n1 n2 (interp dib1)(interp dib2)
interp (Encimar dib1 dib2)      = interp_encimar(interp dib1)(interp dib2)
interp (Torsion n1 n2 dib)      = interp_torsion n1 n2 (interp dib)

--COMPLETAR (EJERCICIO 3)
interp_torsion :: Int -> Int -> ImagenFlotante -> ImagenFlotante
interp_torsion x y imagen d w h =
  let fx = fromIntegral (x * 10) / 100
      fy = fromIntegral (y * 10) / 100
  in imagen d (w V.+ (fx V.* h)) (h V.+ (fy V.* w))