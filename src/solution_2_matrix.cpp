#include "MatrixGraph.h"
using namespace std;

void solution_2_matrix() {

    cout << "\n************* SOLUTION  #2 ************\n";

    MatrixGraph matrixGraph(10);
    /**
     *   V1 ---> V2
     *         / |
     *       /   |
     *     v     v
     *   V4 <--- V3
     */
    matrixGraph.AddEdge(1,2);
    matrixGraph.AddEdge(2,3);
    matrixGraph.AddEdge(3,4);
    matrixGraph.AddEdge(2,4);

    cout << "::::::::::::: MATRIX GRAPH ::::::::::::\n\n";
    cout << "Total vertices counted = " << matrixGraph.VerticesCount() << endl;
    matrixGraph.PrintMatrix();



}