#pragma once

#include <cstdint>
class Node {
public:
  Node();
  ~Node();

private:
  /// Номер ряда клетки
  std::uint8_t row;
  std::uint8_t col;
  bool visited = false;
};
