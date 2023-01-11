#include "ListGraph.h"
#include "MatrixGraph.h"
using namespace std;

void solution_2() {

    cout << "\n************* SOLUTION #2 ************\n\n";

    ListGraph listGraph;
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(2, 4);
    listGraph.AddEdge(2, 5);
    listGraph.AddEdge(5, 3);

    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n";
    ListGraph::DisplayGraph();
    cout << "::::::::::::: LIST GRAPH  ::::::::::::\n\n";

    cout << "Total vertices counted = " << listGraph.VerticesCount() << endl;
    listGraph.PrintNextVertices(); // выводим список следующих смешных вершин для каждой вершины в графе
    listGraph.PrintPrevVertices(); // выводим список предыдущих смешных вершин для каждой вершины в графе
//    listGraph.PrintAllNextVertices(); // выводим список всех следующих вершин до которых можно дойти из конкретной вершины
//    listGraph.PrintAllPrevVertices(); // выводим список всех предыдущих вершин из которых можно дойти до конкретной вершины

    MatrixGraph matrixGraph(10);
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */
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
    matrixGraph.PrintNextVertices(); // выводим список следующих смешных вершин для каждой вершины в графе
    matrixGraph.PrintPrevVertices(); // выводим список предыдущих смешных вершин для каждой вершины в графе


}