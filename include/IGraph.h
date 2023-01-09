#pragma once
#include <iostream>
#include <vector>


class IGraph {
public:
    IGraph() = default;
    explicit IGraph(IGraph *_oth) {};

    virtual void AddEdge(int from, int to) = 0;             // Метод принимает вершины начала и конца ребра и добавляет ребро
    [[nodiscard]] virtual int VerticesCount() const = 0;    // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

    virtual ~IGraph() = default;

};
