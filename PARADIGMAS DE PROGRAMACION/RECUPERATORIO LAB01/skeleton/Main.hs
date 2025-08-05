module Main where
import Dibujo
import Interp
import Graphics.Gloss
import System.Environment

--Expresiones de Dibujo (String,Int) para Testing Sintactico 
dib1 = Basica ("Hola",4)
dib2 = Basica ("Chau",2)
dib3 = Rotar dib1
dib4 = Rotar dib2
dib5 = Apilar 1 1 dib1 dib2
dib6 = Encimar dib1 dib2
dib7 = Encimar dib4 (Rotar dib5)


main :: IO ()
main = do
    args <- getArgs
    let ej = head args

    case ej of
        "1a" -> do
            putStrLn "TESTING FUNCION mapToBool:"
            if mapToBool dib1 == Basica True then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool dib2 == Basica False then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool dib3 == Rotar (Basica True) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool dib4 == Rotar (Basica False) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool dib5 == Apilar 1 1 (Basica True) (Basica False) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool dib6 == Encimar (Basica True) (Basica False) then putStrLn "Ok" else putStrLn "Fail"
        

        "1b" -> do
            putStrLn "TESTING FUNCION mapToBool2:"
            if mapToBool2 dib1 == Basica True then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool2 dib2 == Basica False then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool2 dib3 == Rotar (Basica True) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool2 dib4 == Rotar (Basica False) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool2 dib5 == Apilar 1 1 (Basica True) (Basica False) then putStrLn "Ok" else putStrLn "Fail"
            if mapToBool2 dib6 == Encimar (Basica True) (Basica False) then putStrLn "Ok" else putStrLn "Fail"

        "1c" -> do
            putStrLn "TESTING FUNCION dibujoToText:"
            if dibujoToText (Basica "Hola") == "Hola" then putStrLn "Ok" else putStrLn "Fail"
            if dibujoToText (Encimar (Basica "Hola") (Basica "Mundo")) == "HolaMundo"then putStrLn "Ok" else putStrLn "Fail"
            if dibujoToText (Encimar (Basica "Hola") (Apilar 1 1 (Basica "Chau") (Rotar (Basica "Mundo")))) == "HolaChauMundo"then putStrLn "Ok" else putStrLn "Fail"
            
        "1d" -> do
            putStrLn "TESTING FUNCION dibujoToText2:"
            if dibujoToText2 (Basica "Hola") == "Hola" then putStrLn "Ok" else putStrLn "Fail"
            if dibujoToText2 (Encimar (Basica "Hola") (Basica "Mundo")) == "HolaMundo"then putStrLn "Ok" else putStrLn "Fail"
            if dibujoToText2 (Encimar (Basica "Hola") (Apilar 1 1 (Basica "Chau") (Rotar (Basica "Mundo")))) == "HolaChauMundo"then putStrLn "Ok" else putStrLn "Fail"
        
        "2a" -> do
            putStrLn "TESTING FUNCION INTERP_BASICA:"
            let win = InWindow "Paradigmas 2025 - Rec. Parcial 1" (1000,1000) (0,0)
            display win white ( interp_apilar 1 1 (interp_apilar 1 1 (interp_basica (4,2)) (interp_basica (3,3))) (interp_basica (2,4))  (0,0) (400,0) (0,400) )  

        "2b" -> do
            putStrLn "TESTING FUNCION INTERP:"
            let win = InWindow "Paradigmas 2025 - Rec. Parcial 1" (1000,1000) (0,0)
                dib = (Apilar 1 1 (Rotar (Basica (1,3))) (Basica (2,2))) 
            display win white (interp dib (0,0) (100,0) (0,100))  

        "3" -> do
            putStrLn "TESTING OPERADOR TORSION:"
            let win = InWindow "Paradigmas 2025 - Rec. Parcial 1" (1000,1000) (0,0)
                dib = (Torsion 2 3 (Basica (3,4)))     
            display win white (interp dib (0,0) (100,0) (0,100))

        otherwise -> putStrLn "Numero de Ejercicio Incorrecto"

