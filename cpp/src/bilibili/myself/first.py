def getMultiplier(source):
    index = source.find('+')
    if index > 0:
        return (int(source[0:index]),int(source[index+1:-1]))
    else:
        index = source.find('-')
        return (int(source[0:index]), - int(source[index+1:-1]))



a,b=getMultiplier(input())
c,d=getMultiplier(input())

print(str((a*c-b*d))+"+"+str((a*d+b*c))+"i")