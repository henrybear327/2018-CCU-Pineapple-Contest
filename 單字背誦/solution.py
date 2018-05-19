# Usage:
#     python3 main.py < in > out
# Verify with:
#     cat out | grep Lucky | wc -l
#     Should be about half of the number of testcases


def solve():
    N = int(input())
    head_cnt = [0 for _ in range(26)]
    tail_cnt = [0 for _ in range(26)]

    for _ in range(N):
        s = input()
        head_cnt[ord(s[0]) - ord('a')] += 1
        tail_cnt[ord(s[-1]) - ord('a')] += 1

    if all(head_cnt[c] == tail_cnt[c] for c in range(26)):
        print('Lucky')
    else:
        print('QAQ')


TC = int(input())
for _ in range(TC):
    solve()
