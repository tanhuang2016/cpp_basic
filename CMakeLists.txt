cmake_minimum_required(VERSION 4.2)
project(cpp_basic)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_basic main.cpp
        note.cpp
        dataType/data_type.cpp
        dataType/ptr.cpp
        dataType/cast.cpp
        variable.cpp
        variable_scope.cpp
        saveType/save_type.cpp
        saveType/extern_main.cpp
        saveType/extern_support.cpp)


add_executable(extern_demo
        saveType/extern_main.cpp
        saveType/extern_support.cpp)


