data Carrera = Matematica | Fisica | Computacion | Astronomia
--B
titulo :: Carrera -> String
titulo Matematica  = "Licenciatura en Matematicas"
titulo Fisica      = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Astronomia  = "Licenciatura en Astronomia"

--C
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si 
                  deriving (Eq, Bounded)

--D
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do  = 'C'
cifradoAmericano Re  = 'D'
cifradoAmericano Mi  = 'E'
cifradoAmericano Fa  = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La  = 'A'
cifradoAmericano Si  = 'B'



