def solve():
    income = int(input())
    N = int(input())
    p = [int(input()) for _ in range(N)]
    balance = income - sum(p)
    print(balance)

TC = int(input())
for _ in range(TC):
    solve()
