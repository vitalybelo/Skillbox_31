#pragma once
#include "IGraph.h"

/**
 * Сохраняет ориентированный граф в виде матрицы смежности
 * Нумерация вершин графа начинается с единицы, то есть первая вершина = 1
 */
class MatrixGraph : public IGraph {
private:
    bool** matrix;
    int dimension;
    int verticesCounter;

public:

    explicit MatrixGraph(int dimension);
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;
    void RemoveEdge(int from, int to);
    void PrintMatrix();
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};
