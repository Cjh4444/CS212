def hash(key, n, r):
    key_string = str(key**2)
    length = len(key_string)
    start = 0
    end = 0
    if length % 2 == 0:
        start = int((length - r) / 2)
        end = int((length + r) / 2)
    else:
        mid = int(length / 2)
        half_r = int(r / 2)
        start = mid - half_r
        end = mid + half_r + 1

    return int(key_string[start:end]) % n


while True:
    key = int(input("key: "))
    N = int(input("N: "))
    R = int(input("R: "))

    print(hash(key, N, R))
