def solve():
    Y, X = map(float, input().split())

    m = 0
    while Y > 0:
        Y = Y * (1 + 0.00054)**30
        m += 1
        Y = Y - X

    print(m)

TC = int(input())
for _ in range(TC):
    solve()
