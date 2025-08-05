def main():
    t = int(input())
    output = []
    for tries in range(t):
        
        n, c, q = map(int, input().split())
        s = input()

        for i in range(c):
            num1, num2 = map(int, input().split())

            new_string = ""
            for j in range(num1, num2 + 1):
                new_string += s[j - 1]
        
            s += new_string

        nums = []
        for i in range(q):
            nums.append(int(input()))
        
        for i in range(len(nums)):
            output.append(s[nums[i] - 1])
    
    for i in range(len(output)):
        print((output[i]))

if __name__ == "__main__":
    main()
