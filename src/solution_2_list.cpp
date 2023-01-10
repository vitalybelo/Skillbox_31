#include "ListGraph.h"
using namespace std;

void solution_2_list() {

    cout << "\n************* SOLUTION #2 ************\n";

    ListGraph listGraph;
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */
    ListGraph::DisplayGraph();

    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(2, 4);
    listGraph.AddEdge(2, 5);
    listGraph.AddEdge(5, 3);

    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n\n";
    cout << "Total vertices counted = " << listGraph.VerticesCount() << endl;

    // выводим список следующих смешных вершин для каждой вершины в графе
    listGraph.PrintNextVertices();

    // выводим список предыдущих смешных вершин для каждой вершины в графе
    listGraph.PrintPrevVertices();

    // выводим список всех следующих вершин до которых можно дойти из конкретной вершины
    listGraph.PrintAllNextVertices();

    // выводим список всех предыдущих вершин из которых можно дойти до конкретной вершины
    listGraph.PrintAllPrevVertices();

}