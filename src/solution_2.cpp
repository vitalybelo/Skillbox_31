#include "ListGraph.h"
#include "MatrixGraph.h"
using namespace std;

void solution_2() {

    cout << "\n************* SOLUTION #2 ************\n\n";
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */

    IGraph *a = new ListGraph;

    a->AddEdge(1, 2);
    a->AddEdge(2, 3);
    a->AddEdge(3, 4);
    a->AddEdge(2, 4);
    a->AddEdge(2, 5);
    a->AddEdge(5, 3);

    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n";
    ListGraph::DisplayGraph();
    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n\n";

    cout << "Total vertices counted = " << a->VerticesCount() << endl;
    a->showVertices(); // выводим список следующих и предыдущих смешных вершин для каждой вершины в графе






    MatrixGraph matrixGraph(10);

    matrixGraph.AddEdge(1, 2);
    matrixGraph.AddEdge(2, 3);
    matrixGraph.AddEdge(3, 4);
    matrixGraph.AddEdge(2, 4);
    matrixGraph.AddEdge(2, 5);
    matrixGraph.AddEdge(5, 3);

    cout << "\n\n::::::::::::: MATRIX GRAPH ::::::::::::\n";
    MatrixGraph::DisplayGraph();
    cout << "::::::::::::: MATRIX GRAPH ::::::::::::\n\n";

    cout << "Total vertices counted = " << matrixGraph.VerticesCount() << endl;
    matrixGraph.PrintMatrix();
    matrixGraph.showVertices(); // выводим список следующих и предыдущих смешных вершин для каждой вершины в графе

}