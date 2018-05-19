def solve():
    T = int(input())
    if T == -1:
        return True

    total = 0
    for _ in range(T):
        week = 0
        while True:
            t = int(input())
            if t == 0:
                break
            week += t
        wage = 140 if week <= 50 else 280 if week <= 65 else 420
        total += week * wage

    print(total)
    return False


while True:
    eof = solve()
    if eof:
        break
