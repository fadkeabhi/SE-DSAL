class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[0] * vertices for _ in range(vertices)]

    def print_solution(self, distance):
        print("Vertex \t Distance from Source")
        for i in range(self.vertices):
            print(f"{i}\t\t{distance[i]}")

    def min_distance(self, distance, visited):
        min_dist = float('inf')
        min_index = -1

        for v in range(self.vertices):
            if distance[v] < min_dist and not visited[v]:
                min_dist = distance[v]
                min_index = v

        return min_index

    def dijkstra(self, source):
        distance = [float('inf')] * self.vertices
        distance[source] = 0
        visited = [False] * self.vertices

        for _ in range(self.vertices):
            u = self.min_distance(distance, visited)
            visited[u] = True

            for v in range(self.vertices):
                if (
                    self.graph[u][v] > 0
                    and not visited[v]
                    and distance[v] > distance[u] + self.graph[u][v]
                ):
                    distance[v] = distance[u] + self.graph[u][v]

        self.print_solution(distance)


# Example usage:
g = Graph(5)
g.graph = [
    [0, 4, 0, 0, 1],
    [4, 0, 8, 0, 0],
    [0, 8, 0, 3, 0],
    [0, 0, 3, 0, 6],
    [1, 0, 0, 6, 0]
]
source_vertex = 0
g.dijkstra(source_vertex)
