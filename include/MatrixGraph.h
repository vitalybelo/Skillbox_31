#pragma once
#include "IGraph.h"

class MatrixGraph : public IGraph {
private:
    bool** matrix;
    int dimension;

public:

    explicit MatrixGraph(int dimension);
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
};
