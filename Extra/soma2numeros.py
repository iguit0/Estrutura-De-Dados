def solution1(values, expected):
    dic = {}
    for index, value in enumerate(values):
        dic[value] = index
        diff = expected - value
        if diff not in dic:
            continue
        if dic[diff] != index:
            return True
    return False

def solution2(values, expected):
    dic = {}
    for index, value in enumerate(values):
        diff = expected - value
        if diff not in dic:
            dic[value] = index
            continue
        return True
    return False

if __name__ == "__main__":
    values = [42,5,9,9,16,16,13]

    print("Solucao 1")

    print(solution1(values, 14))
    print(solution1(values, 25))
    print(solution1(values, 47))
    print(solution1(values, 58))
    print(solution1(values, 51))
    print(solution1(values, 21))
    print(solution1(values, 18))

    print(solution1(values, 32))
    print(solution1(values, 9))
    print(solution1(values, 59))
    print(solution2(values, 5))
    print(solution2(values, 10))
    print(solution2(values, 100))

    print("Solução 2")

    print(solution2(values, 14))
    print(solution2(values, 25))
    print(solution2(values, 47))
    print(solution2(values, 58))
    print(solution2(values, 32))
    print(solution2(values, 18))
    print(solution1(values, 51))
    print(solution1(values, 21))

    print(solution2(values, 10))
    print(solution2(values, 9))
    print(solution2(values, 59))
    print(solution2(values, 5))
    print(solution2(values, 100))
