#pragma once
#include "IGraph.h"

#define START_INDEX 1
/**
 * Сохраняет ориентированный граф в виде матрицы смежности
 * Нумерация вершин графа начинается с параметра START_INDEX, по умолчанию = 1
 */
class MatrixGraph : public IGraph {
private:
    bool** matrix;       // динамический массив матрицы
    bool* verticesMap;   // карта учета вершин массива матрицы
    int matrixDimension; // размерность массива матрицы
    int verticesCounter; // счетчик вершин добавленных в матрицу

public:

    explicit MatrixGraph(int dimension);
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    void showVertices() override;

    void PrintMatrix();
    static void DisplayGraph();

};
