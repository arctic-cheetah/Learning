

def fibonacci(n):
    if n < 0:
        raise ValueError("invalid index!")
    if n == 0:
        return 0
    if n == 1:
        return 1

    f = [0, 1]
    for i in range(2, n + 1):
        f.append(f[i - 1] + f[i - 2])
    return f[n]

##Testing below
print("Please enter a number")
x = int(input())
x = fibonacci(x)
print(x)


















