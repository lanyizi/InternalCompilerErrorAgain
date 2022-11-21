cmake_minimum_required(VERSION 3.20)
project(NativeDll)

# Show compiler version
message("COMPILER VERSION: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_custom_target(SHOW_COMPILER_VERSION
        COMMAND ${CMAKE_CXX_COMPILER} /Bv || (exit 0)
    )
endif()

# Dependencies
find_package(fmt CONFIG REQUIRED)

# Build targets
add_library(${PROJECT_NAME} SHARED)
add_library("${PROJECT_NAME}_Preprocessed" SHARED)
add_subdirectory(source)
# Common stuffs
add_library(COMMON INTERFACE)
# Macros
target_compile_definitions(COMMON INTERFACE
    "UNICODE=1"
    "_UNICODE=1"
    "WIN32_LEAN_AND_MEAN=1"
    "WINVER=_WIN32_WINNT_WIN7"
    "_WIN32_WINNT=_WIN32_WINNT_WIN7"
)
# C++20
target_compile_features(COMMON INTERFACE cxx_std_20)
# Dependencies
target_link_libraries(COMMON INTERFACE fmt::fmt)
# Apply common stuffs
target_link_libraries(${PROJECT_NAME} PRIVATE COMMON)
target_link_libraries("${PROJECT_NAME}_Preprocessed" PRIVATE COMMON)
# Static link
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties("${PROJECT_NAME}_Preprocessed" PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Copy compiler version to file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_CXX_COMPILER} /Bv > "${CMAKE_BINARY_DIR}/COMPILER_VERSION.txt" 2>&1 || (exit 0)
)