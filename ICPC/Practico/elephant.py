if __name__ == "__main__":

    f_house: int = int(input())
    elephant_s = 0

    while f_house != 0:
        if f_house >= 5:
            f_house -= 5
            elephant_s += 1

        elif f_house >= 4:
            f_house -= 4
            elephant_s += 1

        elif f_house >= 3:
            f_house -= 3
            elephant_s += 1

        elif f_house >= 2:
            f_house -= 2
            elephant_s += 1

        elif f_house >= 1:
            f_house -= 1
            elephant_s += 1

    

    print(elephant_s)