#include "ListGraph.h"
#include "MatrixGraph.h"
using namespace std;

void DisplayGraph();

void solution_2() {

    cout << "\n************* SOLUTION #2 ************\n\n";
    /**
     *   V1 ---> V2
     *         / |  \
     *       /   |   \
     *     v     v    v
     *   V4 <-- V3 <- V7 --> V9
     */
    DisplayGraph();

    IGraph *a = new ListGraph;

    a->AddEdge(1, 2);
    a->AddEdge(2, 3);
    a->AddEdge(3, 4);
    a->AddEdge(2, 4);
    a->AddEdge(2, 7);
    a->AddEdge(7, 3);
    a->AddEdge(7, 9);

    cout << "\n----------------------------------->\n";
    cout << "IGraph *a = new ListGraph\n";
    cout << "----------------------------------->\n";
    a->showVertices(); // отображаем список следующих и предыдущих смешных вершин для каждой вершины в графе

    cout << "\n----------------------------------->\n";
    cout << "IGraph *b = new ListGraph(a)\n";
    cout << "----------------------------------->\n";
    IGraph *b = new ListGraph(a);
    b->showVertices();

    cout << "\n----------------------------------->\n";
    cout << "IGraph *c = new MatrixGraph(b)\n";
    cout << "----------------------------------->\n";
    IGraph *c = new MatrixGraph(b);
    c->showVertices();

    cout << "\n----------------------------------->\n";
    cout << "IGraph *d = new MatrixGraph(c)\n";
    cout << "----------------------------------->\n";
    IGraph *d = new MatrixGraph(c);
    d->showVertices();

    cout << "\n----------------------------------->\n";
    cout << "IGraph *e = new ListGraph(d)\n";
    cout << "----------------------------------->\n";
    IGraph *e = new ListGraph(d);
    c->showVertices();

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}

void DisplayGraph()
{
    std::cout << "  V1 ---> V2\n";
    std::cout << "        / |  \\\n";
    std::cout << "      /   |   \\\n";
    std::cout << "    v     v    v\n";
    std::cout << "  V4 <-- V3 <- V7 --> V9\n";
}
