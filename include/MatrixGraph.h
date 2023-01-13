#pragma once
#include "IGraph.h"

#define START_INDEX 1
/**
 * Сохраняет ориентированный граф в виде матрицы смежности
 * Нумерация вершин графа начинается с параметра START_INDEX, по умолчанию = 1
 */
class MatrixGraph : public IGraph {
private:
    bool** matrix;       // динамический массив матрицы
    bool* verticesMap;   // карта учета вершин массива матрицы
    int matrixDimension; // размерность массива матрицы
    int verticesCounter; // счетчик вершин добавленных в матрицу

public:

    explicit MatrixGraph(int dimension);
    explicit MatrixGraph(IGraph *other); // конструктор копирования от родительского класса
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override; // Принимает вершины начала и конца ребра и добавляет ребро
    [[nodiscard]] int VerticesCount() const override; // Возвращает количество вершин в графе
    [[nodiscard]] std::vector<int> getVerticesNumbers() const override; // Возвращает список с номерами вершин в графе
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все следующие смежные вершины
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override; // возвращает все предыдущие смежные вершины
    void showVertices() override; // отображение смежных вершин графа

    void PrintMatrix();
};
