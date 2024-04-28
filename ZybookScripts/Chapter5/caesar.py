def caesar(key, shift):
    return "".join(chr(ord(letter) + shift) for letter in key)


while True:
    print(caesar(input("key: "), int(input("shift: "))))
