def solve():
    V, E = map(int, input().split())
    G = [[] for _ in range(V)]
    for _ in range(E):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        G[u].append(v)

    def dfs(s):
        vis = [False for _ in range(V)]
        vis[s] = True
        st = [s]
        while len(st) > 0:
            u = st.pop()
            for v in G[u]:
                if not vis[v]:
                    st.append(v)
                    vis[v] = True
        return sum(vis) - 1

    ans = sum(dfs(u) for u in range(V))
    print(ans)


TC = int(input())
for _ in range(TC):
    solve()

