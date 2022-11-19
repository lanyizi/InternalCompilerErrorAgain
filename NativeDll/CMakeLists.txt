cmake_minimum_required(VERSION 3.20)
project(NativeDll)

# Show compiler version
message("COMPILER VERSION: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# Dependencies
find_package(fmt CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED)
add_subdirectory("source")
# Macros
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "UNICODE=1"
    "_UNICODE=1"
    "WIN32_LEAN_AND_MEAN=1"
    "WINVER=_WIN32_WINNT_WIN7"
    "_WIN32_WINNT=_WIN32_WINNT_WIN7"
)
# Static link
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# UTF-8
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<C_COMPILER_ID:MSVC>:/utf-8>")
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
# C++20
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
# Dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
