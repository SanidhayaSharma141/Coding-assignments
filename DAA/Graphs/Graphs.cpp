#include <bits/stdc++.h>
#include "Graphs.h"
using namespace std;
struct Edge;
struct Vertex
{
    int data;
    struct Vertex *next;
    struct Edge *firstEdge;
    Vertex(int data, struct Vertex *next, struct Edge *firstEdge)
    {
        this->data = data;
        this->next = next;
        this->firstEdge = firstEdge;
    }
};
typedef struct Vertex ver;
struct Edge
{
    ver *destination_ver;
    struct Edge *nextEdge;
    Edge(ver *destination_ver, struct Edge *nextEdge)
    {
        this->destination_ver = destination_ver;
        this->nextEdge = nextEdge;
    }
};
typedef struct Edge edge;

struct Graph
{
    ver *vertex;
    ver *firstVertex;
    Graph(ver *vertex, ver *firstVertex)
    {
        this->vertex = vertex;
        this->firstVertex = firstVertex;
    }
};
typedef struct Graph gr;

main()
{
    gr *g1 = createGraph(1);
    int choice, u, source, dest;
    while (1)
    {
        printf("\n1.Insert a vertex\n2.Insert an Edge\n");
        printf("3.Delete a vertex\n4.Delete an Edge\n");
        printf("5.Display\n6.Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cout << "Enter an Edge to be inserted: ";
            cin >> u;
            InsertVertex(u, g1);
            break;
        case 2:
            cout << "Enter an Edge to be inserted: ";
            cin >> source >> dest;
            InsertEdge(g1, source, dest);
            break;
        case 3:
            cout << "Enter the vertex to be Deleted: ";

            cin >> source;
            deleteVertex(g1, source);
            for (ver *p = g1->firstVertex; p != NULL; p = p->next)
            {
                cout << p->data << " ";
            }
            cout << endl;
            break;

        case 4:
            cout << "Enter an Edge to be deleted: ";
            cin >> source >> dest;
            deleteEdge(g1, source, dest);
            break;
        case 5:
            BFS(g1);
            break; // 2 7 9 2 9 11 2 9 17 2 9 13 2 13 17 2 15 7
        case 6:
            exit(1);
        case 7:
            cout << "Enter the vertex whose degree needs to be found: ";
            cin >> source;
            cout << "Degree: " << Degree(g1, source) << endl;
            break;

        default:
            printf("Wrong Choice");
            break;
        }
    }
}
