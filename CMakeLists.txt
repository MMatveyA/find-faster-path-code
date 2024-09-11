cmake_minimum_required(VERSION 3.5)

project(FindFasterPath LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

option(BUILD_DOC "Build documentation" ON)

file(GLOB srcs src/*.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(
  Boost
  COMPONENTS program_options
  REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(main ${srcs})
target_link_libraries(main ${CURSES_LIBRARY} ${Boost_LIBRARIES})

if(BUILD_DOC)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/docs)
endif()

install(TARGETS main DESTINATION ${CMAKE_INSTALL_BINDIR})
