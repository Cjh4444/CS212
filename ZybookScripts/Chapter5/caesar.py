def caesar(key, shift):
    return "".join(
        chr(((ord(letter) - 97 + shift) % 26) + 97) for letter in key
    )


while True:
    print(caesar(input("key: "), int(input("shift: "))))
