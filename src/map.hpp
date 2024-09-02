#pragma once

#include <vector>

/// Тип клетки
enum MapType {
  Empty = 1, ///< Пустая клетка. Вариант по умолчанию
  Start = 2, ///< Клетка начала маршрута
  Stop = 4,  ///< Клетка конца маршрута
  Wall = 8   ///< Стена
};

/// Представление карты
class Map {
public:
  /// Конструктор
  ///
  /// @param[in] cols Число столбцов
  /// @param[out] rows Число рядов
  Map(int cols, int rows);
  Map(Map &&) = default;
  Map(const Map &) = default;
  Map &operator=(Map &&) = default;
  Map &operator=(const Map &) = default;
  ~Map();

private:
  /// Двумерная матрица, представляющая клетки поля
  std::vector<std::vector<MapType>> fields;
};
