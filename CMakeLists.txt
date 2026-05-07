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
        saveType/extern_support.cpp
        saveType/mutable.cpp
        saveType/thread_local.cpp
        function/call.cpp
        function/lambda.cpp
        array.cpp
        string.cpp
        ptr.cpp
        time.cpp
        out&in/cin.cpp
        out&in/cerr.cpp
        out&in/clog.cpp)


add_executable(extern_demo
        saveType/extern_main.cpp
        saveType/extern_support.cpp)


#点击构件，而不是执行
add_custom_target(clean_exe
        COMMAND ${CMAKE_COMMAND} -E echo "Cleaning all .exe files..."
        COMMAND powershell -Command "Get-ChildItem -Path ${CMAKE_SOURCE_DIR} -Filter *.exe -Recurse | Remove-Item -Force"
        COMMAND ${CMAKE_COMMAND} -E echo "Cleaned!"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Removing all .exe files in project"
        VERBATIM
)


