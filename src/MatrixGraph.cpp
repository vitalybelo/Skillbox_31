#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int dimension) {
    // конструктор задает размер динамического массива матрицы
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

MatrixGraph::MatrixGraph(IGraph *other) {
    // конструктор должен скопировать граф из объекта класса IGraph (интерфейса)
    std::vector<int> verticesNumbers = other->getVerticesNumbers();

    int v_max = 0;
    // определяем номер самой последней вершины (с максимальным номером)
    for (auto i : verticesNumbers) {
        v_max = std::max(v_max, i);
    }
    // инициализируем параметры класса MatrixGraph
    matrixDimension = v_max;
    verticesMap = new bool[matrixDimension];
    matrix = new bool*[matrixDimension];
    for (int i = 0; i < matrixDimension; i++) {
        verticesMap[i] = false;
        matrix[i] = new bool[matrixDimension];
        for (int x = 0; x < matrixDimension; x++)
            matrix[i][x] = false;
    }
    // добавляем в новый граф все вершины и ребра от копируемого графа
    verticesCounter = 0;
    for (int vertex : verticesNumbers) {
        std::vector<int> vertices;
        other->GetNextVertices(vertex, vertices);
        for (int v : vertices) {
            MatrixGraph::AddEdge(vertex, v);
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < matrixDimension; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] verticesMap;
}

void MatrixGraph::PrintMatrix() {
    std::cout << "\n     ";
    for (int i = 0; i < matrixDimension; i++) {
        std::cout << i + START_INDEX << " ";
    }
    std::cout << std::endl;
    std::cout << "  ";
    for (int i = 0; i < matrixDimension; i++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    for (int i = 0; i < matrixDimension; i++) {
        std::cout << i + START_INDEX << " |  ";
        for (int x = 0; x < matrixDimension; x++) {
            std::cout << matrix[i][x] << " ";
        }
        std::cout << std::endl;
    }
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

std::vector<int> MatrixGraph::getVerticesNumbers() const {
    std::vector<int> vertices;
    for (int i = 0; i < matrixDimension; ++i) {
        if (verticesMap[i])
            vertices.push_back(i + START_INDEX);
    }
    return vertices;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    if (vertex <= 0 || vertex > matrixDimension) return;
    vertex -= START_INDEX;
    for (int i = 0; i < matrixDimension; i++) {
        if (matrix[vertex][i])
            vertices.push_back(i + START_INDEX);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    if (vertex <= 0 || vertex > matrixDimension) return;
    vertex -= START_INDEX;
    for (int i = 0; i < matrixDimension; i++) {
        if (matrix[i][vertex])
            vertices.push_back(i + START_INDEX);
    }
}

void MatrixGraph::showVertices() {

    std::vector<int> verticesNumbers = getVerticesNumbers();
    std::cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (auto vertex : verticesNumbers) {
        std::vector<int> vertices;
        GetNextVertices(vertex, vertices);
        std::cout << "Vertex #" << vertex;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " :: --> " << v;
        } else {
            std::cout << " :: --> none";
        }
        std::cout << std::endl;
    }

    std::cout << "\nSCROLL PREVIOUS G(V,E) vertices:\n";
    for (auto vertex : verticesNumbers) {
        std::vector<int> vertices;
        GetPrevVertices(vertex, vertices);
        std::cout << "Vertex #" << vertex;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " <-- :: " << v;
        } else {
            std::cout << " <-- :: none";
        }
        std::cout << std::endl;
    }

}




