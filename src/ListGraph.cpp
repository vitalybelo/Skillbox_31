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
        // добавляем новую смежную вершину в список существующей вершины
        nodeList.at(i).next.push_back(to);
    }
    if (getVertexIndex(to) < 0) {
        // добавляем в список графа конечную вершину
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

void ListGraph::pushBackUnique(int vertex, std::vector<int> &vertices) {
    for (auto & v : vertices) {
        if (vertex == v) return;
    }
    vertices.push_back(vertex);
}

void ListGraph::getAllNextVertices(int vertex, std::vector<int> &vertices) const
{
    std::vector<int> v;
    GetNextVertices(vertex, v);
    for (int & vx : v) {
        pushBackUnique(vx, vertices);
        getAllNextVertices(vx, vertices);
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

void ListGraph::getAllPrevVertices(int vertex, std::vector<int> &vertices) const
{
    std::vector<int> v;
    GetPrevVertices(vertex, v);
    for (int & vx : v) {
        pushBackUnique(vx, vertices);
        getAllPrevVertices(vx, vertices);
    }
}

ListGraph::~ListGraph()
{
    nodeList.clear();
    nodeList.shrink_to_fit();
}

void ListGraph::PrintNextVertices() const
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
}

void ListGraph::PrintPrevVertices() const
{
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

void ListGraph::PrintAllNextVertices() const
{
    std::cout << "\nSCROLL ALL NEXT G(V,E) vertices:\n";
    for (int i = 1; i <= VerticesCount(); i++) {
        std::vector<int> vertices;
        getAllNextVertices(i, vertices);
        std::cout << "Vertex #" << i;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " :: --> " << v;
        } else {
            std::cout << " :: --> none";
        }
        std::cout << std::endl;
    }
}

void ListGraph::PrintAllPrevVertices() const
{
    std::cout << "\nSCROLL ALL PREVIOUS G(V,E) vertices:\n";
    for (int i = 1; i <= VerticesCount(); i++) {
        std::vector<int> vertices;
        getAllPrevVertices(i, vertices);
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

void ListGraph::DisplayGraph()
{
    std::cout << "V1 ---> V2\n";
    std::cout << "      / |  \\\n";
    std::cout << "    /   |   \\\n";
    std::cout << "  v     v    v\n";
    std::cout << "V4 <-- V3 <- V5\n";
}



