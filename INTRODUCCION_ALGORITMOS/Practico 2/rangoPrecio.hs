rangoPrecio :: Int -> String
rangoPrecio precio | precio<2000 && precio>=0 = "Muy barato"
                   | precio>5000 = "Demasiado caro"
                   | 2000<= precio && precio<= 5000 = "Hay que verlo bien"
                   | precio<0 = "Esto no puede ser"