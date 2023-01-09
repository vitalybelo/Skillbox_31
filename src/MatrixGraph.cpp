#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int dimension)
{
    verticesCounter = 0;
    this->dimension = dimension;
    matrix = new bool *[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new bool[dimension];
        for (int x = 0; x < dimension; x++) {
            matrix[i][x] = false;
        }
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
    if (from <= 0 || to <= 0) return;
    from -= 1;
    to -= 1;
    matrix[from][to] = true;
    matrix[to][from] = true;
    verticesCounter++;
}

void MatrixGraph::RemoveEdge(int from, int to) {
    if (from <= 0 || to <= 0) return;
    from -= 1;
    to -= 1;
    matrix[from][to] = false;
    matrix[to][from] = false;
    verticesCounter--;
}

int MatrixGraph::VerticesCount() const {
    return verticesCounter;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {

}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {

}

void MatrixGraph::PrintMatrix() {
    std::cout << "\n     ";
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    std::cout << "  ";
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << i + 1 << " |  ";
        for (int x = 0; x < verticesCounter; x++) {
            std::cout << matrix[i][x] << " ";
        }
        std::cout << std::endl;
    }

}

