#include "ListGraph.h"


ListGraph::ListGraph() = default;

ListGraph::ListGraph(IGraph *other) {
    // конструктор должен скопировать граф из объекта интерфейса IGraph
    std::vector<int> verticesNumbers = other->getVerticesNumbers();
    // для всех вершин копируемого графа получаем смежные вершины и создаем копии
    for (int vertex : verticesNumbers) {
        std::vector<int> vertices;
        other->GetNextVertices(vertex, vertices);
        for (int i : vertices) {
            ListGraph::AddEdge(vertex, i);
        }
    }
}

ListGraph &ListGraph::operator=(const IGraph* other) {
    nodeList.clear();
    std::vector<int> verticesNumbers = other->getVerticesNumbers();
    for (int vertex : verticesNumbers) {
        std::vector<int> vertices;
        other->GetNextVertices(vertex, vertices);
        for (int i : vertices) {
            ListGraph::AddEdge(vertex, i);
        }
    }
    return *this;
}

ListGraph::~ListGraph() {
    nodeList.clear();
    nodeList.shrink_to_fit();
}

int ListGraph::getVertexIndex(int vertex) {
    for (int i = 0; i < nodeList.size(); i++) {
        if (vertex == nodeList.at(i).vertex) {
            // такая вершина уже есть в коллекции графа, возвращаем индекс массива
            return i;
        }
    }
    // вершина не найдена - это новая вершина - её нужно добавить в коллекцию
    return -1;
}

int ListGraph::VerticesCount() const {
    return (int) nodeList.size();
}

std::vector<int> ListGraph::getVerticesNumbers() const {
    std::vector<int> vertices;
    for (const auto & i : nodeList) {
        vertices.push_back(i.vertex);
    }
    return vertices;
}

void ListGraph::AddEdge(int from, int to) {

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

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertices.clear();
    for (auto & node : nodeList) {
        if (vertex == node.vertex) {
            vertices = node.next;
            break;
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
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

void ListGraph::showVertices() {

    std::vector<int> verticesNumbers = getVerticesNumbers();
    std::cout << "\nSCROLL NEXT G(V,E) vertices:\n";
    for (auto vertex : verticesNumbers) {
        std::vector<int> vertices;
        GetNextVertices(vertex, vertices);
        std::cout << "Vertex #" << vertex;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " :: --> " << v;
        } else {
            std::cout << " :: --> none";
        }
        std::cout << std::endl;
    }

    std::cout << "\nSCROLL PREVIOUS G(V,E) vertices:\n";
    for (auto vertex : verticesNumbers) {
        std::vector<int> vertices;
        GetPrevVertices(vertex, vertices);
        std::cout << "Vertex #" << vertex;
        if (!vertices.empty()) {
            for (int &v: vertices)
                std::cout << " <-- :: " << v;
        } else {
            std::cout << " <-- :: none";
        }
        std::cout << std::endl;
    }
}


