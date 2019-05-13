#include <stdio.h>
#include "graph.c"
//#include "search_graph.c"
#include "search_Euler.c"


int main()
{
    GRAPH graph;
    readGraph(&graph, 0);

    printGraph(&graph);


    startSearch(&graph);


    puts("");
    system("pause");
    return 0;
}