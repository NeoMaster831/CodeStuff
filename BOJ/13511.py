import math
import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

class Tree:
    def __init__(self, n):
        self.n = n
        self.graph = defaultdict(list)
        self.depth = [-1] * (n + 1)
        self.parent = [[-1 for _ in range(20)] for _ in range(n + 1)]
        self.dist = [0] * (n + 1)

    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))

    def dfs(self, node, parent, depth, distance):
        self.depth[node] = depth
        self.parent[node][0] = parent
        self.dist[node] = distance

        for v, w in self.graph[node]:
            if v != parent:
                self.dfs(v, node, depth + 1, distance + w)

    def preprocess(self):
        self.dfs(1, -1, 0, 0)
        for j in range(1, 20):
            for i in range(1, self.n + 1):
                if self.parent[i][j - 1] != -1:
                    self.parent[i][j] = self.parent[self.parent[i][j - 1]][j - 1]

    def lca(self, u, v):
        if self.depth[u] < self.depth[v]:
            u, v = v, u

        diff = self.depth[u] - self.depth[v]

        for i in range(20):
            if diff & (1 << i):
                u = self.parent[u][i]

        if u == v:
            return u

        for i in range(19, -1, -1):
            if self.parent[u][i] != self.parent[v][i]:
                u = self.parent[u][i]
                v = self.parent[v][i]

        return self.parent[u][0]

    def distance(self, u, v):
        lca_node = self.lca(u, v)
        return self.dist[u] + self.dist[v] - 2 * self.dist[lca_node]
    
    def kth_vertex(self, u, v, k):
        lca_node = self.lca(u, v)
        if k <= self.depth[u] - self.depth[lca_node] + 1:
            # kth vertex is on the path from u to LCA
            distance = k - 1
            while distance > 0:
                i = int(math.log2(distance))
                u = self.parent[u][i]
                distance -= (1 << i)
            return u
        else:
            distance = self.depth[u] + self.depth[v] - 2 * self.depth[lca_node] + 1 - k
            while distance > 0:
                i = int(math.log2(distance))
                v = self.parent[v][i]
                distance -= (1 << i)
            return v

n = int(input())
tree = Tree(n)
for i in range(n-1):
    u, v, w = map(int, input().split())
    tree.add_edge(u, v, w)
tree.preprocess()


m = int(input())
for i in range(m):
    l = input().split()
    for j in range(len(l)):
        l[j] = int(l[j])
    if l[0] == 1:
        print(tree.distance(l[1], l[2]))
    elif l[0] == 2:
        print(tree.kth_vertex(l[1], l[2], l[3]))