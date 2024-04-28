def hash1(key, size):
    return key % size


def hash2(key, augment):
    return augment - key % augment


def index_from_hashes(key, size, augment, i):
    return (hash1(key, size) + i * hash2(key, augment)) % size


size = 11
augment = 5
print(99 % 17)
while True:
    num = int(input())
    for i in range(0, size):
        print(f"i={i}: {index_from_hashes(num, size, augment, i)}")
