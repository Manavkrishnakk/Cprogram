#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX], rank[MAX]; 
int nodes[MAX]; 
int n; 


int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}


void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}


int compare(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2]; 
}

void kruskal(int edges[MAX * (MAX - 1) / 2], int edge_count) {
    int total_cost = 0;
    int mst_edges = 0;

  
    qsort(edges, edge_count, sizeof(int) * 3, compare);

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < edge_count; i++) {
        int u = edges[i * 3];     
        int v = edges[i * 3 + 1];  
        int weight = edges[i * 3 + 2];

     
        if (find(u) != find(v)) {
            union_sets(u, v);
            printf("Edge %d -> %d (Weight: %d)\n", nodes[u], nodes[v], weight);
            total_cost += weight;
            mst_edges++;

          
            if (mst_edges == n - 1)
                break;
        }
    }

    if (mst_edges == n - 1)
        printf("\nTotal cost of the Minimum Spanning Tree: %d\n", total_cost);
    else
        printf("\nMST could not be formed.\n");
}

int main() {
    printf("\n\t\t<<<<<< KRUSKAL'S ALGORITHM >>>>>>\n\n");

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

 
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &nodes[i]);
    }

  
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int edges[MAX * (MAX - 1) / 2]; 
    int edge_count = 0;

   
    printf("\nEnter the adjacency matrix (weights of edges, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight;
            printf("Weight between %d and %d: ", nodes[i], nodes[j]);
            scanf("%d", &weight);
            if (weight != 0) {
              
                edges[edge_count * 3] = i;    
                edges[edge_count * 3 + 1] = j; 
                edges[edge_count * 3 + 2] = weight;
                edge_count++;
            }
        }
    }
    kruskal(edges, edge_count);

    return 0;
}
