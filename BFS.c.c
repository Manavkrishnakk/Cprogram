


#include <stdio.h>

#define MAX 100

void bfs(int graph[][MAX], int numVertices, int startVertex)
{
   int visited[MAX] = {0};
   int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front <rear) 
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) 
        {
            if (graph[currentVertex][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n\n");
}

int main() {
    int numVertices, startVertex, edges;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX][MAX] = {{0}};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the pair of vertex if they have an edge between them:");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    printf("\nEnter the start vertex: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices+1) {
        printf("\nInvalid start vertex. Please try again.\n");
        return 1;
    }

    bfs(graph, numVertices+1, startVertex);
    return 0;
}
