import numpy as np

def dijkstra(graph, source):
    num_vertices = len(graph)
    all_shortest_distances = []

    for src in range(num_vertices):
        # Initialize distances with infinity for all vertices except the source
        distances = [float('inf')] * num_vertices
        distances[src] = 0

        # List to keep track of visited vertices
        visited = [False] * num_vertices

        for _ in range(num_vertices):
            # Find the vertex with the minimum distance
            min_distance = float('inf')
            min_index = -1
            for i in range(num_vertices):
                if not visited[i] and distances[i] < min_distance:
                    min_distance = distances[i]
                    min_index = i

            # Mark the minimum distance vertex as visited
            visited[min_index] = True

            # Update distances for neighboring vertices
            for v in range(num_vertices):
                if (not visited[v]) and (graph[min_index][v] != 0) and (distances[min_index] + graph[min_index][v] < distances[v]):
                    distances[v] = distances[min_index] + graph[min_index][v]

        all_shortest_distances.append(distances)
    
    return all_shortest_distances

# Take user input for the number of vertices
num_vertices = int(input("Enter the number of vertices: "))

# Initialize adjacency matrix with zeros
graph = np.zeros((num_vertices, num_vertices), dtype=int)

# Take user input for edge weights
print("Enter the distances between nodes (use 0 if no direct edge exists):")
for i in range(num_vertices):
    for j in range(num_vertices):
        if i != j:
            weight = int(input(f"Distance from node {i} to node {j}: "))
            graph[i][j] = weight

# Get the shortest distances from all nodes to all other nodes
all_shortest_distances = dijkstra(graph, 0)

print("\nUser input array of distances:")
print(graph)

print("\nShortest distances from all nodes to all other nodes:")
for i, distances in enumerate(all_shortest_distances):
    print(f"From node {i}:", distances)
