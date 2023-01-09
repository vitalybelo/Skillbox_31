#pragma once
#include "IGraph.h"

/**
 * Сохраняет ориентированный граф в виде массива списков смежности
 */
class ListGraph : public IGraph {
private:
    std::vector<Node> nodeList;

public:
    ListGraph();
    ~ListGraph() override;

    int getVertexIndex(int vertex);
    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все следующие смежные вершины
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все предыдущие смежные вершины
    void getAllNextVertices(int vertex, std::vector<int> &vertices) const; // возвращает все следующие вершины куда можно дойти по графу
    void getAllPrevVertices(int vertex, std::vector<int> &vertices) const; //

};
