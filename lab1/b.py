def binpow(a, n, mod):
    res = 1
    while n != 0:
        if (n&1):
            res = res * a % mod
        a = a * a % mod
        n >>=1
    return res


a, n, mod = map(int, input().split())
if mod == 1:
    print(0)
else:
    print(binpow(a, n, mod))