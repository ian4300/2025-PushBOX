cmake_minimum_required(VERSION 3.16)
project(2025-PUSHBOX)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

# 引入 FetchContent 模組
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# 引入 PTSD 庫
FetchContent_Declare(
        ptsd
        URL https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)
FetchContent_MakeAvailable(ptsd)

# 設定源文件和包含文件的目錄
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)

# 設定 example 目錄
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/example)
set(EXAMPLE_FILES
        ${EXAMPLE_DIR}/src/GiraffeText.cpp
        ${EXAMPLE_DIR}/include/GiraffeText.hpp
)

# 添加可執行文件
add_executable(${PROJECT_NAME}
        ${SRC_DIR}/main.cpp
        ${SRC_FILES}
        ${HEADER_FILES}
        src/AppEnd.cpp
        src/AppStart.cpp
        src/AppUpdate.cpp
        src/Box.cpp
        src/Impact.cpp
        src/Man.cpp
        src/Phasemanager.cpp
        src/Stage.cpp
        src/StepCounter.cpp
        src/Target.cpp
        ${EXAMPLE_FILES}
)

# 設定編譯選項
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# 設定資源目錄
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    message(FATAL_ERROR "relative RESOURCE_DIR is WIP, Please use `-DCMAKE_BUILD_TYPE=Debug` build for now.")
    # target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

# 設定包含目錄
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${EXAMPLE_DIR}/include)

# 連結所需的庫
target_link_libraries(${PROJECT_NAME}
        SDL2::SDL2main
        PTSD
)