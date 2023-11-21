import hashlib

inp = input()
print(hashlib.sha256(b'Sxww0UEB' + inp.encode()).hexdigest())