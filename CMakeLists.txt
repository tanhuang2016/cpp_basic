cmake_minimum_required(VERSION 4.2)
project(cpp_basic)

set(CMAKE_CXX_STANDARD 11)

# 设置 vcpkg 工具链
set(CMAKE_TOOLCHAIN_FILE "D:/soft/vcpkg-2026.04.27/vcpkg-2026.04.27/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-mingw-static")

# 显式设置 CMAKE_PREFIX_PATH，让 CMake 能找到 vcpkg 安装的包
list(APPEND CMAKE_PREFIX_PATH "D:/soft/vcpkg-2026.04.27/vcpkg-2026.04.27/installed/x64-mingw-static")
# 设置 boost 头文件路径
set(Boost_INCLUDE_DIR "D:/soft/vcpkg-2026.04.27/vcpkg-2026.04.27/installed/x64-mingw-static/include")


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
        vector/array.cpp
        string.cpp
        ptr.cpp
        time.cpp
        out&in/cin.cpp
        out&in/cerr.cpp
        out&in/clog.cpp
        struct/struct1.cpp
        vector.cpp
        vector/CopyOnWriteVector.h
        vector/CopyOnWriteVectorTest.cpp
        class/Line.cpp
        class/friend.cpp
        class/this.cpp
        class/ptr.cpp
        overload/function_call.cpp
        extend/virtual.cpp
        fstream/fstream.cpp
        catch/exception.cpp
        template/template.cpp
        macro/paramr.cpp
        "macro/##.cpp"
        signal/signal.cpp
        thread/create_thread.cpp
        thread/condition_variable.cpp
)

# 查找 boost 包（vcpkg 独立包方式）
find_package(boost_system REQUIRED CONFIG)
find_package(boost_filesystem REQUIRED CONFIG)
find_package(boost_filesystem REQUIRED CONFIG)
# boost_stacktrace 分为多个组件，根据需要使用
find_package(boost_stacktrace_windbg REQUIRED CONFIG)




message(STATUS "Boost system and filesystem found!")

add_executable(extern_demo
        saveType/extern_main.cpp
        saveType/extern_support.cpp)
add_executable(exception
        catch/exception.cpp
        )

# 为 exception 目标添加编译选项，启用调试符号和 stacktrace 支持
target_compile_options(exception PRIVATE -g -gdwarf-4)
target_compile_definitions(exception PRIVATE BOOST_STACKTRACE_USE_WINDBG)
# 为 exception 目标添加 boost 头文件路径和链接库
target_include_directories(exception PRIVATE ${Boost_INCLUDE_DIR})
#target_link_libraries(exception PRIVATE boost_system boost_filesystem boost_stacktrace)
target_link_libraries(exception PRIVATE Boost::system Boost::filesystem Boost::stacktrace_windbg)



#点击构件，而不是执行
add_custom_target(clean_exe
        COMMAND ${CMAKE_COMMAND} -E echo "Cleaning all .exe files..."
        COMMAND powershell -Command "Get-ChildItem -Path ${CMAKE_SOURCE_DIR} -Filter *.exe -Recurse | Remove-Item -Force"
        COMMAND ${CMAKE_COMMAND} -E echo "Cleaned!"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Removing all .exe files in project"
        VERBATIM
)


