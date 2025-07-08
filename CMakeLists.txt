cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(BridgeEngine LANGUAGES C CXX)

# 指定C++标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加包含目录
include_directories(include)

# 设置编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2 -g3")

# 收集所有 .c 文件作为源文件
file(GLOB_RECURSE SOURCES "engine/*.cpp")

# 添加可执行文件
add_executable(main ${SOURCES})

# 将SDL3作为子项目添加
add_subdirectory(third_party/SDL3)

# 包含SDL3的头文件目录
include_directories(third_party/SDL3/include)

# 链接SDL3库
target_link_libraries(main SDL3-shared)

add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3-shared>        # SDL3.dll 的完整路径
        $<TARGET_FILE_DIR:main>)          # main.exe 所在目录

# clang-format 和 clang-tidy 的集成
find_program(CLANG_FORMAT NAMES clang-format DOC "Path to clang-format executable")
if (CLANG_FORMAT)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT} -i ${SOURCES}
        COMMENT "Running clang-format on source files"
    )
endif()

find_program(CLANG_TIDY NAMES clang-tidy DOC "Path to clang-tidy executable")
if (CLANG_TIDY)
    add_custom_target(check
        COMMAND ${CLANG_TIDY} -p=${CMAKE_BINARY_DIR} -- ${SOURCES}
        COMMENT "Running clang-tidy on source files"
    )
endif()