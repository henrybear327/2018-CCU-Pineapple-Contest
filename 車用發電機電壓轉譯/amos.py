def solve():
    L = input()
    H = input()
    Q = input()
    idx = next(i for i in range(len(L)) if L[i] != H[i])
    print(int(Q[idx:idx+7], base=2))

TC = int(input())
for _ in range(TC):
    solve()
