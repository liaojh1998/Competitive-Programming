def sigma(nom, dem, n):
    i = 1
    s = 0
    while n != 0:
        t = 0
        #Add away integer sum
        t += ((nom//dem)-1)*n*(n+1)//2
        #Rayleigh's theorem
        nom %= dem
        np = nom*n//dem
        t += (n+np)*(n+np+1)//2
        #Recursion
        if i == 1:
            s += t
        else:
            s -= t
        i ^= 1
        #Next complement
        n = np
        t = nom
        nom += dem
        dem = t
    return s

if __name__ == '__main__':
    #Beatty's sequence sum solved using Rayleigh's theorem
    #Decimal runtime way slower than using fraction
    nom = 1
    dem = 1
    count = 2675 #e accurate to 8000 digits
    i = 1
    while i <= count:
        nom = nom*i+1
        dem *= i
        i += 1
    n = int(input())
    s = sigma(nom, dem, n)
    print(s)
