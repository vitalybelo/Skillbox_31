#pragma once
#include "IGraph.h"

struct Node {
    int vertex;
    std::vector<int> next;
};

/**
 * Сохраняет ориентированный граф в виде массива списков смежности
 */
class ListGraph : public IGraph {
private:
    std::vector<Node> nodeList;

public:
    ListGraph();
    explicit ListGraph(IGraph *oth);
    ~ListGraph() override;

    void AddEdge(int from, int to) override;
    [[nodiscard]] int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все следующие смежные вершины
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все предыдущие смежные вершины
    void showVertices() override; // отображение смежных вершин графа
    int getVertexIndex(int vertex); // возвращает индекс элемента вектора, если вершина существует в списке графа, или -1 если вершины нет в списке графа

};
