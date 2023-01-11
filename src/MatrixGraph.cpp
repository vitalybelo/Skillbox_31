#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int dimension) {

    verticesCounter = 0;
    this->matrixDimension = dimension;
    verticesMap = new bool[dimension];
    matrix = new bool*[dimension];
    for (int i = 0; i < dimension; i++) {
        verticesMap[i] = false;
        matrix[i] = new bool[dimension];
        for (int x = 0; x < dimension; x++)
            matrix[i][x] = false;
    }
}

MatrixGraph::MatrixGraph(IGraph *oth) {

    int verticesCount = oth->VerticesCount();
    matrixDimension = verticesCount + 2;
    verticesMap = new bool[matrixDimension];
    matrix = new bool*[matrixDimension];
    for (int i = 0; i < matrixDimension; i++) {
        verticesMap[i] = false;
        matrix[i] = new bool[matrixDimension];
        for (int x = 0; x < matrixDimension; x++)
            matrix[i][x] = false;
    }
    verticesCounter = 0;
    for (int vertex = 1; vertex <= verticesCount; ++vertex) {
        std::vector<int> vertices;
        oth->GetNextVertices(vertex, vertices);
        for (int v : vertices) {
            MatrixGraph::AddEdge(vertex, v);
        }
    }
}

MatrixGraph::~MatrixGraph()
{
    for (int i = 0; i < matrixDimension; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] verticesMap;
}

void MatrixGraph::AddEdge(int from, int to) {
    if (from <= 0 || to <= 0) return;
    if (from > matrixDimension || to > matrixDimension) return;
    from -= START_INDEX; // приводим номера для использования в массиве
    to -= START_INDEX;
    if (!verticesMap[from]) {
        verticesCounter++;
        verticesMap[from] = true;
    }
    matrix[from][to] = true;
    if (!verticesMap[to]) {
        verticesCounter++;
        verticesMap[to] = true;
    }
}

int MatrixGraph::VerticesCount() const {
    return verticesCounter;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    if (vertex <= 0 || vertex > matrixDimension) return;
    vertex -= START_INDEX;
    for (int i = 0; i < verticesCounter; i++) {
        if (matrix[vertex][i])
            vertices.push_back(i + START_INDEX);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    if (vertex <= 0 || vertex > matrixDimension) return;
    vertex -= START_INDEX;
    for (int i = 0; i < verticesCounter; i++) {
        if (matrix[i][vertex])
            vertices.push_back(i + START_INDEX);
    }
}

void MatrixGraph::PrintMatrix() {
    std::cout << "\n     ";
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << i + START_INDEX << " ";
    }
    std::cout << std::endl;
    std::cout << "  ";
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    for (int i = 0; i < verticesCounter; i++) {
        std::cout << i + START_INDEX << " |  ";
        for (int x = 0; x < verticesCounter; x++) {
            std::cout << matrix[i][x] << " ";
        }
        std::cout << std::endl;
    }

}

void MatrixGraph::showVertices()
{
    std::cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (int i = 1; i <= verticesCounter; i++) {
        std::vector<int> vertices;
        GetNextVertices(i, vertices);
        std::cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " :: --> " << v;
        } else {
            std::cout << " :: --> none";
        }
        std::cout << std::endl;
    }

    std::cout << "\nSCROLL PREVIOUS G(V,E) vertices:\n";
    for (int i = 1; i <= verticesCounter; i++) {
        std::vector<int> vertices;
        GetPrevVertices(i, vertices);
        std::cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " <-- :: " << v;
        } else {
            std::cout << " <-- :: none";
        }
        std::cout << std::endl;
    }

}



