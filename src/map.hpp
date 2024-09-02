#pragma once

#include <vector>

/// Field type
enum MapType {
  Empty = 1,  ///< Empty cell. Default variant
  Start = 2,  ///< Route start cell
  Finish = 4, ///< Route finish cell
  Wall = 8    ///< Wall
};

/// Map view
class Map {
public:
  /// Constructor
  ///
  /// @param[in] cols Number of cols
  /// @param[out] rows Number of rows
  Map(int cols, int rows);
  Map(Map &&) = default;
  Map(const Map &) = default;
  Map &operator=(Map &&) = default;
  Map &operator=(const Map &) = default;
  ~Map();

private:
  /// Two-dimensional matrix representing the cells of a field
  std::vector<std::vector<MapType>> fields;
};
