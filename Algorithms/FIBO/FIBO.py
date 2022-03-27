def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        i = 1
        a, b = 0, 1
        while i < n:
            temp = b
            b = a + b
            a = temp
            i += 1
        return b


if __name__ == '__main__':
    print(fib(23))
