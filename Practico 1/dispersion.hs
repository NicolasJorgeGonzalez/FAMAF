dispersion :: Float -> Float -> Float -> Float
dispersion num1 num2 num3 = ((num1 `max` num2) `max` num3) - ((num1 `min` num2) `min` num3)