#include "ListGraph.h"


ListGraph::ListGraph() = default;

ListGraph::ListGraph(IGraph *oth)
{
    int verticesCount = oth->VerticesCount();
    for (int vertex = 1; vertex <= verticesCount; ++vertex)
    {
        std::vector<int> vertices;
        oth->GetNextVertices(vertex, vertices);
        for (int v : vertices) {
            ListGraph::AddEdge(vertex, v);
        }
    }
}

ListGraph::~ListGraph()
{
    nodeList.clear();
    nodeList.shrink_to_fit();
}


int ListGraph::getVertexIndex(int vertex)
{
    for (int i = 0; i < nodeList.size(); i++) {
        if (vertex == nodeList.at(i).vertex) {
            // такая вершина уже есть в коллекции графа, возвращаем индекс массива
            return i;
        }
    }
    // вершина не найдена - это новая вершина - её нужно добавить в коллекцию
    return -1;
}

void ListGraph::AddEdge(int from, int to)
{
    int i = getVertexIndex(from);
    if (i < 0) {
        // начальная вершины еще не в списке, добавляем в список графа новую вершину
        Node node;
        node.vertex = from;
        node.next.push_back(to);
        nodeList.push_back(node);
    } else {
        // вершина уже есть в списке, добавляем новую смежную вершину к существующей вершине
        nodeList.at(i).next.push_back(to);
    }
    if (getVertexIndex(to) < 0) {
        // конечной вершины нет в списке, добавляем в список графа конечную вершину
        Node node;
        node.vertex = to;
        nodeList.push_back(node);
    }
}

int ListGraph::VerticesCount() const
{
    return (int) nodeList.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (auto & node : nodeList) {
        if (vertex == node.vertex) {
            vertices = node.next;
            break;
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    vertices.clear();
    for (auto & node : nodeList)
    {
        for (auto & next_vertex : node.next)
        if (vertex == next_vertex) {
            vertices.push_back(node.vertex);
            break;
        }
    }
}

void ListGraph::DisplayGraph()
{
    std::cout << "V1 ---> V2\n";
    std::cout << "      / |  \\\n";
    std::cout << "    /   |   \\\n";
    std::cout << "  v     v    v\n";
    std::cout << "V4 <-- V3 <- V5\n";
}

void ListGraph::showVertices()
{
    std::cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (int i = 1; i <= VerticesCount(); i++) {
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
    for (int i = 1; i <= VerticesCount(); i++) {
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




