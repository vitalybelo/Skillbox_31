#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int dimension)
{
    this->dimension = dimension;
    matrix = new bool * [dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new bool [dimension];
        for (int x = 0; x < dimension; x++)
            matrix[i][x] = false;
    }
}

MatrixGraph::~MatrixGraph()
{
    for (int i = 0; i < dimension; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void MatrixGraph::AddEdge(int from, int to) {

}

int MatrixGraph::VerticesCount() const {
    return 0;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {

}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {

}
