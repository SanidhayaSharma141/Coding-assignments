#include <bits/stdc++.h>
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
class graphUsingList
{
    gr *g1;

public:
    bool createGraph(bool val)
    {
        g1 = new gr(NULL, NULL);
    }
    bool findVertex(int data)
    {
        ver *ptr = g1->firstVertex;
        for (; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == data)
            {
                return 1;
            }
        }
        return 0;
    }
    bool InsertVertex(int data)
    {
        if (findVertex(data) == 1)
        {
            return 0;
        }
        ver *tmp, *ptr;
        tmp = new ver(data, NULL, NULL);
        if (g1->firstVertex == NULL)
        {
            g1->firstVertex = tmp;
            return 1;
        }
        ptr = g1->firstVertex;
        for (; ptr->next != NULL; ptr = ptr->next)
        {
        }
        ptr->next = tmp;
        return 1;
    }
    bool isEdge(int u, int v)
    {
        if (findVertex(u) == 0 || findVertex(v) == 0)
        {
            return 0;
        }
        ver *ptr = g1->firstVertex;
        for (; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == u)
            {
                break;
            }
        }
        if (ptr->firstEdge == NULL)
        {
            return 0;
        }
        for (edge *beg = ptr->firstEdge; beg != NULL; beg = beg->nextEdge)
        {
            if (beg->destination_ver->data == v)
            {
                return 1;
            }
        }
        return 0;
    }
    bool InsertEdge(int u, int v)
    {

        // if (findVertex(g1, u) == 0 || findVertex(g1, v) == 0)
        // {
        //     return 0;
        // }
        if (isEdge(u, v) == 1)
        {
            cout << "Edge already exists" << endl;
            return 0;
        }
        ver *verU = NULL, *verV = NULL;
        for (ver *ptr = g1->firstVertex; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == u)
            {
                verU = ptr;
            }
            else if (ptr->data == v)
            {
                verV = ptr;
            }
            if (verU != NULL && verV != NULL)
            {
                break;
            }
        }
        if (verU == NULL || verV == NULL)
        {
            return 0;
        }
        edge *tmp = new edge(verV, NULL);
        edge *tmp2 = new edge(verU, NULL);
        edge *p = verU->firstEdge;
        edge *p2 = verV->firstEdge;
        if (p == NULL)
        {
            verU->firstEdge = tmp;
        }
        else
        {
            for (; p->nextEdge != NULL; p = p->nextEdge)
            {
            }
            p->nextEdge = tmp;
        }
        if (p2 == NULL)
        {
            verV->firstEdge = tmp2;
        }
        else
        {
            for (; p2->nextEdge != NULL; p2 = p2->nextEdge)
            {
            }
            p2->nextEdge = tmp2;
        }
        return 1;
    }
    int Degree(int u)
    {
        ver *v = g1->firstVertex;
        for (; v->data != u && v != NULL; v = v->next)
        {
        }
        if (v == NULL)
        {
            return -1;
        }
        int count = 0;
        for (edge *e1 = v->firstEdge; e1 != NULL; e1 = e1->nextEdge)
        {
            count++;
        }
        return count;
    }
    void BFS()
    {
        ver *ptr = g1->firstVertex;
        if (ptr == NULL)
        {
            cout << "Empty Graph" << endl;
            return;
        }
        for (; ptr != NULL; ptr = ptr->next)
        {
            cout << ptr->data << "-> ";
            for (edge *e1 = ptr->firstEdge; e1 != NULL; e1 = e1->nextEdge)
            {
                cout << e1->destination_ver->data << " ";
            }
            cout << endl;
        }
    }

    bool deleteEdge(int u, int v)
    {
        // if (findVertex(g1, u) == 0 || findVertex(g1, v) == 0)
        // {
        //     return 0;
        // }
        if (isEdge(u, v) == 0)
        {
            // cout << "Edge does not exists" << endl;
            return 0;
        }
        ver *verU = NULL, *verV = NULL;
        for (ver *ptr = g1->firstVertex; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == u)
            {
                verU = ptr;
            }
            else if (ptr->data == v)
            {
                verV = ptr;
            }
            if (verU != NULL && verV != NULL)
            {
                break;
            }
        }
        if (verU == NULL || verV == NULL)
        {
            return 0;
        }
        edge *p = verU->firstEdge;
        if (p->destination_ver->data == v)
        {
            edge *temp = verU->firstEdge;
            verU->firstEdge = verU->firstEdge->nextEdge;
            free(temp);
        }
        else
        {
            for (; p->nextEdge->destination_ver->data != v && p->nextEdge != NULL; p = p->nextEdge)
            {
            }
            edge *temp = p->nextEdge;
            p->nextEdge = p->nextEdge->nextEdge;
            free(temp);
        }
        edge *q = verV->firstEdge;
        if (q->destination_ver->data == u)
        {
            edge *temp = verV->firstEdge;
            verV->firstEdge = verV->firstEdge->nextEdge;
            free(temp);
        }
        else
        {
            for (; q->nextEdge->destination_ver->data != u && q->nextEdge != NULL; q = q->nextEdge)
            {
            }
            edge *temp2 = q->nextEdge;
            q->nextEdge = q->nextEdge->nextEdge;
            free(temp2);
        }
        return 1;
    }
    bool deleteVertex(int u)
    {
        ver *tbDel = g1->firstVertex;
        if (tbDel == NULL)
        {
            return 0; // empty graph;
        }

        if (tbDel->data != u)
        {
            for (; tbDel->next != NULL && tbDel->next->data != u; tbDel = tbDel->next)
            {
            }

            if (tbDel->next == NULL)
            {
                return 0; // no vertex case
            }
            ver *temp = tbDel->next;

            while (temp->firstEdge != NULL)
            {
                deleteEdge(temp->data, temp->firstEdge->destination_ver->data);
            }
            tbDel->next = temp->next;
            free(temp);
        }
        else
        {
            ver *temp = tbDel;
            while (temp->firstEdge != NULL)
            {
                deleteEdge(temp->data, temp->firstEdge->destination_ver->data);
            }
            g1->firstVertex = temp->next;
            free(temp);
        }
        // edge deletion
        return 1;
    }
    void printVertices()
    {
        for (ver *p = g1->firstVertex; p != NULL; p = p->next)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
};

// createGraph function:
graphUsingList *createGraph(bool ch)
{
    if (ch == 1)
    {
        graphUsingList *gr;
        return gr;
    }
}
main()
{
    graphUsingList *g = createGraph(1);
    int choice, u, source, dest;
    while (1)
    {
        printf("\n1.Insert a vertex\n2.Insert an Edge\n");
        printf("3.Delete a vertex\n4.Delete an Edge\n");
        printf("5.Display\n6.Create a Graph\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cout << "Enter an Edge to be inserted: ";
            cin >> u;
            g->InsertVertex(u);
            break;
        case 2:
            cout << "Enter an Edge to be inserted: ";
            cin >> source >> dest;
            g->InsertEdge(source, dest);
            break;
        case 3:
            cout << "Enter the vertex to be Deleted: ";

            cin >> source;
            g->deleteVertex(source);
            g->printVertices();
            break;

        case 4:
            cout << "Enter an Edge to be deleted: ";
            cin >> source >> dest;
            g->deleteEdge(source, dest);
            break;
        case 5:
            g->BFS();
            break; // 2 7 9 2 9 11 2 9 17 2 9 13 2 13 17 2 15 7
        case 6:
            g->createGraph(1);
            break;
        case 7:
            cout << "Enter the vertex whose degree needs to be found: ";
            cin >> source;
            cout << "Degree: " << g->Degree(source) << endl;
            break;

        default:
            printf("Wrong Choice");
            break;
        }
    }
}
