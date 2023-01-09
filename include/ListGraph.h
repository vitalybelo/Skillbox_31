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

    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все следующие смежные вершины
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все предыдущие смежные вершины

    int getVertexIndex(int vertex);
    static void pushBackUnique(int vertex, std::vector<int> &vertices);
    void getAllNextVertices(int vertex, std::vector<int> &vertices) const; // возвращает все следующие вершины куда можно дойти по графу
    void getAllPrevVertices(int vertex, std::vector<int> &vertices) const; // возвращает все предыдущие вершины откуда можно дойти по графу

};
