/**
 * @file
 * @brief A set of entities to represent a 2D field cell
 *
 * This representation is used by the A-star algorithm to find the shortest path
 * between two points.
 */

#pragma once

#include <cstdint>

/// Field type
enum class NodeType {
  Empty = 1,  ///< Empty cell. Default variant
  Start = 2,  ///< Route start cell
  Finish = 4, ///< Route finish cell
  Wall = 8,   ///< Wall
};

/// Representation of a cell on a 2D plane
class Node {
public:
  /// Default constructor
  ///
  /// @param[in] row number of cell's row
  /// @param[in] col number of cell's column
  Node(std::uint8_t row, std::uint8_t col) : row(row), col(col) {}
  ~Node();

  /// Overloaded comparison operator ==
  ///
  /// @param[in] node_ comparison node
  ///
  /// @return comprassion result
  bool operator==(const Node &node_);

  /// Overloaded arithmetic operator +
  ///
  /// @param[in] left left operand
  /// @param[in] right right operand
  ///
  /// @return arithmetic result
  friend Node operator+(const Node left, const Node right) {
    return Node(left.row + left.col, right.row + right.col);
  }

private:
  /// Number wf cell's rww
  std::uint8_t row;
  /// Number of cell's column
  std::uint8_t col;
  /// Status this cell's for A-star algorithm
  ///
  /// Was the cell visited during the algorithm's run?
  bool visited = false;
  /// Type this node
  NodeType type = NodeType::Empty;
};
