#include <iostream>
#include "ListGraph.h"
using namespace std;

void solution_2_list() {

    cout << "\n************* SOLUTION #2 ************\n";

    ListGraph graph;
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(5, 3);

    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n\n";
    cout << "Total vertices counted = " << graph.VerticesCount() << endl;

    // выводим список следующих смешных вершин для каждой вершины в графе
    graph.PrintNextVertices();

    // выводим список предыдущих смешных вершин для каждой вершины в графе
    graph.PrintPrevVertices();

    // выводим список всех следующих вершин до которых можно дойти из конкретной вершины
    graph.PrintAllNextVertices();

    // выводим список всех предыдущих вершин из которых можно дойти до конкретной вершины
    graph.PrintAllPrevVertices();

}