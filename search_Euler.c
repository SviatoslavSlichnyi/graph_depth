#include "search_Euler.h"

void startSearch(GRAPH* graph);
void initialize_search(GRAPH* graph, DiscEdges* discoveredEdges[], PATH** path, int firstPoint);
void searchPath(GRAPH* graph, PATH* path, DiscEdges* discoveredEdges[], int x, int* counter);
void addPath(PATH** path, int y);
_Bool wasDiscoverd(DiscEdges* discoveredEdges[], int x, int y);
void edgeWasDiscovered(DiscEdges* discoveredEdges[], int x, int y);

void startSearch(GRAPH* graph)
{


    DiscEdges* discoveredEdges[MAXV+1];//відкрита// побували чи ні
    PATH* path;
    int parent[MAXV+1];//послідовність проходження вершин

    for(int i = 1; i <= graph->nNodes; i++)
        discoveredEdges[i] = NULL;


    for(int i = 1; i <= graph->nNodes; i++)
    {
        initialize_search(graph, discoveredEdges, &path, i);
        int counter = 0;
        PATH* currentNodeInPath = path;

        searchPath(graph, currentNodeInPath, discoveredEdges, i, &counter);
        //printf("counter: %d\n", counter);
        //printf("edges: %d\n", graph->nEdges);
        if(counter*2 == graph->nEdges)
        {
            printf("The way was found:");
            for(int i = 0, y; path != NULL; i++)
            {
                printf(" %d", path->y);
                path = path->next;
            }
            puts("");
            //break;
        }

    }
}

void initialize_search(GRAPH* graph, DiscEdges* discoveredEdges[], PATH** path, int firstPoint)
{
    for(int i = 1; i <= graph->nNodes; i++)
    {
        discoveredEdges[i] = NULL;
    }

    PATH* firstNode = malloc(sizeof(PATH));
    firstNode->y = firstPoint;
    firstNode->next = NULL;
    *path = firstNode;
}
void searchPath(GRAPH* graph, PATH* path, DiscEdges* discoveredEdges[], int x, int* counter)
{
    //edgeWasDiscovered(discoveredEdges, x, y);//тут я відкрив ребро "(x,y)"


    //список суміжних вершин
    EDGENODE* aroundVertexes = graph->edges[x];//я беру всі вершини які є зєднані із вершиною x



    //цикл нам потрібний для того щоб пройтися по всім елементам списку
    for (int y;aroundVertexes != NULL; aroundVertexes = aroundVertexes->next)
    {
        //і ти дістаю значення ітого елемента
        y = aroundVertexes->y;

        //якщо я наткнувя на не відкриту вершину
        if (wasDiscoverd(discoveredEdges, x, y) == 0)
        {
            //printf("Now is being processed: %d\n",x);
            edgeWasDiscovered(discoveredEdges, x, y);
            //ми втановлюємо батька "v"
            addPath(&path, y);
            //паралельно опрацювати вершину "y"
            *counter += 1;

            searchPath(graph, path, discoveredEdges, y, counter );
            break;
        }

    }

}

void addPath(PATH** path, int y)
{
    PATH* node = malloc(sizeof(PATH));
    node->y = y;
    node->next = NULL;
    (*path)->next = node;
    *path = node;
}

void edgeWasDiscovered(DiscEdges* discoveredEdges[], int x, int y)
{
    DiscEdges* node = malloc(sizeof(DiscEdges));
    node->y = y;
    node->next = discoveredEdges[x];
    discoveredEdges[x] = node;

    node = malloc(sizeof(DiscEdges));
    node->y = x;
    node->next = discoveredEdges[y];
    discoveredEdges[y] = node;
}
_Bool wasDiscoverd(DiscEdges* discoveredEdges[], int x, int y)
{

    for(DiscEdges* node = discoveredEdges[x]; node != NULL; node = node->next)
    {
        if(node->y == y) return 1;
    }
    return 0;
}