from collections import namedtuple
from pprint import pprint

Seg = namedtuple('Seg', ['s', 'e', 'w'])

def solve():
    N = int(input())

    segs = []
    for _ in range(N):
        s, e, w = map(int, input().split())
        segs.append(Seg(s, e, w))

    segs = sorted(segs, key=lambda seg: (seg.e, seg.s))

    # dp[i] = 使用前 i + 1 個區間，且第 i 個區間必選，所能達到的最大學分數
    # dp[i] = max(dp[j] | 0 <= j < i and segs[j].e <= segs[i].s) + segs[i].w
    # Since there are empty segments, usual overlap checking code is useless.
    # def is_overlap(a, b): a.s <= b.s < a.e or b.s <= a.e < b.e
    # 1
    # 2
    # 22 22 4
    # 22 23 4
    # => NOT overlap
    dp = [-1 for _ in range(N)]
    for i in range(N):
        candidates = [dp[j] for j in range(i) if segs[j].e <= segs[i].s]
        dp[i] = max(candidates, default=0) + segs[i].w

    ans = max(dp)
    print(ans)


TC = int(input())
for _ in range(TC):
    solve()
