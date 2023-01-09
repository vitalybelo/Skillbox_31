#include "ListGraph.h"


ListGraph::ListGraph() = default;

int ListGraph::getVertexIndex(int vertex)
{
    for (int i = 0; i < nodeList.size(); i++) {
        if (vertex == nodeList.at(i).vertex)
            return i;
    }
    return -1;
}

void ListGraph::AddEdge(int from, int to)
{
    int i = getVertexIndex(from);
    if (i < 0) {
        // добавляем в список графа новую начальную вершину
        Node node;
        node.vertex = from;
        node.next.push_back(to);
        nodeList.push_back(node);
    } else {
        // добавляем новую смежную вершину в список уже существующей вершины
        nodeList.at(i).next.push_back(to);
    }
    if (getVertexIndex(to) < 0) {
        // добавляем в список графа конечную вершину
        Node node;
        node.vertex = to;
        nodeList.push_back(node);
    }
}

int ListGraph::VerticesCount() const {
    return (int) nodeList.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {

}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {

}


