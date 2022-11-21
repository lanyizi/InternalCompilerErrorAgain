cmake_minimum_required(VERSION 3.20)
project(NativeDll)

# Dependencies
find_package(fmt CONFIG REQUIRED)

# Build targets
add_library(${PROJECT_NAME} SHARED)
add_subdirectory(source)
# Macros
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "UNICODE=1"
    "_UNICODE=1"
    "WIN32_LEAN_AND_MEAN=1"
    "WINVER=_WIN32_WINNT_WIN7"
    "_WIN32_WINNT=_WIN32_WINNT_WIN7"
)
if (PREPROCESS)
    target_compile_options(${PROJECT_NAME} PRIVATE "/P")
endif()
# C++20
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
# Dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
# Static link
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Copy compiler version to file
add_custom_target(SHOW_COMPILER_VERSION
    COMMAND ${CMAKE_CXX_COMPILER} /Bv > "${CMAKE_BINARY_DIR}/COMPILER_VERSION.txt" 2>&1 || (exit 0)
)
add_custom_target(SHOW_WINDOWS_VERSION
    COMMAND cmd /c ver > "${CMAKE_BINARY_DIR}/WINDOWS_VERSION.txt" 2>&1 || (exit 0)
)
add_dependencies(${PROJECT_NAME} SHOW_COMPILER_VERSION SHOW_WINDOWS_VERSION)