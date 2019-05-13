#include "search_graph.h"

void initialize_search(GRAPH* graph)
{
    for(int i = 1; i <= graph->nNodes; i++)
    {
        processed[i] = discovered[i] = 0;
        parent[i] = -1;
    }
}

void start_search(GRAPH* graph)
{
    for(int i = 1; i <= graph->nEdges; i++)
    {
        initialize_search(graph);
        dfs(graph, i);
        puts("");
    }
}


void search_path(GRAPH* graph, int v)//v - вершина з якої
{
    EDGENODE* p;//вказівник на суміжний список
    int y;//вершина яка повязана із v's вершиною

    discovered[v] = 1;//тут я відкрив вершину "v"
    p = graph->edges[v];//я беру всі вершини які є зєднані із вершиною "v"
    printf_s("Now is being processed: %d\n",v);

    //цикл нам потрібний для того щоб пройтися по всім елементам списку
    for (;p != NULL; p = p->next)
    {
        //і ти дістаю значення ітого елемента
        y = p->y;

        //якщо я наткнувя на не відкриту вершину
        if (discovered[y] == 0)
        {
            //ми втановлюємо батька "v"
            parent[y] = v;
            //паралельно опрацювати вершину "y"
            dfs(graph, y);
        }

    }


    //processed[v] = 1;
}



void process_edge(int x, int y)
{
    if(parent[x] != y)
    {
        printf("Cycle from %d to %d: ", y, x);
        find_path(y,x, parent);
        printf("\n\n");
        finished = 1;
    }
}
void process_vertex_early(int v)
{
    printf("process vertex %d\n", v);
}
void process_vertex_late(int v)
{

}