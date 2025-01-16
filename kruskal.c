
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INFINITY 999

int parent[MAX];
int n;

int find(int x) {
    while (parent[x]) {
        x = parent[x];
    }
    return x;
}

int uni(int x, int y) {
    if (x != y) {
        parent[y] = x;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, count = 0, edge1, edge2, edge_count, min_cost;
    int cost[MAX][MAX], row_no, colom_no, sum_cost = 0;

    // Initialize parent array
    for (i = 0; i < MAX; i++) {
        parent[i] = 0;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <=n; i++) {
        for (j = 1; j<= n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INFINITY; // Treat 0 as "no edge" only for i != j
            }
        }
    }

    edge_count = n - 1; // MST will have n-1 edges

    while (count < edge_count) {
        min_cost = INFINITY; // Reset min_cost for each iteration

        // Find the minimum cost edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min_cost) {
                    min_cost = cost[i][j];
                    edge1 = row_no = i;
                    edge2 = colom_no = j;
                }
            }
        }

        // Perform union-find to check if adding this edge creates a cycle
        row_no = find(row_no);
        colom_no = find(colom_no);
        if (uni(row_no, colom_no)) {
            printf("Edge (%d -> %d) = %d\n", edge1, edge2, min_cost);
            sum_cost += min_cost;
            count++; // Increment the edge county
        }

        // Mark the edge as used
        cost[edge1][edge2] = cost[edge2][edge1] = INFINITY;
    }

    printf("Total cost = %d\n", sum_cost);
    return 0;
}
