/**
 * @file
 * @brief A file with axiliary functions
 *
 * Auxiliary functions are included in this file
 */

#include "node.hpp"
#include <cmath>
#include <queue>
#include <unordered_map>
#include <vector>

/**
 * @brief A function for calculating a heuristic estimate (for example, the
 * Manhattan distance)
 * @param[in] node The node to calculate the score for
 * @param[in] goal The target node
 * @return Heuristic estimation of the distance from the node to the target
 */
double calculateHeuristic(Node *node, Node *goal) {
  return abs(node->x - goal->x) + abs(node->y - goal->y);
}

/**
 * @brief A* search function
 * @param grid Graph map (0 is a passable node, 1 is an obstacle)
 * @param start Initial node
 * @param goal Target node
 * @return A node vector representing the found path from start to goal. If the
 * path is not found, an empty vector is returned.
 */
std::vector<Node *> aStarSearch(std::vector<std::vector<int>> &grid,
                                Node *start, Node *goal) {
  // Создаем приоритетную очередь для хранения узлов с оценкой f = cost +
  // heuristic
  std::priority_queue<std::pair<double, Node *>,
                      std::vector<std::pair<double, Node *>>,
                      std::greater<std::pair<double, Node *>>>
      openList;

  // Создаем таблицу посещенных узлов
  std::unordered_map<int, std::unordered_map<int, bool>> closedList;

  // Добавляем начальный узел в очередь
  openList.push(std::make_pair(calculateHeuristic(start, goal), start));

  while (!openList.empty()) {
    // Извлекаем узел с наименьшей оценкой f из очереди
    Node *current = openList.top().second;
    openList.pop();

    // Если достигли цели, возвращаем путь
    if (current->x == goal->x && current->y == goal->y) {
      std::vector<Node *> path;
      while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
      }
      reverse(
          path.begin(),
          path.end()); // Реверсируем путь, чтобы получить правильный порядок
      return path;
    }

    // Помечаем текущий узел как посещенный
    closedList[current->x][current->y] = true;

    // Проверяем соседние узлы
    std::vector<std::pair<int, int>> neighbors = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4-связность

    for (auto neighbor : neighbors) {
      int nx = current->x + neighbor.first;
      int ny = current->y + neighbor.second;

      // Проверяем, что соседний узел находится в пределах карты и является
      // проходимым
      if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
          grid[nx][ny] == 0) {
        Node *neighborNode = new Node(nx, ny);

        // Проверяем, был ли соседний узел уже посещен
        if (closedList.find(nx) != closedList.end() &&
            closedList[nx].find(ny) != closedList[nx].end()) {
          continue;
        }

        // Рассчитываем стоимость пути до соседнего узла
        neighborNode->cost =
            current->cost + 1; // Предполагаем, что стоимость перемещения между
                               // соседними узлами равна 1

        // Рассчитываем эвристическую оценку для соседнего узла
        neighborNode->heuristic = calculateHeuristic(neighborNode, goal);

        // Добавляем соседний узел в очередь
        openList.push(std::make_pair(
            neighborNode->cost + neighborNode->heuristic, neighborNode));

        // Устанавливаем родителя для соседнего узла
        neighborNode->parent = current;
      }
    }
  }

  // Если путь не найден, возвращаем пустой вектор
  return std::vector<Node *>();
}
