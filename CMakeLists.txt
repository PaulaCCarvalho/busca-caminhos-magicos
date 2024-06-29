cmake_minimum_required(VERSION 3.22.1)
project(busca-caminhos-magicos)

set(CMAKE_C_STANDARD 99)
# Retrieve all source files
set(SOURCES
        "${CMAKE_SOURCE_DIR}/src/heap.c"
        "${CMAKE_SOURCE_DIR}/src/graph.c"
        "${CMAKE_SOURCE_DIR}/src/dijkstra.c"
        "${CMAKE_SOURCE_DIR}/src/main.c"
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
