rangoPrecioParametrizado :: Float -> (Float, Float) -> String
rangoPrecioParametrizado precio (menor, mayor) | precio < menor && precio >= 0 = "muy barato"
                                               | precio >= menor && precio <= mayor = "hay que verlo bien"
                                               | precio > mayor = "demasiado caro"
                                               | precio < 0 = "esto no puede ser" 