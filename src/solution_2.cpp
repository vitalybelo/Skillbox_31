#include <iostream>
#include "ListGraph.h"
using namespace std;

void solution_2()
{
    cout << "\n************* SOLUTION #2 ************\n";

    ListGraph graph;

    /**
     *   V1 ---> V2
     *         / |
     *       /   |
     *     v     v
     *   V4 <--- V3
     */
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(3,4);
    graph.AddEdge(2,4);

    cout << "\nLIST GRAPH ::\n\n";
    cout << "Total vertices counted = " << graph.VerticesCount() << endl;

    // выводим список следующих смешных вершин для каждой вершины в графе
    cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (int i = 1; i <= graph.VerticesCount(); i++) {
        vector<int> vertices;
        graph.GetNextVertices(i, vertices);
        cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                cout << " :: --> " << v;
        } else {
            cout << " :: --> none";
        }
        cout << endl;
    }

    // выводим список предыдущих смешных вершин для каждой вершины в графе
    cout << "\nSCROLL PREVIOUS G(V,E) vertices:\n";
    for (int i = 1; i <= graph.VerticesCount(); i++) {
        vector<int> vertices;
        graph.GetPrevVertices(i, vertices);
        cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                cout << " <-- :: " << v;
        } else {
            cout << " <-- :: none";
        }
        cout << endl;
    }


}