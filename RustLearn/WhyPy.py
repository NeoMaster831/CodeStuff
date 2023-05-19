def get_primes(to):
    b = [True for i in range(to + 1)]
    ret = []
    for i in range(2, to + 1):
        if b[i]:
            ret.append(i)
            for j in range(i * 2, to + 1, i):
                b[j] = False
    return ret


print(get_primes(100))