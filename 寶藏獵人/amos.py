from pprint import pprint

def solve():
    try:
        C, R = map(int, input().split())
        K = int(input())
        pos = [map(int, input().split()) for _ in range(K)]
        pos = [(r - 1, c - 1) for (c, r) in pos]
    except EOFError:
        return False

    is_trap = dict()
    dp = dict()
    for r in range(R):
        for c in range(C):
            is_trap[r, c] = False
            dp[r, c] = -1

    for r, c in pos:
        is_trap[r, c] = True

    dp[0, 0] = 0 if is_trap[0, 0] else 1
    for r in range(1, R):
        dp[r, 0] = 0 if is_trap[r, 0] else dp[r - 1, 0]
    for c in range(1, C):
        dp[0, c] = 0 if is_trap[0, c] else dp[0, c - 1]
    for r in range(1, R):
        for c in range(1, C):
            dp[r, c] = 0 if is_trap[r, c] else dp[r - 1, c] + dp[r, c - 1]

    print(dp[R - 1, C - 1])
    return True


while True:
    ok = solve()
    if not ok:
        break
