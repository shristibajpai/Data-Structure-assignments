
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX] = {0};
int visited[MAX];
int n;

// Safe integer input
int readInt()
{
    char line[100];
    int value;
    char extra;

    while (1)
    {
        if (fgets(line, sizeof(line), stdin) == NULL)
            exit(0);

        if (sscanf(line, " %d %c", &value, &extra) == 1)
            return value;

        printf("Invalid input! Enter an integer: ");
    }
}

// Add connection
void addConnection(int a, int b)
{
    graph[a][b] = 1;
    graph[b][a] = 1;

    printf("Connection added successfully!\n");
}

// BFS Traversal
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, current;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// DFS Traversal
void DFS(int start)
{
    int i;

    visited[start] = 1;
    printf("%d ", start);

    for (i = 0; i < n; i++)
    {
        if (graph[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Main Function
int main()
{
    int choice, a, b, start, i;

    printf("Enter number of users (max 10): ");
    n = readInt();

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of users!\n");
        return 0;
    }

    do
    {
        printf("\n--- Social Network ---\n");
        printf("1. Add Connection\n");
        printf("2. BFS\n");
        printf("3. DFS\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1:
                printf("Enter first user (0 to %d): ", n - 1);
                a = readInt();

                printf("Enter second user (0 to %d): ", n - 1);
                b = readInt();

                if (a >= 0 && a < n && b >= 0 && b < n)
                    addConnection(a, b);
                else
                    printf("Invalid users!\n");

                break;

            case 2:
                printf("Enter starting user: ");
                start = readInt();

                if (start >= 0 && start < n)
                    BFS(start);
                else
                    printf("Invalid user!\n");

                break;

            case 3:
                printf("Enter starting user: ");
                start = readInt();

                if (start >= 0 && start < n)
                {
                    for (i = 0; i < n; i++)
                        visited[i] = 0;

                    printf("DFS: ");
                    DFS(start);
                    printf("\n");
                }
                else
                {
                    printf("Invalid user!\n");
                }

                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
