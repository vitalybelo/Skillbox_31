#include "MatrixGraph.h"
using namespace std;

void solution_2_matrix() {

    cout << "\n************* SOLUTION  #2 ************\n";

    MatrixGraph matrixGraph(10);
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V5
     */
    matrixGraph.AddEdge(1,2);
    matrixGraph.AddEdge(2,3);
    matrixGraph.AddEdge(3,4);
    matrixGraph.AddEdge(2,4);
    matrixGraph.AddEdge(2,5);
    matrixGraph.AddEdge(5,3);

    cout << "::::::::::::: MATRIX GRAPH ::::::::::::\n\n";
    cout << "Total vertices counted = " << matrixGraph.VerticesCount() << endl;
    matrixGraph.PrintMatrix();

    // выводим список следующих смешных вершин для каждой вершины в графе
    cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (int i = 1; i <= matrixGraph.VerticesCount(); i++) {
        vector<int> vertices;
        matrixGraph.GetNextVertices(i, vertices);
        cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                cout << " :: --> " << v;
        } else {
            cout << " :: --> none";
        }
        cout << endl;
    }



}