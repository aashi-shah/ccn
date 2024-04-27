#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[20];
};

int minDistance(int dist[], int sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], struct Node nodes[], int V, int source)
{
    printf("\nShortest distances from node %s:\n", nodes[source].name);
    printf("Node\tDistance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%s\t%d\n", nodes[i].name, dist[i]);
    }
}

void dijkstra(int **graph, int src, struct Node nodes[], int V)
{
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, nodes, V, src);
}

int main()
{
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    struct Node nodes[V];
    int **graph;
    graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    printf("Enter details for each node:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Enter name for node %d: ", i + 1);
        scanf("%s", nodes[i].name);
    }
    printf("\nEnter the adjacency matrix for the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("Enter weight for edge between %s and %s: ", nodes[i].name, nodes[j].name);
            scanf("%d", &graph[i][j]);
        }
    }
    for (int source = 0; source < V; source++)
    {
        dijkstra(graph, source, nodes, V);
    }

    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
}