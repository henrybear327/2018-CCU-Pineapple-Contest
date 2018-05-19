# Usage:
#     python3 solution.py < in > out

import math


def solve():
    N, K = map(int, input().split())
    KK = math.floor(math.log(K, 2)) + 1
    p = list(map(int, input().split()))

    dp = dict()
    for u in range(N):
        dp[0, u] = p[u]
    for i in range(1, KK):
        for u in range(N):
            dp[i, u] = dp[i - 1, dp[i - 1, u]]

    movement = [i for i in range(KK) if (K & (1 << i))]
    def nxtK(u):
        for m in movement:
            u = dp[m, u]
        return u

    ans = [u for u in range(N) if nxtK(u) == 0]
    if ans:
        print(' '.join(map(str, ans)))
    else:
        print('-1')


TC = int(input())
for _ in range(TC):
    solve()
