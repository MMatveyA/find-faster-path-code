#include <boost/program_options.hpp>
#include <iostream>
#include <ncurses.h>

namespace po = boost::program_options;

int main(int argc, char *argv[]) {
  try {
    int rows; /// Количество рядов на поле
    int cols; /// Количество колонок на поле

    po::options_description desc("Allowed options");
    desc.add_options()("about", "about this program")("help",
                                                      "show this help message")(
        "rows", po::value<int>(&rows)->default_value(10), "number of rows")(
        "cols", po::value<int>(&cols)->default_value(10), "number of cols");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
    }
    if (vm.count("about")) {
      std::cout << "This program finds the shortest path between two points, "
                   "avoiding all obstacles on the field."
                << std::endl;
      return 1;
    }
  } catch (std::exception &e) {
    std::cerr << "error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Exception of unknown type!\n";
  }

  return 0;
}
