def solve():
    N = int(input())
    A = list(input().split())

    cnt = 0
    for r1 in range(N - 1):
        for c1 in range(N - 1):
            for r2 in range(r1 + 1, N):
                for c2 in range(c1 + 1, N):
                    if all(A[r][c] == '1' for r in [r1, r2] for c in [c1, c2]):
                        cnt += 1
    print(cnt)


TC = int(input())
for _ in range(TC):
    solve()
