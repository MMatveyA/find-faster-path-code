/**
 * @brief A structure for representing a graph node.
 */
struct Node {
  int x, y;         /// Node coordinates.
  double cost;      /// The cost of the path to this node.
  double heuristic; /// Heuristic estimation of the distance to the target.
  Node *parent;     /// A pointer to the parent node.

  /**
   * @brief Конструктор узла.
   * @param[in] x The x coordinate of the node.
   * @param[in] y The y coordinate of the node.
   */
  Node(int x, int y) : x(x), y(y), cost(0), heuristic(0), parent(nullptr) {}
};
