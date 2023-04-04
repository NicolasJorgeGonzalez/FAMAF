haceFrioF :: Float -> Bool
haceFrioF deg | ((deg -32) / 1.8) < 8 = True
              | ((deg -32) / 1.8) >= 8 = False
