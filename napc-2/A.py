def fact(n):
    ans = 1
    for i in range (1, n + 1):
        ans *= i
    return ans

n = int(input())
ans = fact(n) * fact(n) / (n**n)
print('%.2f' % ans)