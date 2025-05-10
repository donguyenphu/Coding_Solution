inputString = input()
maxLength = 1
tmp = 1

if len(inputString) > 1:
    for i in range(1, len(inputString)):  
        if inputString[i] != inputString[i - 1]:  
            tmp = 1  
        else:
            tmp += 1  

        maxLength = max(maxLength, tmp)  

print(maxLength)