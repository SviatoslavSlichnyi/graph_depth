#ifndef GRAPHS_SEARCH_GRAPH_H
#define GRAPHS_SEARCH_GRAPH_H

_Bool finished = 0;

_Bool processed[MAXV+1];//чи вона обровлена(тобто коли ми пройлись по всім ребрам
_Bool discovered[MAXV+1];//відкрита// побували чи ні
int parent[MAXV+1];//послідовність проходження вершин
//index - значення вершини
//значення яке воно зберігає - це батько


void initialize_search(GRAPH* graph);
void dfs(GRAPH* graph, int v);
void find_path(int start, int end, int parents[]);


void process_edge(int x, int y);

void process_vertex_early(int v);
void process_vertex_late(int v);
void process_edge(int x, int y);

#endif //GRAPHS_SEARCH_GRAPH_H
