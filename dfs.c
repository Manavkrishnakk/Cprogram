#include<stdio.h>
#define max 100

int visited[max] = {0};
int graph[max][max];
int nodes[max];
int stack[max];
int n, i, j, e, start, top = -1;

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stack is full..\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty..\n");
    }
    else
    {
        top--;
    }
}

void bfs(int z)
{
    visited[z] = 1;
    push(z);
    while (top != -1)
    {
        int remove = stack[top];
        pop();
        printf("%d->",nodes[remove]);  

        for (i = 0; i < n; i++)
        {
            if (graph[remove][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                push(i);
            }
        }
    }
}

int main()
{
    printf("Enter the no of nodes:");
    scanf("%d", &n);
    printf("Enter the node values:\n");
    for (i = 0; i < n; i++)
    {
        printf("node %d:", i + 1);
        scanf("%d", &nodes[i]);
    }

    printf("answer the questions..\n");
    printf("enter 1:edge between nodes\n\nenter 0:no edge between nodes\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("edge %d and %d:", nodes[i], nodes[j]);
            scanf("%d", &e);
            if (e == 1)
            {
                graph[i][j] = graph[j][i] = 1;
            }
            else
            {
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }

    printf("enter the starting node:");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
    {
        if (start == nodes[i])
        {
            bfs(i); 
            break;
        }
    }
    return 0;
}
