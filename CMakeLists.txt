cmake_minimum_required(VERSION 3.20)
project(sort_visualizer)

find_package(SDL2 REQUIRED)

add_executable(main src/main.cpp
        utils/utils.cpp
        init/init.h
        handlers/handle.h
        handlers/handle.cpp
        init/init.cpp
        sort/sort.h
        sort/sort.cpp
)

target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS}
        PRIVATE ${CMAKE_SOURCE_DIR}/utils
        PRIVATE ${CMAKE_SOURCE_DIR}/handlers
        PRIVATE ${CMAKE_SOURCE_DIR}/init
        PRIVATE ${CMAKE_SOURCE_DIR}/sort
)
target_link_libraries(main ${SDL2_LIBRARIES})