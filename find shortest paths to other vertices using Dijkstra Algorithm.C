#include <stdio.h>
#include <limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int distance[MAX];
    int visited[MAX];
    int i, j, min, u;

    // Initialize distances and visited array
    for (i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from source to itself is 0
    distance[source] = 0;

    // Find shortest path
    for (i = 0; i < n - 1; i++)
    {
        min = INT_MAX;
        u = -1;

        // Find the unvisited vertex with minimum distance
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }

        // If no reachable vertex remains
        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] != 0 &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    // Display shortest distances
    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
            printf("Vertex %d -> INF\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
