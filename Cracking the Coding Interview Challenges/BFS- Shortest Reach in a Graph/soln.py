class Graph(object):
    def __init__(self,n):
        self.n = n
        self.nodes = range(0,n)
        self.edges = dict()

    def connect(self,a,b):
        if a not in self.edges.keys():
            self.edges[a] = []
        if b not in self.edges.keys():
            self.edges[b] = []
        self.edges[a].append(b)
        self.edges[b].append(a)

    def mst_update(self,start):
        if start not in self.edges.keys():
            return
        to_process = []
        for nbr in self.edges[start]:
            d = self.distances[start] + 6
            if self.distances[nbr]==-1 or self.distances[nbr] > d:
                self.distances[nbr] = d
                to_process.append(nbr)
        for nbr in to_process:
            self.mst_update(nbr)

    def find_all_distances(self,start):
        self.distances = [-1 for i in range(0,n)]
        self.distances[start] = 0
        self.mst_update(start)
        res = ""
        for i,node in enumerate(self.distances):
            if i != start:
                res = res + str(node) + " "
        print(res)

t = int(input())
for i in range(t):
    n,m = [int(value) for value in input().split()]
    graph = Graph(n)
    for i in range(m):
        x,y = [int(x) for x in input().split()]
        graph.connect(x-1,y-1)
    s = 1
    try:
        s = int(input())
    except (EOFError):
        pass
    graph.find_all_distances(s-1)
