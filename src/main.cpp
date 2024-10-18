#include "node.hpp"
#include "util.hpp"
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <vector>

/**
 * Start point for program
 *
 * @param[in] argc number of parameters transferred
 * @param[in] argv transferred parameters
 * @return status code (code 0 - successful finish, code 1 - error parsing
 * parameters, 2 - invalid character in map)
 */
int main(int argc, char *argv[]) {
  try {
    std::vector<std::vector<int>> grid = {};
    Node *start = new Node(0, 0);
    Node *goal = new Node(0, 0);

    boost::program_options::options_description desc("Allowed options");
    desc.add_options()("about", "message about this program")(
        "help,h", "show this help message");

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << "\n";
      return 0;
    }
    if (vm.count("about")) {
      std::cout << "Find your way!" << std::endl
                << std::endl
                << "This program will help you find the shortest path between "
                   "two points on a custom map."
                << std::endl
                << std::endl
                << "Create your own card:" << std::endl
                << "\tSpecify the obstacles that need to be bypassed."
                << std::endl
                << "\tSelect the start point and the finish point." << std::endl
                << std::endl
                << "The program will analyze the map and give you a list of "
                   "coordinates that you need to follow to get from start to "
                   "finish as quickly as possible."
                << std::endl;
      return 0;
    }

    std::string line;
    std::cout
        << "Enter your map (0 is wall, 1 is abstacle, empty string for finish):"
        << std::endl;
    while (std::getline(std::cin, line) && !line.empty()) {
      std::vector<int> row;
      for (char c : line) {
        if (c == '0') {
          row.push_back(0);
        } else if (c == '1') {
          row.push_back(1);
        } else {
          std::cerr << "Error: Invalid symbol in line. Allowed only 0 or 1";
          return 2;
        }
      }
      grid.push_back(row);
    }

    {
      std::cout << "Enter coordinate for start point ((0,0) is top left angle)."
                << std::endl;
      std::cout << "X: ";
      std::cin >> start->x;
      std::cout << "Y: ";
      std::cin >> start->y;

      std::cout
          << "Enter coordinate for finish point ((0,0) is top left angle)."
          << std::endl;
      std::cout << "X: ";
      std::cin >> goal->x;
      std::cout << "Y: ";
      std::cin >> goal->y;
    }

    for (const auto &row : grid) {
      for (int cell : row) {
        std::cout << (cell == 0 ? "□" : "■") << " ";
      }
      std::cout << std::endl;
    }

    std::vector<Node *> path = aStarSearch(grid, start, goal);

    // Выводим найденный путь
    if (!path.empty()) {
      std::cout << "Найденный путь:" << std::endl;
      for (const auto node : path) {
        grid[node->x][node->y] = 2;
      }
      for (const auto &row : grid) {
        for (int cell : row) {
          std::cout << (cell == 0 ? "□" : (cell == 1 ? "■" : "*")) << " ";
        }
        std::cout << std::endl;
      }
    } else {
      std::cout << "Путь не найден." << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Exception of unknown type!\n";
  }
  return 0;
}
