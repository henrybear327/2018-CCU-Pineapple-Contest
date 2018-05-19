def solve():
    M, R, Q = map(float, input().split())
    for _ in range(int(Q)):
        sell = M * 10 * (1 + 0.085)
        loan = M * 9 * (1 + R)
        M = sell - loan
    print(f'{M:.2f}')


TC = int(input())
for _ in range(TC):
    solve()
