def search(val, max, i, c1=2, c2=2):
    return (val % max + c1 * i + c2 * i * i) % max


# example use in a `for` loop to hash 61 for an 11-entry hash table
size = 11

while True:
    num = int(input())
    for i in range(0, size):
        print(f"i={i}: {search(num, size, i)}")
