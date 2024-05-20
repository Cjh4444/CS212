def getParent(index: int):
    return (index - 1) // 2


def getChildren(index: int):
    return (2 * index + 1, 2 * index + 2)


print(getChildren(1))
