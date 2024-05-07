def hash(key, init_val, mult):
    string_hash = init_val

    for letter in key:
        string_hash = (string_hash * mult) + ord(letter)

    return string_hash


while True:
    key = input("key: ")
    init_val = int(input("init_val: "))
    mult = int(input("mult: "))
    print(str(hash(key, init_val, mult)))
